/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:21:07 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/10 16:03:49 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int		malloc_tabs(int **a, int **b, size_t *top, int argc)
{
	top[0] = argc - 1;
	top[1] = 0;
	if (!(*a = (int*)malloc(sizeof(int) * top[0])))
		return (-1);
	if (!(*b = (int*)malloc(sizeof(int) * top[0])))
	{
		ft_memdel((void**)a);
		return (-1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		*a;
	int		*b;
	size_t	top[2];

	if (argc == 1 || check_integers(argc, argv) == -1)
		return ((int)write(2, "Error\n", 6));
	if (malloc_tabs(&a, &b, top, argc) == -1)
		return (-1);
	while (--top[0] > 0)
		a[top[1]++] = ft_atoi(argv[top[0] + 1]);
	a[top[1]] = ft_atoi(argv[top[0] + 1]);
	top[0] = argc - 1;
	top[1] = 0;
	if (check_dbl(a, b, top[0]) == -1)
		return ((int)write(2, "Error\n", 6));
	if (check_arr(a, top[0], top[1]) == 0)
		return (0);
	if (top[0] > 3)
		algo(a, b, top);
	else
		less_than_four(a, top);
	ft_memdel((void**)&a);
	ft_memdel((void**)&b);
	return (0);
}
