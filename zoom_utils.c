/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:10:31 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/09 01:08:05 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	handle_zoom(t_vars *vars, double factor, double fx, double fy)
{
	t_complex	c;
	double		old_width;
	double		old_height;
	double		new_width;
	double		new_height;

	c = map_to_complex(fx * WIDTH, fy * HEIGHT, vars->view.min, vars->view.max);
	old_width = vars->view.max.r - vars->view.min.r;
	old_height = vars->view.max.i - vars->view.min.i;
	new_width = old_width * factor;
	new_height = old_height * factor;
	vars->view.min.r = c.r - fx * new_width;
	vars->view.max.r = vars->view.min.r + new_width;
	vars->view.max.i = c.i + fy * new_height;
	vars->view.min.i = vars->view.max.i - new_height;
	update_max_iter(vars);
}

void	update_max_iter(t_vars *vars)
{
	double	current_width;
	double	zoom_factor;
	int		new_max_iter;

	current_width = vars->view.max.r - vars->view.min.r;
	zoom_factor = vars->initial_width / current_width;
	new_max_iter = (int)(vars->base_max_iter + 50 * log2(zoom_factor + 1e-10));
	if (new_max_iter < 20)
		new_max_iter = 20;
	if (new_max_iter > 1000)
		new_max_iter = 1000;
	vars->view.max_iter = new_max_iter;
}
