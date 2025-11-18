/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 07:39:35 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/14 09:04:07 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_complex	map_to_complex(double x, double y, t_complex min, t_complex max)
{
	t_complex	c;

	c.r = min.r + x * ((max.r - min.r) / WIDTH);
	c.i = max.i - y * ((max.i - min.i) / HEIGHT);
	return (c);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	*(unsigned int *)(data->addr + y * data->line_length + x * 4) = color;
}
