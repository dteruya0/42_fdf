/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:17 by dteruya           #+#    #+#             */
/*   Updated: 2025/02/26 13:21:38 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_transformations(float *x, float *y, t_fdf *fdf)
{
	int	z;

	z = fdf->z_matrix[(int)(*y)][(int)(*x)];
	fdf->z1 = fdf->z_matrix[(int)(fdf->y1)][(int)(fdf->x1)];
	*x *= fdf->zoom;
	*y *= fdf->zoom;
	fdf->x1 *= fdf->zoom;
	fdf->y1 *= fdf->zoom;
	if (z > 0 || fdf->z1 > 0)
		fdf->color = 0xe80c0c;
	else
		fdf->color = 0xffffff;
	isometric(x, y, z);
	isometric2(fdf);
	*x += fdf->shift_x;
	*y += fdf->shift_y;
	fdf->x1 += fdf->shift_x;
	fdf->y1 += fdf->shift_y;
}

void	calculate_steps(float x, float y, t_fdf *fdf)
{
	float	max;

	fdf->x_step = fdf->x1 - x;
	fdf->y_step = fdf->y1 - y;
	if (fabsf(fdf->x_step) > fabsf(fdf->y_step))
		max = fabsf(fdf->x_step);
	else
		max = fabsf(fdf->y_step);
	fdf->x_step /= max;
	fdf->y_step /= max;
}

void	draw_line(float x, float y, t_fdf *fdf)
{
	while ((int)(x - fdf->x1) || (int)(y - fdf->y1))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->color);
		x += fdf->x_step;
		y += fdf->y_step;
	}
}

void	bresenham(float x, float y, t_fdf *fdf)
{
	apply_transformations(&x, &y, fdf);
	calculate_steps(x, y, fdf);
	draw_line(x, y, fdf);
}

void	draw(t_fdf *fdf)
{
	float	x;
	float	y;

	y = 0;
	while (fdf->height > y)
	{
		x = 0;
		while (fdf->width > x)
		{
			if (x < fdf->width - 1)
			{
				fdf->y1 = y;
				fdf->x1 = x + 1;
				bresenham(x, y, fdf);
			}
			if (y < fdf->height - 1)
			{
				fdf->x1 = x;
				fdf->y1 = y + 1;
				bresenham(x, y, fdf);
			}
			x++;
		}
		y++;
	}
}
