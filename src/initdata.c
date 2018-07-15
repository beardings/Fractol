/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 22:48:54 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/08 15:47:55 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractol	*init_fractol()
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	MLX = NULL;
	WIN = NULL;
	IMG = 0;
	IMG_P = NULL;
	ZOOM = 0.5;
 	MX = 0;
 	MY = 0;
 	MITER = 300;
 	CRE = -0.7;
 	CIM = 0.27015;
 	COLOR = RED_CRIMSON;
	return (fractol);
}

void	*work_while(void *thr)
{
	int			y;
	int			x;
	int			y_max;
	t_threads	*threads;

	threads = (t_threads *)thr;
	y = HEIGHT/8 * threads->thread;
	y_max = HEIGHT/8 * (threads->thread + 1);
	while (y < y_max)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (threads->copy->num == 1)
				show_julia(x, y, threads->copy);
			else if (threads->copy->num == 2)
				show_mandelbrot(x, y, threads->copy);
			x++;
		}
		y++;
	}
	return (0);
}

void work_with_threads(t_fractol *fractol)
{
	t_threads threads[8];
	int i;

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

void		init_window(t_fractol *fractol)
{
	int endian;
	int bpp;
	int size_line;

	endian = 0;
	bpp = 32;
	size_line = WIDTH;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, "Fractol");
	IMG_P = mlx_new_image(MLX, WIDTH, HEIGHT);
	IMG = (int *)mlx_get_data_addr(IMG_P, &bpp,
	&size_line, &endian);
	work_with_threads(fractol);
	mlx_put_image_to_window(MLX, WIN, IMG_P, 0, 0);
	mlx_hook(WIN, 2, 0, hook, fractol);
	mlx_hook(WIN, 6, 0, move_julia, fractol);
	mlx_mouse_hook(WIN, mouse_hook, fractol);
	mlx_hook(WIN, 17, 1L << 17, exit_button, 0);
	mlx_loop(MLX);
}
