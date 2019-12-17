/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:01:52 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/17 16:53:44 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

/*
** This function identifies the card to move to the top within B can be
** MAX of B or the one right under the value of the card to move within A
** i[0] = i, i[1] = under, i[2] = max, i[3] = min
*/

size_t	get_move_b(int move_a, int *b, size_t *top)
{
	size_t	i[4];
	int		i_under;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	i_under = -2147483648;
	while (i[0] < top[1])
	{
		if (b[i[0]] > b[i[2]])
			i[2] = i[0];
		if (b[i[0]] < b[i[3]])
			i[3] = i[0];
		if (b[i[0]] < move_a && b[i[0]] >= i_under)
		{
			i[1] = i[0];
			i_under = b[i[1]];
		}
		i[0]++;
	}
	if (move_a > b[i[2]] || move_a < b[i[3]])
		return (i[2]);
	return (i[1]);
}

/*
** This function will push the first two of A (which are not part of the top 3)
** on top of B
*/

void	push_first_two(int *a, int *b, size_t *top, int *top_3)
{
	size_t	push_counter;

	push_counter = 0;
	while (push_counter < 2 && top[0] > 3)
	{
		if (a[top[0] - 1] < top_3[2])
		{
			ft_putstr("pb\n");
			push_a_b(a, &(top[0]), b, &(top[1]));
			push_counter++;
		}
		else
		{
			ft_putstr("ra\n");
			rotate_a_b(a, top[0]);
		}
	}
}

/*
** This function gets the top 3 values within A and stores their value
** inside the top_3 tab
*/

void	get_top_3(int *a, int *b, size_t *top, int *top_3)
{
	size_t	i;

	i = 0;
	top_3[0] = -2147483648;
	top_3[1] = -2147384638;
	top_3[2] = -2147483648;
	while (i < top[0])
	{
		if (a[i] > top_3[0])
		{
			top_3[2] = top_3[1];
			top_3[1] = top_3[0];
			top_3[0] = a[i];
		}
		else if (a[i] > top_3[1])
		{
			top_3[2] = top_3[1];
			top_3[1] = a[i];
		}
		else if (a[i] > top_3[2])
			top_3[2] = a[i];
		i++;
	}
	push_first_two(a, b, top, top_3);
}

/*
** This function decides which option is best, when number of instructions are
** equal in both cases (i[0] is an index, i[1] is the index of max value)
*/

void	equal_instr(t_target *cr, t_target *final, int *b, size_t *top)
{
	size_t	i[2];
	int		rotz_cr;
	int		rotz_final;

	i[0] = top[1];
	i[1] = top[1] - 1;
	while (--i[0] < top[1])
		if (b[i[0]] > b[i[1]])
			i[1] = i[0];
	if (cr->rb_toggle == true || cr->rr_toggle == true)
	{
		if ((rotz_cr = (cr->rb + cr->rr) - (top[1] - i[1] - 1)) < 0)
			rotz_cr *= -1;
	}
	else if ((rotz_cr = (cr->rrb + cr->rrr) - (i[1] + 1)) < 0)
		rotz_cr *= -1;
	if (final->rb_toggle == true || final->rr_toggle == true)
	{
		if ((rotz_final = (final->rb + final->rr) - (top[1] - i[1] - 1)) < 0)
			rotz_final *= -1;
	}
	else if ((rotz_final = (final->rrb + final->rrr) - (i[1] + 1)) < 0)
		rotz_final *= -1;
	if (rotz_cr < rotz_final)
		cpy_stru(cr, final);
}

/*
** Algo principal
*/

int		algo(int *a, int *b, size_t *top)
{
	t_target	cr;
	t_target	final;
	size_t		move_a;
	int			top_3[3];

	get_top_3(a, b, top, top_3);
	while (top[0] > 3 && rst_stru(&final, 0))
	{
		move_a = 0;
		while (move_a < top[0])
		{
			if (a[move_a] < top_3[2])
			{
				get_rot_instr(top, move_a, get_move_b(a[move_a], b, top), &cr);
				if (cr.instr < final.instr)
					cpy_stru(&cr, &final);
				else if (cr.instr == final.instr)
					equal_instr(&cr, &final, b, top);
			}
			move_a++;
		}
		exe_instr(a, b, top, &final);
	}
	rot_b_nd_push_a(a, b, top);
	return (0);
}
