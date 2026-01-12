/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehlil <obehlil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:34:14 by obehlil           #+#    #+#             */
/*   Updated: 2026/01/08 13:34:15 by obehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

bool	is_white_space(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	skip_white_spaces(const char **str)
{
	while (is_white_space(**str))
		(*str)++;
}

int	get_sign(const char **str)
{
	int		sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

int	ft_atoi(const char *str, int *error)
{
	long			n;
	int				sign;

	n = 0;
	*error = 0;
	if (!str)
		return (*error = 1, 0);
	skip_white_spaces(&str);
	sign = get_sign(&str);
	if (!is_digit(*str))
		return (*error = 1, 0);
	while (is_digit(*str))
	{
		n = n * 10 + (*str - '0');
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && (-n) < INT_MIN))
			return (*error = 1, 0);
		str++;
	}
	if (*str)
		return (*error = 1, 0);
	return ((int)(n * sign));
}
