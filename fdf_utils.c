/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:44:05 by dteruya           #+#    #+#             */
/*   Updated: 2025/01/22 15:41:00 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

void	ft_free_projected_matrix(t_point **matrix, int rows)
{
	int	index;

	index = 0;
	while(index < rows)
	{
		free(matrix[index]);
		index++;
	}
	free(matrix);
}

float	ft_formula_x(int row, int col)
{
	float	x_prime;
	
	x_prime = (col - row) * cos(ANG_30);
	return (x_prime);
}

float	ft_formula_y(int row, int col, int **matrix)
{
	float	y_prime;

	y_prime = 0;
	y_prime = ((col + row) * sin(ANG_30)) - matrix[row][col];
	return (y_prime);
}

void	ft_fill_the_prime_matrix(t_point **matrix_prime, int **matrix, int rows, int cols)
{
	int	x;
	int	y;

	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			matrix_prime[x][y].x_prime = ft_formula_x(y, x);
			matrix_prime[x][y].y_prime = ft_formula_y(y, x, matrix);
			matrix_prime[x][y].z = matrix[x][y];
			printf("matrix_prime[%d][%d]: x'=%.2f, y'=%.2f, z=%d\n",
            x, y,
            matrix_prime[x][y].x_prime,
            matrix_prime[x][y].y_prime,
            matrix_prime[x][y].z);
			y++;
		}
		x++;
	}
}

t_point	**ft_allocate_projected_matrix(int cols, int rows, int **matrix)
{
	t_point	**matrix_prime;
	int		index;

	index = 0;
	matrix_prime = malloc(rows * sizeof(t_point *));
	if (!matrix_prime)
		return (NULL);
	while (index < rows)
	{
		matrix_prime[index] = malloc(cols * sizeof(t_point));
		if (matrix_prime[index] == NULL)
		{
			ft_free_projected_matrix(matrix_prime, rows);
			return (NULL);
		}
		index++;
	}
	ft_fill_the_prime_matrix(matrix_prime, matrix, rows, cols);
	return (matrix_prime);
}
