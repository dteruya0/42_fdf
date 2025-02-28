/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:44:08 by dteruya           #+#    #+#             */
/*   Updated: 2025/02/28 11:30:30 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	cleanup(t_fdf *fdf)
{
	if (fdf->mlx_ptr)
		free(fdf->mlx_ptr);
	if (fdf)
		free(fdf);
}
