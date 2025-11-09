/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 07:39:35 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/08 23:09:10 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_complex	map_to_complex(double x, double y, t_complex min, t_complex max)
{
	t_complex	c;

	c.r = min.r + (x / (double)WIDTH) * (max.r - min.r);
	c.i = max.i - (y / (double)HEIGHT) * (max.i - min.i);
	return (c);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
