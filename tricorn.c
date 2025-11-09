/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 07:51:42 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/08 23:09:50 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	tricorn(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	double	magnitude;
	int		n;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < max_iter)
	{
		magnitude = zr * zr + zi * zi;
		if (magnitude > 4.0)
			return (n + 1 - log(log(magnitude)) / log(2.0));
		tmp = zr * zr - zi * zi + cr;
		zi = -2.0 * zr * zi + ci;
		zr = tmp;
		n++;
	}
	return (n);
}

void	draw_pixel_tricorn(t_data *img, int x, int y, t_view *view)
{
	t_complex	c;
	double		n_iterations;
	double		t;

	c = map_to_complex(x, y, view->min, view->max);
	n_iterations = tricorn(c.r, c.i, view->max_iter);
	t = log(1 + n_iterations) / log(1 + view->max_iter);
	t = pow(t, view->gamma);
	my_mlx_pixel_put(img, x, y, get_gradient_color(t, view));
}

void	draw_tricorn(t_data *img, t_view *view)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel_tricorn(img, x, y, view);
			x++;
		}
		y++;
	}
}
