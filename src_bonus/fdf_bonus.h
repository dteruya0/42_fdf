/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:19:11 by dteruya           #+#    #+#             */
/*   Updated: 2025/02/28 15:26:55 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <math.h>
# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

# define WINDOW_WIDTH	1000
# define WINDOW_HEIGHT	1000

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	float	x1;
	float	y1;
	int		z1;
	int		center_x;
	int		center_y;
	int		map_center_x;
	int		map_center_y;
	float	x_step;
	float	y_step;
	float	zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

int		close_window(t_fdf *fdf);
int		is_valid(const char *file_name, int *flag);
void	free_matrix(int **matrix, int height);
void	draw(t_fdf *fdf);
int		validate_file(const char *file_name);
void	read_file(const char *file_name, t_fdf *fdf);
void	free_split(char **split);
int		word_count(char **split);
int		init_program(t_fdf *fdf);
void	isometric(float *x, float *y, int z);
void	isometric2(t_fdf *fdf);
void	cleanup(t_fdf *fdf);
void	calculate_dynamic_zoom(t_fdf *fdf);

#endif