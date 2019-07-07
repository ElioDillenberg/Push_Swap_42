/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:21:07 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/07 17:27:51 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		*a;
	int		*b;
	u_int	top[2];

	a = NULL;
	b = NULL;
	/*
	if (argc == 1 || check_integers(argc, argv) == -1)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	top[0] = argc - 1;
	top[1] = 0;
	if (!(a = (int*)malloc(sizeof(int) * top[0])))
		return (-1);
	if (!(b = (int*)malloc(sizeof(int) * top[0])))
	{
		ft_memdel((void**)&a);
		return (-1);
	}
	while (--top[0] > 0)
		a[top[1]++] = ft_atoi(argv[top[0] + 1]);
	a[top[1]] = ft_atoi(argv[top[0] + 1]);
	top[0] = argc - 1;
	top[1] = 0;
	*/
	top[0] = build_arrays(argc, argv, a, b);
	top[1] = 0;
	ft_printf("DEBUG\n");
	if (check_doubles(a, top[0]) == -1)
	{
		ft_putstr("Error\n");
		ft_memdel((void**)&a);
		ft_memdel((void**)&b);
		return (-1);
	}
//	if (top[0] > 2)
		algo(a, b, top);
//	else
//		less_than_four(a, b, top);
	ft_memdel((void**)&a);
	ft_memdel((void**)&b);
	return (0);
}
