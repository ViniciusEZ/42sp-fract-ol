/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:07:38 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/18 02:29:51 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(0);
}

int	destroy_hook(t_vars *vars)
{
	close_window(vars);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_window(vars);
	else if (keycode == 97 || keycode == 100 || keycode == 115
		|| keycode == 119)
		handle_movement(keycode, vars);
	else if (keycode == 65361 || keycode == 65363)
		handle_palette_switch(keycode, vars);
	redraw(vars);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	double	factor;
	double	fx;
	double	fy;

	if (button != 4 && button != 5)
		return (0);
	if (button == 4)
		factor = 0.8;
	else
		factor = 1.25;
	fx = (double)x * INV_WIDTH;
	fy = (double)y * INV_HEIGHT;
	handle_zoom(vars, factor, fx, fy);
	redraw(vars);
	return (0);
}

int	loop_hook(t_vars *vars)
{
	struct timeval	tv;
	double			now;
	double			elapsed;

	if (vars->view.transitioning)
	{
		gettimeofday(&tv, NULL);
		now = tv.tv_sec + (double)tv.tv_usec * 0.000001;
		elapsed = now - vars->view.transition_start;
		vars->view.transition_fraction = elapsed
			* vars->view.inv_transition_duration;
		if (vars->view.transition_fraction >= 1.0)
		{
			vars->view.palette_id = vars->view.target_palette_id;
			vars->view.transitioning = 0;
			vars->view.transition_fraction = 0.0;
		}
		redraw(vars);
	}
	return (0);
}
