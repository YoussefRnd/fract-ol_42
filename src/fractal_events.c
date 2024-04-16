/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:43:52 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/15 18:35:02 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	close_window(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	mlx_delete_image(fractal->mlx_ptr, fractal->img);
	mlx_close_window(fractal->mlx_ptr);
	exit(EXIT_SUCCESS);
}

void	scroll_handler(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	(void)xdelta;
	fractal = (t_fractal *)param;
	if (ydelta > 0)
		fractal->zoom *= 1.05;
	else if (ydelta < 0)
		fractal->zoom *= 0.95;
	fractal_render(fractal);
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_window(fractal);
	else if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
		fractal->max_iter -= 10;
	else if (keydata.key == 61 && keydata.action == MLX_PRESS)
		fractal->max_iter += 10;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fractal->shift_x -= 0.5 * fractal->zoom;
	fractal_render(fractal);
}
