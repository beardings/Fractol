/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:14:44 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/15 20:17:41 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		change_position(int key, t_fractol *fractol)
{
	double		move;

	move = 0.1;
	if (ZOOM > 2 && ZOOM <= 10)
		move = 0.01;
	else if (ZOOM > 10 && ZOOM <= 100)
		move = 0.001;
	else if (ZOOM > 100 && ZOOM <= 1000)
		move = 0.0001;
	else if (ZOOM > 1000 && ZOOM <= 10000)
		move = 0.00001;
	else if (ZOOM > 10000 && ZOOM <= 100000)
		move = 0.000001;
	else if (ZOOM > 100000)
		move = 0.0000001;
	if (key == 123)
		MX -= move;
	else if (key == 124)
		MX += move;
	else if (key == 125)
		MY += move;
	else if (key == 126)
		MY -= move;
}

int				mouse_hook(int keycode, int x, int y, t_fractol *fractol)
{
	x = 0;
	y = 0;
	if (keycode == 4 || keycode == 5)
	{
		mlx_clear_window(MLX, WIN);
		if (keycode == 4)
		{
			ZOOM *= 1.1;
			MITER += 10;
		}
		else
		{
			ZOOM *= 0.9;
			if (MITER > 100)
				MITER -= 10;
		}
		work_with_threads(fractol);
	}
	return (0);
}

static void		change_color_dynamic(int key, t_fractol *fractol)
{
	if (key == 69)
		COLOR -= 1000;
	else if (key == 78)
		COLOR += 1000;
}

static void		change_color(int key, t_fractol *fractol)
{
	int			color;

	color = 0;
	if (key == 18)
		color = GREEN;
	else if (key == 19)
		color = GREEN_LIGHT;
	else if (key == 20)
		color = RED;
	else if (key == 21)
		color = RED_CRIMSON;
	else if (key == 22)
		color = BLUE;
	else if (key == 23)
		color = BLUE_LIGHT;
	else if (key == 26)
		color = WHITE;
	COLOR = color;
}

int				hook(int key, t_fractol *fractol)
{
	mlx_clear_window(MLX, WIN);
	if (key == 53)
	{
		mlx_destroy_window(MLX, WIN);
		exit(0);
	}
	else if (key == 18 || key == 19 || key == 20 ||
			key == 21 || key == 22 || key == 23 || key == 26)
		change_color(key, fractol);
	else if (key == 69 || key == 78)
		change_color_dynamic(key, fractol);
	else if (key == 123 || key == 124 ||
			key == 125 || key == 126)
		change_position(key, fractol);
	else if (key == 83 || key == 84 || key == 85 || key == 86 ||
		key == 87 || key == 88 || key == 89 || key == 91)
		change_fractol(key, fractol);
	work_with_threads(fractol);
	mlx_put_image_to_window(MLX, WIN, IMG_P, 0, 0);
	return (0);
}
