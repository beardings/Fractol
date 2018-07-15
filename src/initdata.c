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
	ZOOM = 1;
 	MX = 0;
 	MY = 0;
 	MITER = 300;
 	CRE = -0.7;
 	CIM = 0.27015;
	return (fractol);
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
	if (fractol->num == 1)
		show_julia(fractol);
	else if (fractol->num == 2)
		show_mandelbrot(fractol);
	mlx_put_image_to_window(MLX, WIN, IMG_P, 0, 0);
	mlx_hook(WIN, 2, 0, hook, fractol);
	mlx_hook(WIN, 17, 1L << 17, exit_button, 0);
	mlx_loop(MLX);
}
