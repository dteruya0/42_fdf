/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:31:39 by dteruya           #+#    #+#             */
/*   Updated: 2025/01/09 19:41:58 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void	draw_line(void *mlx, void *win)
{
	t_point	point1;
	t_point	point2;
	float	dx;
	float	dy;
	float	step;
	int		i;
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 8000, 6000, "Minilibx Test");
	point1.x = 100;
	point1.y = 100;
	point2.x = 100;
	point2.y = 200;
	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx /= step;
	dy /= step;
	i = 0;
	while (i <= step)
	{
		mlx_pixel_put(mlx, win, point1.x, point1.y, 0x00FF00);
		point1.x += dx;
		point1.y += dy;
		i++;
	}
	mlx_loop(mlx);
}*/
/*
void	ft_draw_line(void *mlx, void *win)
{
	
}

void	positions()
{
	
}
*/
/*
int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "MiniLibX Test");
	mlx_pixel_put(mlx, win, 400, 300, 0xFF0000);
	mlx_loop(mlx);
	return (0);
}*/
/*
int y = 0; // Linha na matriz
while (linha = próxima_linha_do_arquivo()) {
    int x = 0; // Coluna na matriz
    while (valor = próximo_valor_da_linha(linha)) {
        printf("Ponto: x = %d, y = %d, z = %d\n", x, y, valor);
        x++; // Avança para a próxima coluna
    }
    y++; // Avança para a próxima linha
}
*/

int	**ft_alocate_matriz(int **matriz, char *line, int row, int i, int j)
{
	while (i < row)
	{
		if (ft_isdigit(*line))
		{
			while (ft_isdigit(*line))
			{
				matriz[i][j] = ft_atoi(line);
				line++;
			}
			j++;
		}
		else if (!(ft_isdigit(*line)))
			line++;
		else
			i++;
	}
	return (matriz);
}

void	ft_free(int **matriz, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(matriz[i]);
		i++;
	}
	free (matriz);
	return;
}

int	**read_file(char *file, int **matriz, int *row, int *col)
{
	int		fd;
	char	*line;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Erro opening file", 1));
	line = get_next_line(fd);
		while (line != NULL)
	{
		matriz = ft_alocate_matriz(matriz, line, row, i, j);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (matriz);
}

int	**ft_create_matriz(const char *file, int row, int col, int **matriz)
{
	int	index;
	
	index = 0;
	matriz = (int **)malloc(row * sizeof(int *));
	if (matriz == NULL)
		return (NULL);
	while (index < row)
	{
		matriz[index] = (int *)malloc(col * sizeof(int));
		if (matriz[index] == NULL)
		{
			ft_free(matriz, row);
			return (NULL);
		}
		index++;
	}
	matriz = read_file(file, matriz, row);
	return (matriz);
}

int	count_col(char *line)
{
	int	x;

	x = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			x++;
			while (ft_isdigit(*line))
				line++;
		}
		else
			line++;
	}
	return (x);
}

int	main(int argc, char *argv[])
{
	int	**matrix;
	int	row;
	int	col;

	row = 0;
	if (argc != 2)
		return (ft_printf("Argumentos incorretos"), 1);
	**matrix = read_file(argv, matrix, &row, *col);
	while (line != NULL)
	{
		col = count_col(line);
		row++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	matriz = ft_create_matriz(argv[1], row, col, matriz);
	ft_printf(("%d, %d"), col, row);
	ft_printf("%d", **matriz);
	return (0);
}
