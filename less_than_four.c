/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:06:21 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/09 15:22:12 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/*
** This function sorts A, when a only contains 3 elements
*/

void	sort_three(int *a, size_t *top)
{
	if (a[2] < a[1] && a[1] < a[0])
		return ;
	else if (a[0] < a[1] && a[1] < a[2])
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
	{
		ft_putstr("ra\n");
		rotate_a_b(a, top[0]);
		ft_putstr("sa\n");
		swap_a_b(a, top[0]);
		ft_putstr("rra\n");
		rev_rotate_a_b(a, top[0]);
	}
	else if (a[1] < a[2] && a[2]< a[0])
	{
		ft_putstr("sa\n");
		swap_a_b(a, top[0]);
	}
}

/*
** This function handles all different cases when A contains 3 elements or less
*/

void	less_than_four(int *a, size_t *top)
{
	if (top[0] == 2)
	{
		if (a[0] < a[1])
			ft_putstr("sa\n");
	}
	else if (top[0] == 3)
		sort_three(a, top);
}
