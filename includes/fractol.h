/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:08:03 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/08 17:06:35 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/header/libft.h"
# include "../libft/header/ft_printf.h"
# include "../libft/header/get_next_line.h"
# include <math.h>
# include <mlx.h>
# include <pthread.h>

# define GREEN 0x008000
# define GREEN_LIGHT 0x00FF00

# define RED 0xFF0000
# define RED_CRIMSON 0xDC143C

# define BLUE 0x4169E0
# define BLUE_LIGHT 0x00BFFF

# define WHITE 0xFFFFFF

# define WIDTH 1600
# define HEIGHT 1200


# define MLX fractol->mlx
# define WIN fractol->win
# define IMG_P fractol->img
# define IMG fractol->image
# define ZOOM fractol->zoom
# define MX fractol->move_x
# define MY fractol->move_y
# define MITER fractol->max_iter
# define CRE fractol->c_re
# define CIM fractol->c_im
# define COLOR fractol->color

typedef	struct		s_fractol
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*image;
	char			num;
	double zoom;
	double move_x;
	double move_y;
	int max_iter;
	double c_re;
	double c_im;
	int color;

}					t_fractol;


int			exit_button(int key);
void		print_error(char *str);
t_fractol 	*init_fractol();
void		init_window(t_fractol *fractol);
void 		show_julia(t_fractol *fractol);
int			hook(int key, t_fractol *fractol);
void 		show_mandelbrot(t_fractol *fractol);

#endif
