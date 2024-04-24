/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_events_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:43:52 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/24 16:48:43 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol_bonus.h"

void	close_window(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	mlx_terminate(fractal->mlx_ptr);
	exit(EXIT_SUCCESS);
}

static void	adjust_boundaries(t_fractal *fractal, double cursor_x,
		double cursor_y, double zoom_factor)
{
	fractal->x_min = cursor_x + ((fractal->x_min - cursor_x) * zoom_factor);
	fractal->y_min = cursor_y + ((fractal->y_min - cursor_y) * zoom_factor);
	fractal->y_max = cursor_y + ((fractal->y_max - cursor_y) * zoom_factor);
	fractal->x_max = cursor_x + ((fractal->x_max - cursor_x) * zoom_factor);
}

void	scroll_handler(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	double		cursor_x;
	double		cursor_y;
	double		zoom_factor;

	(void)xdelta;
	fractal = (t_fractal *)param;
	if (ydelta < 0)
	{
		zoom_factor = 1.05;
		fractal->zoom *= zoom_factor;
	}
	else if (ydelta > 0)
	{
		zoom_factor = 0.95;
		fractal->zoom *= zoom_factor;
	}
	else
		return ;
	cursor_x = scale(fractal->xpos, fractal->x_min, fractal->x_max, WIDTH);
	cursor_y = scale(fractal->ypos, fractal->y_min, fractal->y_max, HEIGHT);
	adjust_boundaries(fractal, cursor_x, cursor_y, zoom_factor);
	fractal_render(fractal);
}

void	key_handler(mlx_key_data_t kdata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (kdata.key == MLX_KEY_ESCAPE && kdata.action == MLX_RELEASE)
		close_window(fractal);
	else if ((kdata.key == MLX_KEY_MINUS || kdata.key == MLX_KEY_KP_SUBTRACT)
		&& kdata.action == MLX_RELEASE)
	{
		if (fractal->max_iter - 10 > 0)
			fractal->max_iter -= 10;
	}
	else if (((kdata.key == MLX_KEY_EQUAL && kdata.modifier == MLX_SHIFT)
			|| kdata.key == MLX_KEY_KP_ADD) && kdata.action == MLX_RELEASE)
		fractal->max_iter += 10;
	else if (kdata.key == MLX_KEY_DOWN && kdata.action == MLX_RELEASE)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (kdata.key == MLX_KEY_UP && kdata.action == MLX_RELEASE)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (kdata.key == MLX_KEY_LEFT && kdata.action == MLX_RELEASE)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (kdata.key == MLX_KEY_RIGHT && kdata.action == MLX_RELEASE)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else
		return ;
	fractal_render(fractal);
}

void	cursor_handler(double xpos, double ypos, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	fractal->xpos = xpos;
	fractal->ypos = ypos;
}
