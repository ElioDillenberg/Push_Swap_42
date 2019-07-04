/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:01:52 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/03 21:24:16 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function identifies the card to move to the top within B can be
** MAX of B or the one right under the value of the card to move within A
*/

u_int	get_move_b(int move_a, int *b, u_int *top)
{
	u_int	max;
	u_int	under;
	int		i_under;
	u_int	i;
	u_int	min;

	max = 0;
	min = 0;
	under = 0;
	i_under = -2147483648;
	i = 0;
	while (i < top[1] - 1)
	{
		if (b[i] > b[max])
			max = i;
		if (b[i] < b[min])
			min = i;
		if (b[i] < move_a && b[i] > i_under)
		{
			i_under = b[i]
			under = i;
		}
		i++;
	}
	if (move_a > b[max] || move_a < b[min])
		return (max);
	return (under);
}

/*
** This function gets the number of RA and RRA needed to put current card on
** top of the A pile and this function gets the number of RB and RRB needto put
** chosen card on top of the B pile / Information stored in t_target struct
*/

void	get_rot(u_int *top, u_int move_a, u_int move_b, t_target *trying)
{
	trying->ra = top[0] - move_a;
	trying->rra = move_a + 1;
	trying->rb = top[1] - move_b;
	trying->rb = move_b + 1;
}

/*
** This function resets a t_target structure
*/

void	rst_stru(t_target *stru)
{
	stru->ra = 0;
	stru->ra_toggle = false;
	stru->rra = 0;
	stru->rra_toggle = false;
	stru->rb = 0;
	stru->rb_toggle = false;
	stru->rrb = 0;
	stru->rrb_toggle = false;
	stru->index = 0;
	stru->value = 0;
	stru->instr = 4294967295;
}

/*
** Copy structure content to another structure
*/

void	cpy_stru(t_target *src, t_target *dst)
{
	dst->ra = src->ra;
	dst->ra_toggle = src->ra_toggle;
	dst->rb = src->rb;
	dst->rb_toggle = src->rb_toggle;
	dst->rra = src->rra;
	dst->rra_toggle = src->rra_toggle;
	dst->rrb = src->rrb;
	dst->rrb_toggle = src->rrb_toggle;
	dst->index = src->index;
	dst->value = src->value;
	dst->instr = src->instr;
}

/*
** This function will determine the best possible combination of rotations to
** place move_a in pile B / Information is stored in t_target *trying
*/

void	get_instr(t_target *trying)
{
	trying->instr = trying->ra > trying->rb ? trying->ra : trying->rb;
	if (trying->)
}

/*
** Algo principal
*/

void	algo(int *a, int *b, int *top)
{
	t_target	*trying;
	t_target	*final;
	u_int		move_a;
	u_int		move_b;

	rst_stru(trying);
	rst_stru(final);

	move_a = 0;
	while (move_a < top[0])
	{
		move_b = get_move_b(a[move_a], b, top);
		get_rot(top, move_a, move_b, trying);
		get_instr(trying);
		if (trying->instr < final->instr)
			cpy_stru(trying, final);
		move_a++;
	}
	exe_instr(a, b, top, final);
}
