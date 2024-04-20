/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_events_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:43:52 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/19 22:58:53 by yboumlak         ###   ########.fr       */
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

void	scroll_handler(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	double		zoom_factor;
	double		cursor_x;
	double		cursor_y;

	(void)xdelta;
	zoom_factor = 0.0;
	fractal = (t_fractal *)param;
	if (ydelta > 0)
		zoom_factor = 1.05; 
	else if (ydelta < 0)
		zoom_factor = 0.95;
	else
		return ;
	cursor_x = scale(fractal->xpos, fractal->x_min, fractal->x_max, WIDTH);
	cursor_y = scale(fractal->ypos, fractal->y_max, fractal->y_min, HEIGHT);
	fractal->x_min = cursor_x + ((fractal->x_min - cursor_x) * zoom_factor);
	fractal->y_min = cursor_y + ((fractal->y_min - cursor_y) * zoom_factor);
	fractal->y_max = cursor_y + ((fractal->y_max - cursor_y) * zoom_factor);
	fractal->x_max = cursor_x + ((fractal->x_max - cursor_x) * zoom_factor);
	fractal_render(fractal);
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		close_window(fractal);
	else if ((keydata.key == MLX_KEY_MINUS
			|| keydata.key == MLX_KEY_KP_SUBTRACT)
		&& keydata.action == MLX_RELEASE)
	{
		if (fractal->max_iter - 10 > 0)
			fractal->max_iter -= 10;
	}
	else if (((keydata.key == MLX_KEY_EQUAL && keydata.modifier == MLX_SHIFT)
			|| keydata.key == MLX_KEY_KP_ADD) && keydata.action == MLX_RELEASE)
		fractal->max_iter += 10;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else
		return ;
	fractal_render(fractal);
}

void	cursor_handler(double xpos, double ypos, void *param)
{
	t_fractal *fractal;


	fractal = (t_fractal *)param;
	fractal->xpos = xpos;
	fractal->ypos = ypos;
}