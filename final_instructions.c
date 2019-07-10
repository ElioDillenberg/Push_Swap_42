/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:06:21 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/10 18:11:04 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/*
** sort_three sorts A, when A contains exactly 3 elements
*/

static void	ra_sa_rra(int *a, size_t *top)
{
	ft_putstr("ra\n");
	rotate_a_b(a, top[0]);
	ft_putstr("sa\n");
	swap_a_b(a, top[0]);
	ft_putstr("rra\n");
	rev_rotate_a_b(a, top[0]);
}

static void	sort_three(int *a, size_t *top)
{
	if (a[0] < a[1] && a[1] < a[2])
	{
		ft_putstr("ra\n");
		rotate_a_b(a, top[0]);
		ft_putstr("sa\n");
		swap_a_b(a, top[0]);
	}
	else if (a[1] < a[0] && a[0] < a[2])
	{
		ft_putstr("ra\n");
		rotate_a_b(a, top[0]);
	}
	else if (a[0] < a[2] && a[2] < a[1])
	{
		ft_putstr("rra\n");
		rev_rotate_a_b(a, top[0]);
	}
	else if (a[2] < a[0] && a[0] < a[1])
		ra_sa_rra(a, top);
	else if (a[1] < a[2] && a[2] < a[0])
	{
		ft_putstr("sa\n");
		swap_a_b(a, top[0]);
	}
}

/*
** This function will rotate pb the necessary number of times to get the max
** value on top of the stack in order to be able to push all cards back to a
** i[0] = i, i[1] = max, i[2] = rot, i[3] = rev_rot
*/

static void	rotate_b_max(int *a, int *b, size_t *top)
{
	size_t	i[4];

	i[0] = top[1];
	i[1] = top[1] - 1;
	while (--i[0] < top[1])
	{
		if (b[i[0]] > b[i[1]])
			i[1] = i[0];
	}
	i[2] = top[1] - i[1] - 1;
	i[3] = i[1] + 1;
	if (i[2] <= i[3])
		while (i[2]-- > 0)
		{
			ft_putstr("rb\n");
			rotate_a_b(b, top[1]);
		}
	else
		while (i[3]-- > 0)
		{
			ft_putstr("rrb\n");
			rev_rotate_a_b(b, top[1]);
		}
	sort_three(a, top);
}

/*
** This function rotates B in order to have the MAX on top (inverted sorting)
** finishing the algorithm and then pushes all B towards A
*/

void		rot_b_nd_push_a(int *a, int *b, size_t *top)
{
	rotate_b_max(a, b, top);
	while (top[1]-- > 0)
		ft_putstr("pa\n");
}

/*
** This function handles all different cases when A contains 3 elements or less
*/

void		less_than_four(int *a, size_t *top)
{
	if (top[0] == 2)
	{
		if (a[0] < a[1])
			ft_putstr("sa\n");
	}
	else if (top[0] == 3)
		sort_three(a, top);
}
