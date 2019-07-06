/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:53:51 by edillenb          #+#    #+#             */
/*   Updated: 2019/06/25 17:50:08 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/*
** This file contains the functions to execute the following commands:
** sa / sb / ss / pa / pb / ra / rb / rr
*/

int		swap_a_b(int *a_b, u_int top)
{
	int	temp;

	if (top < 2)
		return (-1);
	temp = a_b[top - 1];
	a_b[top - 1] = a_b[top - 2];
	a_b[top - 2] = temp;
	return (0);
}

int		swap_both(int *a, u_int top_a, int *b, u_int top_b)
{
	swap_a_b(a, top_a);
	swap_a_b(b, top_b);
	return (0);
}

int		push_a_b(int *src, u_int *top_src, int *dst, u_int *top_dst)
{
	if (*top_src == 0)
		return (-1);
	dst[*top_dst] = src[*top_src - 1];
	(*top_src)--;
	(*top_dst)++;
	return (0);
}

int		rotate_a_b(int *a_b, u_int top)
{
	u_int	x;
	int		temp;

	if (top < 2)
		return (-1);
	temp = a_b[top - 1];
	x = top + 1;
	while (--x > 0)
		a_b[x] = a_b[x - 1];
	a_b[0] = temp;
	return (0);
}

int		rotate_both(int *a, u_int top_a, int *b, u_int top_b)
{
	rotate_a_b(a, top_a);
	rotate_a_b(b, top_b);
	return (0);
}