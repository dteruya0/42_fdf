/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:24:49 by dteruya           #+#    #+#             */
/*   Updated: 2025/02/26 13:18:04 by dteruya          ###   ########.fr       */
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

static int	verify_lines(char *str, int fd, int expected_count)
{
	char	**split;
	int		amount_tmp;

	split = ft_split(str, ' ');
	if (!split)
	{
		free(str);
		close(fd);
		ft_printf("Error: Attempt to count columns failed.\n");
		return (-1);
	}
	amount_tmp = word_count(split);
	free_split(split);
	if (amount_tmp != expected_count)
	{
		free(str);
		close(fd);
		ft_printf("Error: The file structure is incorrect.\n");
		return (-1);
	}
	free (str);
	return (0);
}

static int	verify_remaining_lines(int fd, int count)
{
	char	*str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		if (verify_lines(str, fd, count) == -1)
			return (-1);
		str = get_next_line(fd);
	}
	return (0);
}

static int	verify_first_line(int fd, int *count)
{
	char	*str;
	char	**split;

	str = get_next_line(fd);
	if (!str)
	{
		close(fd);
		ft_printf("Error: Empty map.\n");
		return (-1);
	}
	split = ft_split(str, ' ');
	if (!split)
	{
		free(str);
		close(fd);
		ft_printf("Error: Attempt to count columns failed.\n");
		return (-1);
	}
	*count = word_count(split);
	free_split(split);
	free(str);
	return (0);
}

int	validate_file(const char *file_name)
{
	int	fd;
	int	count;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	if (verify_first_line(fd, &count) == -1)
		return (-1);
	if (verify_remaining_lines(fd, count) == -1)
		return (-1);
	close(fd);
	return (0);
}
