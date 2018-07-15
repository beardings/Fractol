/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:08:14 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/08 15:46:33 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			exit_button(int key)
{
	key = 0;
	exit(0);
}

void		print_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_fractol *fractol;

	if (argc != 2)
		print_error("Hey, you need input smth that: 'julia' or 'mandelbrot'👌");
	else
	{
		fractol = init_fractol();
		if (!ft_strcmp(argv[1], "julia"))
			fractol->num = 1;
		else if (!ft_strcmp(argv[1], "mandelbrot"))
			fractol->num = 2;
		else
			print_error("Hey, you input invalid argument!😭");
		init_window(fractol);
	}
	return (0);
}
