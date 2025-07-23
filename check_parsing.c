/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:11:38 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/23 11:11:40 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_len(char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

static size_t	count_total(char **av)
{
	size_t	total;
	size_t	n;
	int		i;

	total = 0;
	i = 1;
	while (av[i])
	{
		n = get_len(av[i]);
		if (!n)
			return (0);
		total += n;
		if (av[i + 1])
			total++;
		i++;
	}
	return (total);
}

static void	fill_out(char **av, char *out)
{
	size_t	z;
	size_t	n;
	int		i;

	z = 0;
	i = 1;
	while (av[i])
	{
		n = get_len(av[i]);
		ft_memcpy(out + z, av[i], n);
		z += n;
		if (av[i + 1])
			out[z++] = ' ';
		i++;
	}
	out[z] = '\0';
}

char	*join_ps(char **av)
{
	size_t	len;
	char	*out;

	len = count_total(av);
	if (!len)
		return (NULL);
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	fill_out(av, out);
	return (out);
}
