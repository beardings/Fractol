/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:12:25 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/15 20:14:21 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractol		*init_fractol(void)
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

void			init_window(t_fractol *fractol)
{
	int			endian;
	int			bpp;
	int			size_line;

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
