/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_top_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:44:43 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/11 12:41:35 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rra_push_top_4_top_5(int *a, int *b, size_t *top, int *top_5)
{
	size_t	push_counter;
	
	push_counter = 0;
	while (push_counter < 2)
	{
		if (a[0] == top_5[4] || a[0] == top_5[3])
		{
			ft_putstr("pb\n");
			push_a_b(a, &(top[0]), b, &(top[1]));
			push_counter++;
		}
		ft_putstr("rra\n");
		rev_rotate_a_b(a, top[0]);
	}
}

void	ra_push_top_4_top_5(int *a, int *b, size_t *top, int *top_5)
{
	size_t	push_counter;
	
	push_counter = 0;
	while (push_counter < 2)
	{
		if (a[i] == top_5[4] || a[i] == top_5[3])
		{
			ft_putstr("pb\n");
			push_a_b(a, top[0], b, top[1]);
			push_counter++;
		}
		ft_putstr("ra\n");
		rotate_a_b(a, top[0]);
	}
}

int			ra_or_rra(int *a, int *b, size_t *top, size_t *top_4_5)
{
	size_t	ra_top_4;
	size_t	ra_top_5;
	size_t	rra_top_4;
	size_t	rra_top_5;

	ra_top_4 = top[0] - top_4_5[3] - 1;
	rra_top_4 = top_4_5[3] + 1;
	ra_top_5 = top[0] - top_4_5[4] - 1;
	rra_top_5 = top_4_5[4] + 1;
	if (ra_top_4 + ra_top_5 < rra_top_4 + rra_top_5)
		return (1);
	return (0);

}

void		get_top_4_top_5(int *a, int *b, size_t *top, int *top_5)
{
	size_t	top_4_5[2];
	size_t	i;

	top_4_5[0] = 0;
	top_4_5[1] = 0;
	i = 0;
	while (i < top[0])
	{
		if (a[i] == top_5[4])
			top_4_5[1] = i;
		if (a[i] == top_5[3])
			top_4_5[0] = i;
		i++;
	}
	if (ra_or_rra(a, b, top, top_4_5) == 1)
		ra_push_top_4_top_5(a, b, top, top_5);
	else
		rra_push_top_4_top_5(a, b, top, top_5)
}

/*
** These functions will store the top 5 values within the stack A in a tab
*/

static void	bigger_than_top_4(int *a, size_t i, int *top_5)
{
	if (a[i] > top_5[1])
	{
		top_5[4] = top_5[3];
		top_5[3] = top_5[2];
		top_5[2] = top_5[1];
		top_5[1] = a[i];
	}
	else if (a[i] > top_5[2])
	{
		top_5[4] = top_5[3];
		top_5[3] = top_5[2];
		top_5[2] = a[i];
	}
	else if (a[i] > top_5[3])
	{
		top_5[4] = top_5[3];
		top_5[3] = a[i];
	}
	else if (a[i] > top_5[4])
		top_5[4] = a[i];
}

void		get_top_5(int *a, int *b, size_t *top, int *top_5)
{
	size_t	i;

	i = 0;
	top_5[0] = -2147483648;
	top_5[1] = -2147384638;
	top_5[2] = -2147483648;
	top_5[3] = -2147483648;
	top_5[4] = -2147483648;
	while (i < top[0])
	{
		if (a[i] > top_5[0])
		{
			top_5[4] = top_5[3];
			top_5[3] = top_5[2];
			top_5[2] = top_5[1];
			top_5[1] = top_5[0];
			top_5[0] = a[i];
		}
		else if (a[i] > top_5[4])
			bigger_than_top_4(a, i, top_5);
		i++;
	}
	push_first_two(a, b, top, top_5);
}
