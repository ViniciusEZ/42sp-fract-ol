/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 07:42:34 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/08 23:03:15 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	burning_ship(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	double	mag;
	int		n;

	zr = 0.0;
	zi = 0.0;
	n = 0;
	while (n < max_iter)
	{
		mag = zr * zr + zi * zi;
		if (mag > 4.0)
			return (n + 1 - log(log(mag)) / log(2.0));
		tmp = fabs(zr);
		mag = fabs(zi);
		zr = tmp * tmp - mag * mag + cr;
		zi = 2 * tmp * mag + ci;
		n++;
	}
	return (n);
}

void	draw_pixel_burning_ship(t_data *img, int x, int y, t_view *view)
{
	t_complex	c;
	double		n;
	double		t;

	c = map_to_complex(x, y, view->min, view->max);
	n = burning_ship(c.r, c.i, view->max_iter);
	t = log(1 + n) / log(1 + view->max_iter);
	t = pow(t, view->gamma);
	my_mlx_pixel_put(img, x, y, get_gradient_color(t, view));
}

void	draw_burning_ship(t_data *img, t_view *view)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel_burning_ship(img, x, y, view);
			x++;
		}
		y++;
	}
}
