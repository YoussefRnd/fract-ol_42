/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:14:20 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/22 15:49:58 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol_bonus.h"

int	skip_spaces(char *str, double *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		*sign = -1.0;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

double	atod(char *str)
{
	double	res;
	double	factor;
	double	sign;
	int		i;

	res = 0.0;
	sign = 1.0;
	i = skip_spaces(str, &sign);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	factor = 1.0;
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		factor *= 10;
		i++;
	}
	if (str[i])
		invalid_input();
	return (sign * (res / factor));
}

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
