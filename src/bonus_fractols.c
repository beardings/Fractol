/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fractols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 21:20:32 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/16 21:20:37 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			show_heart(int x, int y, t_fractol *fractol)
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
		NIM = fabs(ORE) * OIM * 2 + PI;
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

void			show_buffalo(int x, int y, t_fractol *fractol)
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
		NIM = -2 * fabs(ORE * OIM) + PI;
		NRE = fabs(ORE * ORE - OIM * OIM) + PR;
		if ((NRE * NRE + NIM * NIM) > 4)
			break ;
		i++;
	}
	if (i == MITER)
		IMG[x + (y * WIDTH)] = 0;
	else
		IMG[x + (y * WIDTH)] = COLOR * i;
}

void			show_celtic_heart(int x, int y, t_fractol *fractol)
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
		NIM = 2 * fabs(ORE) * OIM + PI;
		NRE = fabs(ORE * ORE - OIM * OIM) + PR;
		if ((NRE * NRE + NIM * NIM) > 4)
			break ;
		i++;
	}
	if (i == MITER)
		IMG[x + (y * WIDTH)] = 0;
	else
		IMG[x + (y * WIDTH)] = COLOR * i;
}

void			show_buring_ship(int x, int y, t_fractol *fractol)
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
		NIM = -2 * fabs(ORE * OIM) + PI;
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

void			show_perpendicular_celtic(int x, int y, t_fractol *fractol)
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
		NIM = -2 * fabs(ORE) * OIM + PI;
		NRE = fabs(ORE * ORE - OIM * OIM) + PR;
		if ((NRE * NRE + NIM * NIM) > 4)
			break ;
		i++;
	}
	if (i == MITER)
		IMG[x + (y * WIDTH)] = 0;
	else
		IMG[x + (y * WIDTH)] = COLOR * i;
}
