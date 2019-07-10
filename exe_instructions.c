/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:14:47 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/10 18:11:33 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

/*
** These functions execute the instructions found in t_target *final and
** print them on the standard output as they are being executed
*/

static void	exe_instr_ra_rb(int *a, int *b, size_t *top, t_target *final)
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
}

static void	exe_instr_rra_rrb(int *a, int *b, size_t *top, t_target *final)
{
	if (final->rra_toggle == true)
	{
		while (final->rra > 0)
		{
			ft_putstr("rra\n");
			rev_rotate_a_b(a, top[0]);
			(final->rra)--;
		}
	}
	if (final->rrb_toggle == true)
	{
		while (final->rrb > 0)
		{
			ft_putstr("rrb\n");
			rev_rotate_a_b(b, top[1]);
			(final->rrb)--;
		}
	}
}

static void	exe_instr_rr_rrr(int *a, int *b, size_t *top, t_target *final)
{
	if (final->rr_toggle == true)
	{
		while (final->rr > 0)
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
}

void		exe_instr(int *a, int *b, size_t *top, t_target *final)
{
	exe_instr_ra_rb(a, b, top, final);
	exe_instr_rra_rrb(a, b, top, final);
	exe_instr_rr_rrr(a, b, top, final);
	ft_putstr("pb\n");
	push_a_b(a, &(top[0]), b, &(top[1]));
}
