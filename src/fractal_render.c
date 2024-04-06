/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:45:23 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/06 02:22:17 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// Todo : Implement the draw_pixel function
//! z = z^2 + c
//! z(0, 0)
//! c(x, y)

void	draw_pixel(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	z.real = 0;
	z.im = 0;
	c.real = scale(x, -2, 2, WIDTH);
	c.im = scale(y, 2, -2, HEIGHT);
	i = 0;
	while (i < fractal->max_iter)
	{
		z = sum_complex(square_complex(z), c);
		if (z.real * z.real + z.im * z.im > fractal->escape_value)
		{
			color = scale(i, BLACK, WHITE, fractal->max_iter);
			mlx_put_pixel(fractal->img.img_ptr, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractal->img.img_ptr, x, y, BLUE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(fractal, x, y);
			x++;
		}
		mlx_image_to_window(fractal->mlx_ptr, fractal->img.img_ptr, 0, 0);
		y++;
	}
}
