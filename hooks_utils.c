/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:07:54 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/18 02:29:54 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	handle_movement(int keycode, t_vars *vars)
{
	double	shift_r;
	double	shift_i;

	shift_r = (vars->view.max.r - vars->view.min.r) * 0.2;
	shift_i = (vars->view.max.i - vars->view.min.i) * 0.2;
	if (keycode == 97)
	{
		vars->view.min.r -= shift_r;
		vars->view.max.r -= shift_r;
	}
	else if (keycode == 100)
	{
		vars->view.min.r += shift_r;
		vars->view.max.r += shift_r;
	}
	else if (keycode == 115)
	{
		vars->view.min.i -= shift_i;
		vars->view.max.i -= shift_i;
	}
	else if (keycode == 119)
	{
		vars->view.min.i += shift_i;
		vars->view.max.i += shift_i;
	}
}

void	handle_palette_switch(int keycode, t_vars *vars)
{
	struct timeval	tv;

	if (vars->view.transitioning)
		return ;
	if (keycode == 65361)
	{
		vars->view.target_palette_id = (vars->view.palette_id - 1
				+ NUM_PALETTES) % NUM_PALETTES;
	}
	else if (keycode == 65363)
	{
		vars->view.target_palette_id = (vars->view.palette_id + 1)
			% NUM_PALETTES;
	}
	gettimeofday(&tv, NULL);
	vars->view.transition_start = tv.tv_sec + (double)tv.tv_usec * 0.000001;
	vars->view.transitioning = 1;
	vars->view.transition_fraction = 0.0;
}
