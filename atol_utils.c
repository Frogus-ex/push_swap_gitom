/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:00:00 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/24 16:37:29 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skip_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
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

static int	validate_input(const char *str, int start, int i)
{
	if (i == start || str[i] != '\0')
		return (-1);
	return (0);
}

int	ft_atol(const char *str, int *error)
{
	int		i;
	int		sign;
	long	result;
	int		start;

	i = skip_whitespace(str);
	sign = get_sign(str, &i);
	result = 0;
	*error = 0;
	start = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (validate_input(str, start, i) == -1)
		*error = 1;
	result *= sign;
	return (check_overflow(result, error));
}
