/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 07:45:39 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/18 00:04:51 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	julia(double zr, double zi, t_view *view)
{
	double	zr2;
	double	zi2;
	int		n;
	double	cr;
	double	ci;

	cr = view->c.r;
	ci = view->c.i;
	n = 0;
	while (n < view->max_iter)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > 4.0)
			return (n + 1 - log2(log(zr2 + zi2)));
		zi = 2 * zr * zi + ci;
		zr = zr2 - zi2 + cr;
		n++;
	}
	return (n);
}

void	draw_pixel_julia(t_data *img, int x, int y, t_view *view)
{
	t_complex	z;
	double		n_iterations;
	double		t;

	z = map_to_complex(x, y, view->min, view->max);
	n_iterations = julia(z.r, z.i, view);
	t = log(1 + n_iterations) / view->log_max_iter_plus_one;
	t = pow(t, view->gamma);
	my_mlx_pixel_put(img, x, y, get_gradient_color(t, view));
}

void	draw_julia(t_data *img, t_view *view)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel_julia(img, x, y, view);
			x++;
		}
		y++;
	}
}
