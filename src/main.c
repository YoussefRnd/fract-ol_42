/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:55:43 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/06 03:35:08 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

char	*lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(lowercase(argv[1]), "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(lowercase(argv[1]), "julia", 5)))
	{
		fractal.name = argv[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		events_init(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
}
