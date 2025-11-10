/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 01:12:25 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/08 23:48:03 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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

static void	init_fractal_type(t_vars *vars, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		set_view_mandelbrot(vars);
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
			print_error();
		set_view_julia(vars, argv);
	}
	else if (ft_strcmp(argv[1], "tricorn") == 0)
		set_view_tricorn(vars);
	else if (ft_strcmp(argv[1], "burning_ship") == 0)
		set_view_burning_ship(vars);
	else
		print_error();
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 2)
		print_error();
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fract-ol");
	vars.img = init_image(vars.mlx);
	init_fractal_type(&vars, argc, argv);
	redraw(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0, destroy_hook, &vars);
	mlx_loop_hook(vars.mlx, loop_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
