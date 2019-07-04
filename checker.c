/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:03:50 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/01 17:13:39 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

int		check_arr(int *a, u_int top_a, u_int top_b)
{
	u_int	i;

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

int		run_algo(int *a, u_int *top_a, int *b, u_int *top_b)
{
	char	*command;
	int		ret;

	while ((ret = get_next_line(0, &command)) && ret != -1 && ret != 0)
	{
		if (ft_strcmp(command, "sa") == 0)
			swap_a_b(a, *top_a);
		else if (ft_strcmp(command, "sb") == 0)
			swap_a_b(b, *top_b);
		else if (ft_strcmp(command, "ss") == 0)
			swap_both(a, *top_a, b, *top_b);
		else if (ft_strcmp(command, "pa") == 0)
			push_a_b(b, top_b, a, top_a);
		else if (ft_strcmp(command, "pb") == 0)
			push_a_b(a, top_a, b, top_b);
		else if (ft_strcmp(command, "ra") == 0)
			rotate_a_b(a, *top_a);
		else if (ft_strcmp(command, "rb") == 0)
			rotate_a_b(b, *top_b);
		else if (ft_strcmp(command, "rr") == 0)
			rotate_both(a, *top_a, b, *top_b);
		else if (ft_strcmp(command, "rra") == 0)
			rev_rotate_a_b(a, *top_a);
		else if (ft_strcmp(command, "rrb") == 0)
			rev_rotate_a_b(b, *top_b);
		else if (ft_strcmp(command, "rrr") == 0)
			rev_rotate_both(a, *top_a, b, *top_b);
		else
		{
			ft_memdel((void**)&command);
			return (-1);
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		*a;
	int		*b;
	u_int	top_a;
	u_int	top_b;

	if (argc == 1 || check_integers(argc, argv) == -1)
		return (ft_printf("Error\n"));
	top_a = argc - 1;
	top_b = 0;
	if (!(a = (int*)malloc(sizeof(int) * top_a)))
		return (-1);
	if (!(b = (int*)malloc(sizeof(int) * top_a)))
		return (-1);
	while (--top_a > 0)
		a[top_b++] = ft_atoi(argv[top_a + 1]);
	a[top_b] = ft_atoi(argv[top_a + 1]);
	top_a = argc - 1;
	top_b = 0;
	if (check_doubles(a, top_a) == -1 || run_algo(a, &top_a, b, &top_b) == -1)
		return (ft_printf("Error\n"));
	check_arr(a, top_a, top_b) == -1 ? ft_printf("KO\n") : ft_printf("OK\n");
	ft_memdel((void**)&a);
	ft_memdel((void**)&b);
	return (0);
}
