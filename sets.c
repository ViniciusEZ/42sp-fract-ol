/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:09:26 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/08 23:09:39 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	set_view_mandelbrot(t_vars *vars)
{
	vars->view.min.r = -2.0;
	vars->view.min.i = -1.5;
	vars->view.max.r = 1.0;
	vars->view.max.i = 1.5;
	vars->view.max_iter = 80;
	vars->view.gamma = 0.7;
	vars->view.palette_id = 0;
	vars->view.target_palette_id = 0;
	vars->view.transition_start = 0.0;
	vars->view.transition_duration = 1.0;
	vars->view.transition_fraction = 0.0;
	vars->view.transitioning = 0;
	vars->base_max_iter = 80;
	vars->fractal_type = MANDELBROT;
	vars->initial_width = vars->view.max.r - vars->view.min.r;
}

void	set_view_tricorn(t_vars *vars)
{
	vars->view.min.r = -2.0;
	vars->view.min.i = -1.5;
	vars->view.max.r = 1.0;
	vars->view.max.i = 1.5;
	vars->view.max_iter = 80;
	vars->view.gamma = 0.7;
	vars->view.palette_id = 0;
	vars->view.target_palette_id = 0;
	vars->view.transition_start = 0.0;
	vars->view.transition_duration = 1.0;
	vars->view.transition_fraction = 0.0;
	vars->view.transitioning = 0;
	vars->base_max_iter = 80;
	vars->fractal_type = TRICORN;
	vars->initial_width = vars->view.max.r - vars->view.min.r;
}

void	set_view_burning_ship(t_vars *vars)
{
	vars->view.min.r = -1.8;
	vars->view.min.i = 0.2;
	vars->view.max.r = -1.6;
	vars->view.max.i = -0.2;
	vars->view.max_iter = 80;
	vars->view.gamma = 0.5;
	vars->view.palette_id = 0;
	vars->view.target_palette_id = 0;
	vars->view.transition_start = 0.0;
	vars->view.transition_duration = 1.0;
	vars->view.transition_fraction = 0.0;
	vars->view.transitioning = 0;
	vars->base_max_iter = 80;
	vars->fractal_type = BURNING_SHIP;
	vars->initial_width = vars->view.max.r - vars->view.min.r;
}

void	set_view_julia(t_vars *vars, char **argv)
{
	vars->view.min.r = -1.5;
	vars->view.min.i = -1.5;
	vars->view.max.r = 1.5;
	vars->view.max.i = 1.5;
	vars->view.max_iter = 300;
	vars->view.gamma = 0.55;
	vars->view.palette_id = 0;
	vars->view.target_palette_id = 0;
	vars->view.transition_start = 0.0;
	vars->view.transition_duration = 1.0;
	vars->view.transition_fraction = 0.0;
	vars->view.transitioning = 0;
	vars->base_max_iter = 300;
	vars->fractal_type = JULIA;
	vars->view.c.r = atof(argv[2]);
	vars->view.c.i = atof(argv[3]);
	vars->initial_width = vars->view.max.r - vars->view.min.r;
}
