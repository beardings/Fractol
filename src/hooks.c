/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 21:33:43 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/06 22:39:44 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// static void	change_position(int key, t_fdf *fdf)
// {

// }

// static void	zoom_window(int key, t_fdf *fdf)
// {
// 	if (key == 69)
// 		fdf->size *= 0.9;
// 	else if (key == 78)
// 		fdf->size *= 1.1;
// }

// static void	change_z(int key, t_fdf *fdf)
// {

// }

// static void	change_color(int key, t_fdf *fdf)
// {
// 	int		color;
// 	t_coor	*tmp;

// 	color = 0;
// 	tmp = fdf->coor;
// 	if (key == 18)
// 		color = GREEN;
// 	else if (key == 19)
// 		color = GREEN_LIGHT;
// 	else if (key == 20)
// 		color = RED;
// 	else if (key == 21)
// 		color = RED_CRIMSON;
// 	else if (key == 22)
// 		color = BLUE;
// 	else if (key == 23)
// 		color = BLUE_LIGHT;
// 	else if (key == 26)
// 		color = WHITE;
// 	while (tmp)
// 	{
// 		tmp->color = color;
// 		tmp = tmp->next;
// 	}
// }

int			hook(int key, t_fractol *fractol)
{
	mlx_clear_window(MLX, WIN);
	if (key == 53)
	{
		mlx_destroy_window(MLX, WIN);
		exit(0);
	}

	if (fractol->num == 1)
		show_julia(fractol);
	else if (fractol->num == 2)
		show_mandelbrot(fractol);
	mlx_put_image_to_window(MLX, WIN, IMG_P, 0, 0);
	return (0);
}