/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:36:06 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/10 18:08:27 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function resets a t_target structure
** Depending on the indicated option it will reset only the flags or not
*/

int			rst_stru(t_target *stru, size_t option)
{
	if (option != 1)
	{
		stru->ra = 0;
		stru->rra = 0;
		stru->rb = 0;
		stru->rrb = 0;
		stru->rr = 0;
		stru->rrr = 0;
		stru->index = 0;
		stru->instr = 4294967295;
	}
	stru->ra_toggle = false;
	stru->rra_toggle = false;
	stru->rb_toggle = false;
	stru->rrb_toggle = false;
	stru->rr_toggle = false;
	stru->rrr_toggle = false;
	return (1);
}

/*
** These functions will toggle the right instructions in the structure based on
** the input index (which corresponds to the right combination of instructions)
*/

static void	switch_toggles_zero(t_target *cr)
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

static void	switch_toggles_one(t_target *cr)
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

static void	switch_toggles(t_target *cr, size_t i)
{
	rst_stru(cr, 1);
	if (i == 0)
		switch_toggles_zero(cr);
	else if (i == 1)
		switch_toggles_one(cr);
	else if (i == 2)
	{
		cr->ra_toggle = true;
		cr->rrb_toggle = true;
	}
	else
	{
		cr->rra_toggle = true;
		cr->rb_toggle = true;
	}
}

/*
** This function will determine the best possible combination of rotations to
** place move_a in pile B / Information is stored in t_target *cr
*/

void		get_instr(t_target *cr)
{
	size_t	tab[4];
	size_t	i;

	i = 0;
	tab[0] = cr->ra > cr->rb ? cr->ra : cr->rb;
	tab[1] = cr->rra > cr->rrb ? cr->rra : cr->rrb;
	tab[2] = cr->ra + cr->rrb;
	tab[3] = cr->rra + cr->rb;
	cr->instr = tab[0];
	switch_toggles(cr, 0);
	while (++i < 4)
		if (tab[i] < cr->instr)
		{
			cr->instr = tab[i];
			switch_toggles(cr, i);
		}
}
