/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:07:05 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/15 20:07:52 by mponomar         ###   ########.fr       */
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

# define WIDTH 1200
# define HEIGHT 700

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

# define PR varaibles.pr
# define PI varaibles.pi
# define NRE varaibles.new_re
# define NIM varaibles.new_im
# define ORE varaibles.old_re
# define OIM varaibles.old_im

typedef	struct		s_fractol
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*image;
	char			num;
	double			zoom;
	double			move_x;
	double			move_y;
	int				max_iter;
	double			c_re;
	double			c_im;
	int				color;
}					t_fractol;

typedef struct		s_varaibles
{
	double			pr;
	double			pi;
	double			new_re;
	double			new_im;
	double			old_re;
	double			old_im;
}					t_varaibles;

typedef struct		s_threads
{
	t_fractol		*copy;
	int				thread;
	pthread_t		threads;
}					t_threads;

int					exit_button(int key);
void				print_error(char *str);
t_fractol			*init_fractol();
void				init_window(t_fractol *fractol);
void				show_julia(int x, int y, t_fractol *fractol);
int					hook(int key, t_fractol *fractol);
void				show_mandelbrot(int x, int y, t_fractol *fractol);
void				work_with_threads(t_fractol *fractol);
int					mouse_hook(int keycode, int x, int y, t_fractol *fractol);
int					move_julia(int x, int y, t_fractol *fractol);
void				show_tricorn(int x, int y, t_fractol *fractol);
void				show_heart(int x, int y, t_fractol *fractol);
void				show_buffalo(int x, int y, t_fractol *fractol);
void				show_celtic_heart(int x, int y, t_fractol *fractol);
void				show_buring_ship(int x, int y, t_fractol *fractol);
void				show_perpendicular_celtic(int x, int y, t_fractol *fractol);
void				change_fractol(int key, t_fractol *fractol);
void				come_back(t_fractol *fractol);

#endif
