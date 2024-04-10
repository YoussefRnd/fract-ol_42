/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:58:38 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/09 05:56:21 by yboumlak         ###   ########.fr       */
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
	double	real;
	double	im;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_ptr;
	t_img	img;
	double	escape_value;
	int		max_iter;
	double	shift_x;
	double	shift_y;
	double	zoom;
}			t_fractal;

void		fractal_init(t_fractal *fractal);
void		events_init(t_fractal *fractal);

void		fractal_render(t_fractal *fractal);

double		scale(double value, double new_min, double new_max, double old_max);
t_complex	square_complex(t_complex a);
t_complex	sum_complex(t_complex a, t_complex b);

void		close_window(void *param);
void		key_handler(mlx_key_data_t keydata, void *param);
void		scroll_handler(double xdelta, double ydelta, void *param);

#endif