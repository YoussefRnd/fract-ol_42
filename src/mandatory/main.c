/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:55:43 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/24 17:02:07 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	invalid_input(void)
{
	ft_putstr_fd("Invalid input!\n", 2);
	ft_putstr_fd("Usage: <program> <fractal> OR ", 2);
	ft_putstr_fd("<program> <fractal> <real> <imaginary>\n", 2);
	ft_putstr_fd("Available fractals:\n\t- mandelbrot\n", 2);
	ft_putstr_fd("\t- julia\t<real> <imaginary>\n", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(lowercase(argv[1]), "mandelbrot", 10)
			&& ft_strlen(argv[1]) == 10) || (argc == 4
			&& !ft_strncmp(lowercase(argv[1]), "julia", 5)
			&& ft_strlen(argv[1]) == 5))
	{
		fractal.name = lowercase(argv[1]);
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia.real = atod(argv[2]);
			fractal.julia.im = atod(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
		invalid_input();
	return (0);
}
