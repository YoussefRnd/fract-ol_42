/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:45:23 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/05 03:54:26 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	pixel_put(t_fractal *fractal, int x, int y, int color)
{
	int	offset;

	offset = (y * fractal->img.line_size) + (x * (fractal->img.bits_per_pixel
				/ 8));
	(*(unsigned int *)(offset + fractal->img.pixel_ptr)) = color;
}

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
			pixel_put(fractal, x, y, color);
			return ;
		}
		i++;
	}
	pixel_put(fractal, x, y, BLACK);
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
		mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
			fractal->img.img_ptr, 0, 0);
		y++;
	}
}
