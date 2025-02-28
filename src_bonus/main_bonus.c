/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:58:54 by dteruya           #+#    #+#             */
/*   Updated: 2025/02/28 11:35:57 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	exit_error(const char *msg, int status, t_fdf *fdf)
{
	ft_printf("%s", msg);
	cleanup(fdf);
	exit (status);
}

static int	deal_key(int key, t_fdf *fdf)
{
	if (key == 65362)
		fdf->shift_y -= 10;
	if (key == 65364)
		fdf->shift_y += 10;
	if (key == 65361)
		fdf->shift_x -= 10;
	if (key == 65363)
		fdf->shift_x += 10;
	if (key == 65451)
		fdf->zoom += 1;
	if (key == 65453)
		fdf->zoom -= 1;
	if (key == 0 || key == 65307 || key == 2)
	{
		if (fdf->win_ptr)
			mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		if (fdf->mlx_ptr)
			mlx_destroy_display(fdf->mlx_ptr);
		free_matrix(fdf->z_matrix, fdf->height);
		cleanup(fdf);
		exit(0);
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw(fdf);
	return (0);
}

int	init_program(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
			WINDOW_HEIGHT, WINDOW_WIDTH, "FDF");
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	draw(fdf);
	mlx_loop(fdf->mlx_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	free(fdf->mlx_ptr);
	cleanup(fdf);
	return (0);
}

static void	centralize_projection(t_fdf *fdf)
{
	float	map_center_x;
	float	map_center_y;

	fdf->center_x = WINDOW_WIDTH / 2;
	fdf->center_y = WINDOW_HEIGHT / 2;
	map_center_x = (fdf->width - 1) * fdf->zoom / 2.0;
	map_center_y = (fdf->height - 1) * fdf->zoom / 2.0;
	isometric(&map_center_x, &map_center_y, 0);
	fdf->shift_x = fdf->center_x - map_center_x;
	fdf->shift_y = fdf->center_y - map_center_y;
}

int	main(int argc, char **argv)
{
	const char	*file_name;
	t_fdf		*fdf;

	fdf = NULL;
	if (argc == 2)
	{
		file_name = argv[1];
		if (validate_file(file_name) == -1)
			exit(EXIT_FAILURE);
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		if (!fdf)
			return (1);
		read_file(file_name, fdf);
		calculate_dynamic_zoom(fdf);
		centralize_projection(fdf);
		init_program(fdf);
	}
	else
		exit_error("Error: Number of arguments is invalid", 1, fdf);
	return (0);
}
