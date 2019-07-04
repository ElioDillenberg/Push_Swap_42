/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:21:07 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/03 21:24:18 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>


/*
** i'm trying to place all cards from A into B, returning the index of the
** one card that needs the least amount of instructions to move
*/

/*
** 1 always count the number of moves to place card on top of A
** 2 count the number of moves necessary to place the cart in the right spot  
** on pile B 
*/

/*
** the goal here is to understand if the A card is > top B / < bot B or else 
** if else, then need to check how many actions required to place it properly
*/

u_int	moves_to_place_in_b(int testing, int *b, u_int *top, u_int movements)
{
	u_int	i;
	int		testing;


	i = top[1] - 1;
	while (i > 0)
	//using rb
	movements[2] = ;
	//using rrb
	movements[3] = ;
}

void	moves_to_place_top_a(int *a, u_int *top, u_int trying_to_move, u_int *movements)
{
	//using ra
	movements[0] = top[0] - trying_to_move;
	//using rra
	movements[1] = trying_to_move + 1;
	/*
	if (trying_to_move < (top[0] - 1 / 2))
		return (top[0] - trying_to_move);
	else
		return (trying_to_move + 1);
	*/
}

u_int	select_card(int *a, int *b, u_int *top)
{
	u_int		to_move;
	u_int		trying_to_move;
	u_int		moves_to_move;
	u_int		moves_trying_to_move;
	u_int		movements[4];
	s_target	trying;
	s_target	final;

	to_move = top[0] - 1;
	trying_to_move = trying_to_move - 1;
	moves_to_move = 0;
	moves_trying_to_move = 0;
	while (--trying_to_move > 0)
	{
		moves_to_place_top_a(a, top, trying_to_move, moments);
		moves_to_place_in_b(to_move, b, u_int *top, movements)
		if (moves_trying_to_move < 3)
			return (trying_to_move);
		else if (moves_trying_to_move > moves_to_move)
		{
			moves_to_move = moves_trying_to_move;
			to_move = trying_to_move;
		}
	}
	return (to_move);
}

void	homemade_algo(int *a, int *b, u_int *top)
{
	while (top[0] > 0)
	{
		select_card(a, b, top);
		ft_putstr("pb\n");
		push_a_b(a, top[0], b, top[1]);
	}
	while (top[1] > 0)
	{
		ft_putstr("pa\n");
		push_a_b(b, top[1], a, top[0]);
	}
}

int		main(int argc, char **argv)
{
	int		*a;
	int		*b;
	u_int	top[2];

	if (argc == 1 || check_integers(argc, argv) == -1)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	top[0] = argc - 1;
	top[1] = 0;
	if (!(a = (int*)malloc(sizeof(int) * top[0])))
		return (-1);
	if (!(b = (int*)malloc(sizeof(int) * top[1])))
		return (-1);
	while (--top[0] > 0)
		a[top[1]++] = ft_atoi(argv[top[0] + 1]);
	a[top[1]] = ft_atoi(argv[top[0] + 1]);
	top[0] = argc - 1;
	top[1] = 0;
	if (check_doubles(a, top[0]) == -1)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	//quick_sort(a, 0, top[0] - 1, top);
	//get_min_algo(a, b, top);
	homemade_algo();
	ft_memdel((void**)&a);
	ft_memdel((void**)&b);
	return (0);
}
