/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:31:39 by dteruya           #+#    #+#             */
/*   Updated: 2025/01/21 19:03:42 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_matriz(int **matriz, const char *line, int row)
{
	int		col;
	char	**numbers;

	numbers = ft_split(line, ' ');
	col  = 0;
	while (numbers[col])
	{
		ft_printf("Filling row %d, col %d with value %d\n", row, col, ft_atoi(numbers[col]));
		matriz[row][col] = ft_atoi(numbers[col]);
		free(numbers[col]);
		col++;
	}
	free (numbers);
}

int	ft_fill_matriz_help(int **matrix, const char *file)
{
	int		fd;
	char	*line;
	int		row;

	row = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_fill_matriz(matrix, line, row);
		free (line);
		line = get_next_line(fd);
		row++;
	}
	close (fd);
	return (0);
}

int	count_rows(const char *file)
{
	int		fd;
	int		row;
	char	*line;

	row = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("%s", "Error opening file") ,-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		row++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (row);
}

int	count_col(char *line)
{
	int	col;

	col = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			col++;
			while (ft_isdigit(*line))
				line++;
		}
		else
			line++;
	}
	return (col);
}

void	ft_free(int **matriz, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(matriz[i]);
		i++;
	}
	free (matriz);
	return;
}

t_dimensions	get_dimensions(char *file)
{
	int				fd;
	char			*line;
	t_dimensions	dim = {0, 0};

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Erro opening file");
		return (dim);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (dim.rows == 0)
			dim.cols = count_col(line);
		dim.rows++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (dim);
}

int	**ft_allocate_matriz(const char *file, int row, int col)
{
	int	**matrix;
	int	index;

	index = 0;
	matrix = (int **)malloc(row * sizeof(int *));
	if (matrix == NULL)
		return (NULL);
	while (index < row)
	{
		matrix[index] = (int *)malloc(col * sizeof(int));
		if (matrix[index] == NULL)
		{
			ft_free(matrix, row);
			return (NULL);
		}
		index++;
	}
	if (ft_fill_matriz_help(matrix, file) < 0)
	{
		ft_free(matrix, row);
		return (NULL);
	}
	return (matrix);
}

int	main(int argc, char *argv[])
{
	int				**matrix;
	t_dimensions	dim;

	matrix = 0;
	if (argc != 2)
		return (ft_printf("Incorrect arguments\n"), -1);
	dim = get_dimensions(argv[1]);
	if (dim.rows == 0 || dim.cols == 0)
	{
		ft_printf("Error: invalid file or empty file\n");
		return (1);
	}
	matrix = ft_allocate_matriz(argv[1], dim.rows, dim.cols);
	ft_printf("%d, %d", dim.cols, dim.rows);
	ft_free (matrix, dim.rows);
	return (0);
}
