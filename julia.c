/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 07:45:39 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/09 00:47:03 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	julia(double zr, double zi, t_view *view)
{
	double	tmp;
	double	mag;
	int		n;
	double	cr;
	double	ci;

	cr = view->c.r;
	ci = view->c.i;
	n = 0;
	while (n < view->max_iter)
	{
		mag = zr * zr + zi * zi;
		if (mag > 4.0)
			return (n + 1 - log2(log(mag)));
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
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
	t = log(1 + n_iterations) / log(1 + view->max_iter);
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
