/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:00:00 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/23 18:57:48 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skip_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

static int	get_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static int	check_overflow(long result, int *error)
{
	if (result < INT_MIN || result > INT_MAX)
	{
		*error = 1;
		return (0);
	}
	return ((int)result);
}

int	ft_atol(const char *str, int *error)
{
	int		i;
	int		sign;
	long	result;

	i = skip_whitespace(str);
	sign = get_sign(str, &i);
	result = 0;
	*error = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result *= sign;
	return (check_overflow(result, error));
}

int	is_numerique(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (-1);
	if ((str[i] == '+' && str[i + 1] == '+')
		|| (str[i] == '-' && str[i + 1] == '-'))
		return (-1);
	else if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == 32))
			i++;
		else
			return (-1);
	}
	return (0);
}
