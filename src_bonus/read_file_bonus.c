/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:18:41 by dteruya           #+#    #+#             */
/*   Updated: 2025/02/26 14:10:25 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	get_height(const char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (height);
}

static int	get_width(const char *file_name)
{
	int		fd;
	int		width;
	char	**split;
	char	*line;

	width = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	width = word_count(split);
	free_split(split);
	free(line);
	close(fd);
	return (width);
}

static void	fill_matrix(int *z_value, char *line, int width)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line, ' ');
	if (split == NULL)
		return ;
	while (split[i] && i < width)
	{
		z_value[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	ft_malloc(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->z_matrix = (int **)malloc(sizeof(int *) * (fdf->height));
	if (fdf->z_matrix == NULL)
	{
		perror("Memory allocation failed for z_matrix");
		exit(EXIT_FAILURE);
	}
	while (i < fdf->height)
	{
		fdf->z_matrix[i] = (int *)malloc(sizeof(int) * (fdf->width));
		if (fdf->z_matrix[i] == NULL)
		{
			perror("Memory allocation failed for z_matrix");
			while (i >= 0)
			{
				free(fdf->z_matrix[i]);
				i--;
			}
			free(fdf->z_matrix);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	read_file(const char *file_name, t_fdf *fdf)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fdf->height = get_height(file_name);
	fdf->width = get_width(file_name);
	ft_malloc(fdf);
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL && i <= fdf->height)
	{
		fill_matrix(fdf->z_matrix[i], line, fdf->width);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}
