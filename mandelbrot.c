/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 07:41:41 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/18 02:32:49 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	mandelbrot(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		n;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < max_iter)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > 4.0)
			return (n);
		zi = 2.0 * zr * zi + ci;
		zr = zr2 - zi2 + cr;
		n++;
	}
	return (n);
}

void	draw_pixel_mandelbrot(t_data *img, int x, int y, t_view *view)
{
	t_complex	c;
	double		n_iterations;
	double		t;

	c = map_to_complex(x, y, view->min, view->max);
	n_iterations = mandelbrot(c.r, c.i, view->max_iter);
	t = log(1 + n_iterations) * view->inv_log_max_iter_plus_one;
	t = pow(t, view->gamma);
	my_mlx_pixel_put(img, x, y, get_gradient_color(t, view));
}

void	draw_mandelbrot(t_data *img, t_view *view)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel_mandelbrot(img, x, y, view);
			x++;
		}
		y++;
	}
}
