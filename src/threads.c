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
			if (threads->copy->num == 1)
				show_julia(x, y, threads->copy);
			else if (threads->copy->num == 2)
				show_mandelbrot(x, y, threads->copy);
			else if (threads->copy->num == 3)
				show_tricorn(x, y, threads->copy);
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
