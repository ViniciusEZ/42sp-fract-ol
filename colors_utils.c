/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:24:05 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/09 01:25:28 by vfirmino         ###   ########.fr       */
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
	if (t != t || t < 0.0)
		return (0.0);
	if (t > 1.0)
		return (1.0);
	return (t);
}

int	interpolate_color(int c1, int c2, double t)
{
	t_color	r1;
	t_color	r2;

	t = clamp_t(t);
	r1 = extract_rgb(c1);
	r2 = extract_rgb(c2);
	return (((int)(r1.r + (r2.r - r1.r) * t) << 16) | ((int)(r1.g + (r2.g
					- r1.g) * t) << 8) | (int)(r1.b + (r2.b - r1.b) * t));
}

int	get_start_color(int index, t_view *v)
{
	int	c1;
	int	c2;

	if (!v->transitioning)
		return (get_palette_color(v->palette_id, index));
	c1 = get_palette_color(v->palette_id, index);
	c2 = get_palette_color(v->target_palette_id, index);
	return (interpolate_color(c1, c2, v->transition_fraction));
}

int	get_gradient_color(double t, t_view *v)
{
	double	seg;
	int		i;
	double	lt;

	t = clamp_t(t);
	seg = t * 5.0;
	i = (int)seg;
	if (i < 0)
		i = 0;
	if (i >= 5)
		i = 4;
	lt = seg - i;
	return (interpolate_color(get_start_color(i, v), get_start_color(i + 1, v),
			lt));
}
