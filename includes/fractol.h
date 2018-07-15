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

# define GREEN 0x008000
# define GREEN_LIGHT 0x00FF00

# define RED 0xFF0000
# define RED_CRIMSON 0xDC143C

# define BLUE 0x4169E0
# define BLUE_LIGHT 0x00BFFF

# define WHITE 0xFFFFFF

# define WIDTH 1600
# define HEIGHT 1200

typedef struct		s_coor
{
	float			x;
	float			y;
	float			z;
	int				color;
	struct s_coor	*next;
}					t_coor;

typedef	struct		s_fractol
{
	void			*mlx;
	void			*win;

}					t_fdf;


int					ft_atoi_base_16(const char *str);

#endif
