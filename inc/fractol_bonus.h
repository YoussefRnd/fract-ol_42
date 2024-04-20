/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:58:38 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/19 21:06:50 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/Libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>

# define WIDTH 1080
# define HEIGHT 1080

# define BLACK 0x000000
# define WHITE 0xFFFFFF

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define ORANGE 0xFFA500
# define PURPLE 0x800080
# define PINK 0xFFC0CB
# define LIME 0xBFFF00

typedef struct s_complex
{
	double		real;
	double		im;
}				t_complex;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_ptr;
	mlx_image_t	*img;
	double		escape_value;
	int			max_iter;
	double		shift_x;
	double		shift_y;
	double		xpos;
	double		ypos;
	double		zoom;
	t_complex	julia;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
}				t_fractal;

void			fractal_init(t_fractal *fractal);
void			events_init(t_fractal *fractal);

void			fractal_render(t_fractal *fractal);

int				julia(t_fractal *fractal, t_complex *coord);
int				mandelbrot(t_fractal *fractal, t_complex *coord);
int				nova(t_fractal *fractal, t_complex *coord);

double			scale(double value, double new_min, double new_max,
					double old_max);
t_complex		square_complex(t_complex a);
t_complex		sum_complex(t_complex a, t_complex b);

double			atod(char *str);

void			close_window(void *param);
void			key_handler(mlx_key_data_t keydata, void *param);
void			scroll_handler(double xdelta, double ydelta, void *param);
void			cursor_handler(double xpos, double ypos, void *param);

int				get_rgba(int r, int g, int b, int a);
int				bernstein_color(t_fractal *fractal, int iterations);

#endif