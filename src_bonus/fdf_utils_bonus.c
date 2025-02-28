/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:20:34 by dteruya           #+#    #+#             */
/*   Updated: 2025/02/28 11:35:28 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_matrix(int **matrix, int height)
{
	int	i;

	if (matrix == NULL)
		return ;
	i = 0;
	while (matrix[i] && i < height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	isometric2(t_fdf *fdf)
{
	fdf->x1 = (fdf->x1 - fdf->y1) * cos(0.8);
	fdf->y1 = (fdf->x1 + fdf->y1) * sin(0.8) - fdf->z1;
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	cleanup(t_fdf *fdf)
{
	if (fdf->mlx_ptr)
		free(fdf->mlx_ptr);
	if (fdf)
		free(fdf);
}
