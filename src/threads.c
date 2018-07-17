/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:11:17 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/15 20:12:02 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			check_kind_fractols(int x, int y, t_threads *threads)
{
	if (threads->copy->num == 1)
		show_julia(x, y, threads->copy);
	else if (threads->copy->num == 2)
		show_mandelbrot(x, y, threads->copy);
	else if (threads->copy->num == 3)
		show_tricorn(x, y, threads->copy);
	else if (threads->copy->num == 4)
		show_heart(x, y, threads->copy);
	else if (threads->copy->num == 5)
		show_buffalo(x, y, threads->copy);
	else if (threads->copy->num == 6)
		show_celtic_heart(x, y, threads->copy);
	else if (threads->copy->num == 7)
		show_buring_ship(x, y, threads->copy);
	else if (threads->copy->num == 8)
		show_perpendicular_celtic(x, y, threads->copy);
}

void			*work_while(void *thr)
{
	int			y;
	int			x;
	int			y_max;
	t_threads	*threads;

	threads = (t_threads *)thr;
	y = HEIGHT / 8 * threads->thread;
	y_max = HEIGHT / 8 * (threads->thread + 1);
	while (y < y_max)
	{
		x = 0;
		while (x < WIDTH)
		{
			check_kind_fractols(x, y, threads);
			x++;
		}
		y++;
	}
	return (0);
}

void			work_with_threads(t_fractol *fractol)
{
	t_threads	threads[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		threads[i].copy = fractol;
		threads[i].thread = i;
		pthread_create(&threads[i].threads, NULL, work_while, &threads[i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		pthread_join(threads[i].threads, NULL);
		i++;
	}
	mlx_put_image_to_window(MLX, WIN, IMG_P, 0, 0);
}

void			change_fractol(int key, t_fractol *fractol)
{
	if (key == 83)
		fractol->num = 1;
	else if (key == 84)
		fractol->num = 2;
	else if (key == 85)
		fractol->num = 3;
	else if (key == 86)
		fractol->num = 4;
	else if (key == 87)
		fractol->num = 5;
	else if (key == 88)
		fractol->num = 6;
	else if (key == 89)
		fractol->num = 7;
	else if (key == 91)
		fractol->num = 8;
}

void			come_back(t_fractol *fractol)
{
	MX = 0;
	MY = 0;
	COLOR = RED_CRIMSON;
	ZOOM = 0.5;
}
