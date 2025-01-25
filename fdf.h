/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:49:24 by dteruya           #+#    #+#             */
/*   Updated: 2025/01/22 14:51:39 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include "libft/libft.h"

# define ANG_30	0.52359877

typedef struct s_dimensions
{
	int	rows;
	int	cols;
}	t_dimensions;

typedef struct s_point
{
	float	x_prime;
	float	y_prime;
	int		z;
}	t_point;

t_point	**ft_allocate_projected_matrix(int cols, int rows, int **matrix);
void	ft_fill_the_prime_matrix(t_point **matrix_prime, int **matrix, int rows, int cols);
float	ft_formula_y(int row, int col, int **matrix);
float	ft_formula_x(int row, int col);
void	ft_free_projected_matrix(t_point **matrix, int rows);

void print_projected_matrix(t_point **projected_matrix, int rows, int cols);


#endif