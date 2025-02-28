/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:24:49 by dteruya           #+#    #+#             */
/*   Updated: 2025/02/28 11:50:00 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	word_count(char **split)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (split[i])
	{
		if (*split[i] == '\n')
			i++;
		else
		{
			i++;
			amount++;
		}
	}
	return (amount);
}

static int	verify_lines(char *str, int fd, int expected_count, int *flag)
{
	char	**split;
	int		amount_tmp;

	split = ft_split(str, ' ');
	if (!split)
	{
		free(str);
		close(fd);
		ft_printf("Error: Attempt to count columns failed.\n");
		*flag = 1;
	}
	amount_tmp = word_count(split);
	free_split(split);
	if (amount_tmp != expected_count)
	{
		free(str);
		close(fd);
		ft_printf("Error: The file structure is incorrect.\n");
		*flag = 1;
	}
	else
		free(str);
	return (0);
}

static int	verify_remaining_lines(int fd, int count, int *flag)
{
	char	*str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		verify_lines(str, fd, count, flag);
		str = get_next_line(fd);
	}
	return (0);
}

static int	verify_first_line(int fd, int *count, int *flag)
{
	char	*str;
	char	**split;

	str = get_next_line(fd);
	if (!str)
	{
		close(fd);
		ft_printf("Error: Empty map.\n");
		*flag = 1;
	}
	split = ft_split(str, ' ');
	if (!split)
	{
		free(str);
		close(fd);
		ft_printf("Error: Attempt to count columns failed.\n");
		*flag = 1;
	}
	else
	{
		*count = word_count(split);
		free_split(split);
		free(str);
	}
	return (0);
}

int	validate_file(const char *file_name)
{
	int	fd;
	int	count;
	int	flag;

	flag = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	verify_first_line(fd, &count, &flag);
	verify_remaining_lines(fd, count, &flag);
	is_valid(file_name, &flag);
	if (flag == 1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}
