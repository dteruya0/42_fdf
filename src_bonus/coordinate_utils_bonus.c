/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:21:17 by dteruya           #+#    #+#             */
/*   Updated: 2025/02/28 15:26:24 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	calculate_dynamic_zoom(t_fdf *fdf)
{
	float	usable_width;
	float	usable_height;

	usable_width = (float)WINDOW_WIDTH - (2 * 100);
	usable_height = (float)WINDOW_HEIGHT - (2 * 100);
	fdf->zoom = fmin(usable_width / fdf->width, usable_height / fdf->height);
}

int	is_valid(const char *file_name, int *flag)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 5)
	{
		*flag = 1;
		return (0);
	}
	file_name += len - 4;
	if (ft_strncmp(file_name, ".fdf", 4) != 0)
	{
		*flag = 1;
		ft_printf("Error: The file extension is incorrect, please use .fdf\n");
	}
	return (0);
}

int	close_window(t_fdf *fdf)
{
	if (fdf->win_ptr)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	if (fdf->mlx_ptr)
		mlx_destroy_display(fdf->mlx_ptr);
	free_matrix(fdf->z_matrix, fdf->height);
	cleanup(fdf);
	exit(0);
	return (0);
}
