/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coodinate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:57:18 by dteruya           #+#    #+#             */
/*   Updated: 2025/02/26 12:34:10 by dteruya          ###   ########.fr       */
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
