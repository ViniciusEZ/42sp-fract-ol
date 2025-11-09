/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:24:05 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/08 23:24:14 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_color	extract_rgb(int color)
{
	t_color	rgb;

	rgb.r = (color >> 16) & 0xFF;
	rgb.g = (color >> 8) & 0xFF;
	rgb.b = color & 0xFF;
	return (rgb);
}

double	clamp_t(double t)
{
	if (isnan(t))
		return (0);
	if (t < 0)
		return (0);
	if (t > 1)
		return (1);
	return (t);
}

int	interpolate_color(int c1, int c2, double t)
{
	t_color	rgb1;
	t_color	rgb2;
	int		r;
	int		g;
	int		b;

	rgb1 = extract_rgb(c1);
	rgb2 = extract_rgb(c2);
	r = (int)(rgb1.r + (rgb2.r - rgb1.r) * t);
	g = (int)(rgb1.g + (rgb2.g - rgb1.g) * t);
	b = (int)(rgb1.b + (rgb2.b - rgb1.b) * t);
	return ((r << 16) | (g << 8) | b);
}

int	get_start_color(int index, t_view *view)
{
	int	color;
	int	col1;
	int	col2;

	if (view->transitioning)
	{
		col1 = get_palette_color(view->palette_id, index);
		col2 = get_palette_color(view->target_palette_id, index);
		color = interpolate_color(col1, col2, view->transition_fraction);
	}
	else
	{
		color = get_palette_color(view->palette_id, index);
	}
	return (color);
}

int	get_gradient_color(double t, t_view *view)
{
	double	segment;
	int		index;
	double	local_t;
	int		start_col;
	int		end_col;

	t = clamp_t(t);
	segment = t * 5.0;
	index = (int)segment;
	if (index < 0)
		index = 0;
	if (index >= 5)
		index = 4;
	local_t = segment - index;
	start_col = get_start_color(index, view);
	end_col = get_start_color(index + 1, view);
	return (interpolate_color(start_col, end_col, local_t));
}
