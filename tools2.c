/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:19:28 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/10 18:10:02 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

/*
** Function used to execute both RRA and RRB
*/

int			rev_rotate_a_b(int *a_b, size_t top)
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

/*
** Function that executes RRR
*/

int			rev_rotate_both(int *a, size_t top_a, int *b, size_t top_b)
{
	rev_rotate_a_b(a, top_a);
	rev_rotate_a_b(b, top_b);
	return (0);
}

/*
** Copy t_target structure content to another t_target structure
*/

void		cpy_stru(t_target *src, t_target *dst)
{
	dst->ra = src->ra;
	dst->ra_toggle = src->ra_toggle;
	dst->rb = src->rb;
	dst->rb_toggle = src->rb_toggle;
	dst->rra = src->rra;
	dst->rra_toggle = src->rra_toggle;
	dst->rrb = src->rrb;
	dst->rrb_toggle = src->rrb_toggle;
	dst->rr = src->rr;
	dst->rr_toggle = src->rr_toggle;
	dst->rrr = src->rrr;
	dst->rrr_toggle = src->rrr_toggle;
	dst->index = src->index;
	dst->instr = src->instr;
}

/*
** This function gets the number of RA and RRA needed to put current card on
** top of the A pile and this function gets the number of RB and RRB needto put
** chosen card on top of the B pile / Information stored in t_target struct
*/

void		get_rot_instr(size_t *top, size_t m_a, size_t m_b, t_target *cr)
{
	cr->ra = top[0] - m_a - 1;
	cr->rra = m_a + 1;
	cr->rb = top[1] - m_b - 1;
	cr->rrb = m_b + 1;
	get_instr(cr);
}
