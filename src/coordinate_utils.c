/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:57:18 by dteruya           #+#    #+#             */
/*   Updated: 2025/02/28 12:30:45 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_dynamic_zoom(t_fdf *fdf)
{
	float	usable_width;
	float	usable_height;

	usable_width = (float)WINDOW_WIDTH - (2 * 100);
	usable_height = (float)WINDOW_HEIGHT - (2 * 100);
	fdf->zoom = fmin(usable_width / fdf->width, usable_height / fdf->height);
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
