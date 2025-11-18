/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:09:59 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/18 02:29:35 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_isspace(char c)
{
	if (c == 32)
		return (1);
	return (0);
}

double	ft_atof(const char *str)
{
	double	res;
	double	sign;
	double	frac;

	res = 0.0;
	sign = 1.0;
	frac = 0.1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1.0;
	while (*str && *str >= '0' && *str <= '9')
		res = res * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str && *str >= '0' && *str <= '9')
		{
			res += (*str++ - '0') * frac;
			frac *= 0.1;
		}
	}
	return (res * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	ret;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ret = write(fd, &s[i], 1);
		(void)ret;
		i++;
	}
}

void	redraw(t_vars *vars)
{
	if (vars->fractal_type == MANDELBROT)
		draw_mandelbrot(&vars->img, &vars->view);
	else if (vars->fractal_type == JULIA)
		draw_julia(&vars->img, &vars->view);
	else if (vars->fractal_type == TRICORN)
		draw_tricorn(&vars->img, &vars->view);
	else if (vars->fractal_type == BURNING_SHIP)
		draw_burning_ship(&vars->img, &vars->view);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
