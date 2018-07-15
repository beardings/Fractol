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

int			move_julia(int x, int y, t_fractol *fractol)
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

void		show_julia(int x, int y, t_fractol *fractol)
{
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
	int		i;

	newRe = 1.5 * (x - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + MX;
	newIm = (y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + MY;
	i = 0;
	while (i < MITER)
	{
		oldRe = newRe;
		oldIm = newIm;
		newRe = oldRe * oldRe - oldIm * oldIm + CRE;
		newIm = 2 * oldRe * oldIm + CIM;
		if((newRe * newRe + newIm * newIm) > 4)
			break ;
		i++;
	}
	if (i == MITER)
		IMG[x + (y * WIDTH)] = 0;
	else
		IMG[x + (y * WIDTH)] = COLOR * i;
}

void		show_mandelbrot(int x, int y, t_fractol *fractol)
{
	double	pr;
	double	pi;
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
	int		i;

	pr = 1.5 * (x - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + MX;
	pi = (y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + MY;
	newRe = 0;
	newIm = 0;
	i = 0;
	while (i < MITER)
	{
		oldRe = newRe;
		oldIm = newIm;
		newRe = oldRe * oldRe - oldIm * oldIm + pr;
		newIm = 2 * oldRe * oldIm + pi;
		if ((newRe * newRe + newIm * newIm) > 4)
			break ;
		i++;
	}
	if (i == MITER)
		IMG[x + (y * WIDTH)] = 0;
	else
		IMG[x + (y * WIDTH)] = COLOR * i;
}

void		show_tricorn(int x, int y, t_fractol *fractol)
{
	double	pr;
	double	pi;
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
	int		i;

	pr = 1.5 * (x - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + MX;
	pi = (y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + MY;
	newRe = 0;
	newIm = 0;
	i = 0;
	while (i < MITER)
	{
		oldRe = newRe;
		oldIm = newIm;
		newIm = -2 * oldRe * oldIm + pi;
		newRe = oldRe * oldRe - oldIm * oldIm + pr;
		if ((newRe * newRe + newIm * newIm) > 4)
			break ;
		i++;
	}
	if (i == MITER)
		IMG[x + (y * WIDTH)] = 0;
	else
		IMG[x + (y * WIDTH)] = COLOR * i;
}

