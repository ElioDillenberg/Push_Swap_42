/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:06:21 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/08 17:28:48 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sort_six(int *a, int *b, size_t *top)
{
	int		top_3[3];
	size_t	i;
	int		i_value;

	top_3[0] = -2147483648;
	top_3[1] = -2147483648;
	top_3[2] = -2147483648;
	i = 0;
	while (i < top[0])
	{
		if (top[i])
	}
}

void	sort_three(int *a)
{
	if (a[0] > a[1] && a[1] > a[2])
		return ;
	else if (a[1] > a[0] && a[0] > a[2])
	{
		ft_putstr("ra\n");
		ft_putstr("sa\n");
		ft_putstr("ra\n");
	}
	else if (a[2] > a[0] && a[1] > a[0])
	{
		ft_putstr("ra\n");
		ft_putstr("sa\n");
	}
	else if (a[2] > a[0] && a[0] > a[1])
		ft_putstr("sa\n");
	else if (a[1] > a[2] && a[2] > a[0])
		ft_putstr("rra\n");
	else if (a[2] > a[1] && a[1] > a[0])
	{
		ft_putstr("sa\n");
		ft_putstr("rra\n");
	}
}

void	less_than_four(int *a, int *b, size_t *top)
{
	if (top[0] == 2)
	{
		if (a[0] < a[1])
			ft_putstr("sa\n");
	}
	else if (top[0] == 3)
		sort_three(a);
	else if (top[0] > 3)
		sort_siz(a, top);
}
