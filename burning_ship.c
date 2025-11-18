/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 07:42:34 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/18 02:33:03 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	burning_ship(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		n;

	zr = 0.0;
	zi = 0.0;
	n = 0;
	while (n < max_iter)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > 4.0)
			return (n + 1 - log2(log(zr2 + zi2)));
		if (zr < 0)
			zr = -zr;
		if (zi < 0)
			zi = -zi;
		zi = 2 * zr * zi + ci;
		zr = zr2 - zi2 + cr;
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
	t = log(1 + n) * view->inv_log_max_iter_plus_one;
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
