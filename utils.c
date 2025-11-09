/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:09:59 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/08 23:10:21 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	print_error(void)
{
	ft_putstr_fd("Invalid arguments\n", 2);
	ft_putstr_fd("Usage:\n", 2);
	ft_putstr_fd("./fractol mandelbrot\n", 2);
	ft_putstr_fd("./fractol julia <float> <float>\n", 2);
	ft_putstr_fd("./fractol tricorn\n", 2);
	ft_putstr_fd("./fractol burning_ship\n", 2);
	exit(1);
}

t_data	init_image(void *mlx)
{
	t_data	img;

	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
			&img.endian);
	return (img);
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
