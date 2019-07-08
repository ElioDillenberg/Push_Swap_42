/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:19:28 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/08 11:46:27 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

/*
** This file contains the function to execute following commands:
** rra / rrb / rrr
** Added function needed to check input in both push_swap and checker
*/

int		rev_rotate_a_b(int *a_b, size_t top)
{
	size_t	x;
	int		temp;

	if (top < 2)
		return (-1);
	temp = a_b[0];
	x = 0;
	while (x < top - 1)
	{
		a_b[x] = a_b[x + 1];
		x++;
	}
	a_b[top - 1] = temp;
	return (0);
}

int		rev_rotate_both(int *a, size_t top_a, int *b, size_t top_b)
{
	rev_rotate_a_b(a, top_a);
	rev_rotate_a_b(b, top_b);
	return (0);
}

int		check_doubles(int *a, size_t top_a)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (++i < top_a)
	{
		j = i;
		while (++j < top_a)
			if (a[j] == a[i])
				return (-1);
	}
	return (0);
}

static int	max_min_integer_check(int i, char **argv)
{
	if (argv[i][0] == '-')
	{
		if (ft_strcmp(argv[i], "-2147483648") > 0)
			return (-1);
	}
	else if (argv[i][0] == '+')
	{
		if (ft_strcmp(argv[i], "+2147483647") > 0)
			return (-1);
	}
	else
		if (ft_strcmp(argv[i], "2147483647") > 0)
			return (-1);
	return (0);
}

int		check_integers(int argc, char **argv)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		x = 0;
		if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j++]) == 0 || ++x > 10)
				return (-1);
			if (x == 10)
				if (max_min_integer_check(i, argv) == -1)
					return (-1);
		}
	}
	return (0);
}
