/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 01:01:15 by vfirmino          #+#    #+#             */
/*   Updated: 2025/11/08 23:25:12 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define HEIGHT 800
# define WIDTH 800
# define MAX_ITER 80
# define NUM_PALETTES 4

// Includes necessários
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h> // Para write

typedef enum e_fractal
{
	MANDELBROT,
	JULIA,
	TRICORN,
	BURNING_SHIP
}				t_fractal;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_view
{
	t_complex	min;
	t_complex	max;
	t_complex	c;
	int			max_iter;
	double		gamma;
	int			palette_id;
	int			target_palette_id;
	double		transition_start;
	double		transition_duration;
	double		transition_fraction;
	int			transitioning;
}				t_view;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_view		view;
	double		initial_width;
	int			base_max_iter;
	t_fractal	fractal_type;
}				t_vars;

double			burning_ship(double cr, double ci, int max_iter);
void			draw_pixel_burning_ship(t_data *img, int x, int y,
					t_view *view);
void			draw_burning_ship(t_data *img, t_view *view);
int				get_palette_color(int palette_id, int index);
t_color			extract_rgb(int color);
double			clamp_t(double t);
int				interpolate_color(int c1, int c2, double t);
int				get_start_color(int index, t_view *view);
int				get_gradient_color(double t, t_view *view);
void			close_window(t_vars *vars);
int				destroy_hook(t_vars *vars);
int				key_hook(int keycode, t_vars *vars);
int				mouse_hook(int button, int x, int y, t_vars *vars);
int				loop_hook(t_vars *vars);
void			handle_movement(int keycode, t_vars *vars);
void			handle_palette_switch(int keycode, t_vars *vars);
double			julia(double zr, double zi, t_view *view);
void			draw_pixel_julia(t_data *img, int x, int y, t_view *view);
void			draw_julia(t_data *img, t_view *view);
double			mandelbrot(double cr, double ci, int max_iter);
void			draw_pixel_mandelbrot(t_data *img, int x, int y, t_view *view);
void			draw_mandelbrot(t_data *img, t_view *view);
t_complex		map_to_complex(double x, double y, t_complex min,
					t_complex max);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			set_view_mandelbrot(t_vars *vars);
void			set_view_tricorn(t_vars *vars);
void			set_view_burning_ship(t_vars *vars);
void			set_view_julia(t_vars *vars, char **argv);
double			tricorn(double cr, double ci, int max_iter);
void			draw_pixel_tricorn(t_data *img, int x, int y, t_view *view);
void			draw_tricorn(t_data *img, t_view *view);
int				ft_strcmp(const char *s1, const char *s2);
void			print_error(void);
void			ft_putstr_fd(char *s, int fd);
t_data			init_image(void *mlx);
void			redraw(t_vars *vars);
void			handle_zoom(t_vars *vars, double factor, double fx, double fy);
void			update_max_iter(t_vars *vars);

#endif
