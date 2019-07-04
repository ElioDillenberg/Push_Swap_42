/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:48:39 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/02 18:52:00 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static u_int	get_min(int *a, u_int top_a)
{
	u_int	x;
	u_int	res;
	int		res_value;

	x = 0;
	res = 0;
	res_value = 2147483647;
	while (x < top_a)
	{
		if (a[x] < res_value)
		{
			res_value = a[x];
			res = x;
		}
		x++;
	}
	return (res);
}

static void	rr_nd_push(int *a, int *b, u_int *top, u_int iterations)
{
	while (iterations > 0)
	{
		ft_putstr("rra\n");
		rev_rotate_a_b(a, top[0]);
		iterations--;
	}
	ft_putstr("pb\n");
	push_a_b(a, &(top[0]), b, &(top[1]));
}

static void	r_nd_push(int *a, int *b, u_int *top, u_int iterations)
{
	while (iterations > 0)
	{
		ft_putstr("ra\n");
		rotate_a_b(a, top[0]);
		iterations--;
	}
	ft_putstr("pb\n");
	push_a_b(a, &(top[0]), b, &(top[1]));
}

void	get_min_algo(int *a, int *b, u_int *top)
{
	u_int	min_index;
	int		min;

	while (top[0] > 0)
	{
		min_index = get_min(a, top[0]);
		min = a[min_index];
		if (min_index < (top[0] / 2))
			rr_nd_push(a, b, top, min_index + 1);
		else
			r_nd_push(a, b, top, top[0] - min_index - 1);
	}
	while (top[1] > 0)
	{
		ft_putstr("pa\n");
		push_a_b(b, &(top[1]), a, &(top[0]));
	}
}
