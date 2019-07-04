/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:01:52 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/04 16:19:06 by edillenb         ###   ########.fr       */
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

void	get_rot(u_int *top, u_int move_a, u_int move_b, t_target *cr)
{
	cr->ra = top[0] - move_a;
	cr->rra = move_a + 1;
	cr->rb = top[1] - move_b;
	cr->rb = move_b + 1;
}

/*
** This function resets a t_target structure
*/

void	rst_stru(t_target *stru, u_int index)
{
	if (index != 1)
	{
		stru->ra = 0;
		stru->rra = 0;
		stru->rb = 0;
		stru->rrb = 0;
		stru->rr = 0;
		stru->rrr = 0;
		stru->index = 0;
		stru->value = 0;
		stru->instr = 4294967295;
	}
	stru->ra_toggle = false;
	stru->rra_toggle = false;
	stru->rb_toggle = false;
	stru->rrb_toggle = false;
	stru->rr_toggle = false;
	stru->rrr_toggle = false;
}

/*
** Copy t_target structure content to another t_target structure
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
	dst->rr = src->rr;
	dst->rr_toggle = src->rr_toggle;
	dst->rrr = src->rrr;
	dst->rrr_toggle = src->rrr_toggle;
	dst->index = src->index;
	dst->value = src->value;
	dst->instr = src->instr;
}

/*
** This function will a toggle the right instructions in the structure based on
** the input index (which corresponds to the right combination of instructions)
*/

void	switch_toggles(t_target *cr, u_int i)
{
	reset_toggles(cr, 1);
	if (i == 0)
		//ra + rb
	{
		if (cr->ra > cr->rb)
		{
			cr->rr = cr->rb;
			cr->ra -= cr->rb;
			cr->rr_toggle = true;
			cr->ra_toggle = true;
		}
		else if (cr->ra == cr->rb)
		{
			cr->rr = cr->ra;
			cr->rr_toggle = true;
		}
		else
		{
			cr->rr = cr->ra;
			cr->rb -= cr->ra;
			cr->rr_toggle = true;
			cr->rb_toggle = true;
		}
	}
	else if (i == 1)
		// rra + rrb
	{
		if (cr->rra > cr->rrb)
		{
			cr->rrr = cr->rrb;
			cr->rra -= cr->rrb;
			cr->rrr_toggle = true;
			cr->rra_toggle = true;
		}
		else if (cr->rra == cr->rrb)
		{
			cr->rrr = cr->rra;
			cr->rrr_toggle = true;
		}
		else
		{
			cr->rrr = cr->rra;
			cr->rrb -= cr->rra;
			cr->rrr_toggle = true;
			cr->rrb_toggle = true;
		}
	}
	else if (i == 2)
		// ra + rrb
	{
		cr->ra_toggle = true;
		cr->rrb_toggle = true;
	}
	else
		// rra + rb
	{
		cr->rra_toggle = true;
		cr->rb_toggle = true;
	}
}

/*
** This function will determine the best possible combination of rotations to
** place move_a in pile B / Information is stored in t_target *cr
*/

void	get_instr(t_target *cr)
{
	u_int	tab[4];
	u_int	i;

	i = 0;
	tab[0] = cr->ra > cr->rb ? cr->ra : cr->rb;
	tab[1] = cr->rra > cr->rrb ? cr->rra : cr->rrb;
	tab[2] = cr->ra + cr->rrb;
	tab[3] = cr->rra + cr->rb;
	cr->instr = tab[0];
	switch_toggles(cr, 0);
	while (++i < 4)
		if (tab[i] > cr->instr)
		{
			cr->instr = tab[i];
			switch_toggles(cr, i);
		}
		// else if (tab[i] == cr->instr) -> room to optimize in this case
}

/*
** This functions executes the instructions and displays the instructions
** on the standard output as they are being executed
*/

void	exe_instr(int *a, int *b, int *top, t_target *final)
{
	if (final->ra_toggle == true)
	{
		while (final->ra > 0)
		{
			ft_putstr("ra\n");
			rotate_a_b(a, top[0]);
			(final->ra)--;
		}
	}
	if (final->rb_toggle == true)
	{
		while (final->rb > 0)
		{
			ft_putstr("rb\n");
			rotate_a_b(b, top[1]);
			(final->rb)--;
		}
	}
	if (final->rra == true)
	{
		while (final->rra_toggle > 0)
		{
			ft_putstr("rra\n");
			rev_rotate_a_b(a, top[0]);
			(final->rra)--;
		}
	}
	if (final->rrb == true)
	{
		while (final->rrb_toggle > 0)
		{
			ft_putstr("rrb\n");
			rev_rotate_a_b(b, top[1]);
			(final->rrb)--;
		}
	}
	if (final->rr == true)
	{
		while (final->rr_toggle > 0)
		{
			ft_putstr("rr\n");
			rotate_both(a, top[0], b, top[1]);
			(final->rr)--;
		}
	}
	if (final->rrr_toggle == true)
	{
		while (final->rrr > 0)
		{
			ft_putstr("rrr\n");
			rev_rotate_both(a, top[0], b, top[1]);
			(final->rrr)--;
		}
	}
	ft_putstr("pb\n");
	push_a_b(a, top[0], b, top[1]);
}

/*
** Algo principal
*/

void	algo(int *a, int *b, int *top)
{
	t_target	*cr;
	t_target	*final;
	u_int		move_a;
	u_int		move_b;

	rst_stru(cr, 0);
	rst_stru(final, 0);
	// pushing the first two, this can be optimized easily by handling piles of
	// 1 / 2 / 3 first, and then calling this algorithm
	ft_putstr("pb\n");
	push_a_b(a, top[0], b, top[1]);
	ft_putstr("pb\n");
	push_a_b(a, top[0], b, top[1]);
	while (top[0] > 0)
	{
		move_a = 0;
		while (move_a < top[0])
		{
			move_b = get_move_b(a[move_a], b, top);
			get_rot(top, move_a, move_b, cr);
			get_instr(cr);
			if (cr->instr < final->instr)
				cpy_stru(cr, final);
			move_a++;
		}
		exe_instr(a, b, top, final);
	}
	// here I need to rotate my B pile until it the highest value card is on top
	while (top[1] > 0)
	{
		ft_putstr("pa\n");
		push_a_b(b, top[1], a, top[0]);
	}
}
