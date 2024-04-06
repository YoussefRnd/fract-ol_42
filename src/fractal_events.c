/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:43:52 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/06 03:55:49 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	key_press_handler(mlx_key_data_t keydata, void *param)
{
	char *l = "mlx";
	if ((char *)param == l)
		return ;
	if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
		printf("yes");
}