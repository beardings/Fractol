/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:06:35 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/04 16:06:41 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_null(char *tmp, t_arg *res, int len)
{
	if (tmp == NULL)
	{
		write(1, "(null)", len);
		res->len += len;
		return (1);
	}
	return (0);
}
