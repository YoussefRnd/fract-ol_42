/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:43:52 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/24 16:42:34 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

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
	else
		return ;
	fractal_render(fractal);
}
