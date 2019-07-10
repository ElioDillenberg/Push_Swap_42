/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:37:00 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/10 18:06:57 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/*
** This function checks if there are any doubles within the int array (stack A)
*/

int			check_dbl(int *a, int *b, size_t top_a)
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
			{
				ft_memdel((void**)&a);
				ft_memdel((void**)&b);
				return (-1);
			}
	}
	return (0);
}

/*
** These two functions check if the are any non-authorized (non-int)
** elements within the input before creating the array of ints
*/

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
	else if (ft_strcmp(argv[i], "2147483647") > 0)
		return (-1);
	return (0);
}

int			check_integers(int argc, char **argv)
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

/*
** This functions checks wether or not an array is sorted
*/

int			check_arr(int *a, size_t top_a, size_t top_b)
{
	size_t	i;

	if (top_b != 0)
		return (-1);
	i = 0;
	while (i < top_a - 1)
	{
		if (a[i] < a[i + 1])
			return (-1);
		i++;
	}
	return (0);
}
