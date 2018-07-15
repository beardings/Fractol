/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:18:54 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/15 20:19:02 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				move_julia(int x, int y, t_fractol *fractol)
{
	if (fractol->num == 1)
	{
		mlx_clear_window(MLX, WIN);
		if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		{
			CRE = -0.7 * x / 1000;
			CIM = 0.27015 * y / 1000;
		}
		work_with_threads(fractol);
	}
	return (0);
}

void			show_julia(int x, int y, t_fractol *fractol)
{
	int			i;
	t_varaibles varaibles;

	NRE = 1.5 * (x - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + MX;
	NIM = (y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + MY;
	i = 0;
	while (i < MITER)
	{
		ORE = NRE;
		OIM = NIM;
		NRE = ORE * ORE - OIM * OIM + CRE;
		NIM = 2 * ORE * OIM + CIM;
		if ((NRE * NRE + NIM * NIM) > 4)
			break ;
		i++;
	}
	if (i == MITER)
		IMG[x + (y * WIDTH)] = 0;
	else
		IMG[x + (y * WIDTH)] = COLOR * i;
}

void			show_mandelbrot(int x, int y, t_fractol *fractol)
{
	int			i;
	t_varaibles varaibles;

	PR = 1.5 * (x - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + MX;
	PI = (y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + MY;
	NRE = 0;
	NIM = 0;
	i = 0;
	while (i < MITER)
	{
		ORE = NRE;
		OIM = NIM;
		NRE = ORE * ORE - OIM * OIM + PR;
		NIM = 2 * ORE * OIM + PI;
		if ((NRE * NRE + NIM * NIM) > 4)
			break ;
		i++;
	}
	if (i == MITER)
		IMG[x + (y * WIDTH)] = 0;
	else
		IMG[x + (y * WIDTH)] = COLOR * i;
}

void			show_tricorn(int x, int y, t_fractol *fractol)
{
	int			i;
	t_varaibles varaibles;

	PR = 1.5 * (x - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + MX;
	PI = (y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + MY;
	NRE = 0;
	NIM = 0;
	i = 0;
	while (i < MITER)
	{
		ORE = NRE;
		OIM = NIM;
		NIM = -2 * ORE * OIM + PI;
		NRE = ORE * ORE - OIM * OIM + PR;
		if ((NRE * NRE + NIM * NIM) > 4)
			break ;
		i++;
	}
	if (i == MITER)
		IMG[x + (y * WIDTH)] = 0;
	else
		IMG[x + (y * WIDTH)] = COLOR * i;
}
