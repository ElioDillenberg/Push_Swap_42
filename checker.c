/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:03:50 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/10 16:42:09 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

/*
** This function takes care of the rotation functions within run algo
*/

static int	check_rot_instr(char *command, int *a, int *b, size_t *top)
{
	if (ft_strcmp(command, "ra") == 0)
		rotate_a_b(a, top[0]);
	else if (ft_strcmp(command, "rb") == 0)
		rotate_a_b(b, top[1]);
	else if (ft_strcmp(command, "rr") == 0)
		rotate_both(a, top[0], b, top[1]);
	else if (ft_strcmp(command, "rra") == 0)
		rev_rotate_a_b(a, top[0]);
	else if (ft_strcmp(command, "rrb") == 0)
		rev_rotate_a_b(b, top[1]);
	else if (ft_strcmp(command, "rrr") == 0)
		rev_rotate_both(a, top[0], b, top[1]);
	else
		return (-1);
	return (0);
}

/*
** This function reads on sdin thanks to get next line
** it executes functions according to instruction found
*/

static int	run_algo(int *a, int *b, size_t *top)
{
	char	*command;
	int		ret;

	while ((ret = get_next_line(0, &command)) && ret != -1 && ret != 0)
	{
		if (ft_strcmp(command, "sa") == 0)
			swap_a_b(a, top[0]);
		else if (ft_strcmp(command, "sb") == 0)
			swap_a_b(b, top[1]);
		else if (ft_strcmp(command, "ss") == 0)
			swap_both(a, top[0], b, top[1]);
		else if (ft_strcmp(command, "pa") == 0)
			push_a_b(b, &(top[1]), a, &(top[0]));
		else if (ft_strcmp(command, "pb") == 0)
			push_a_b(a, &(top[0]), b, &(top[1]));
		else if (check_rot_instr(command, a, b, top) == -1)
		{
			ft_memdel((void**)&command);
			return (-1);
		}
		ft_memdel((void**)&command);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	int		*a;
	int		*b;
	size_t	top[2];

	if (argc == 1 || check_integers(argc, argv) == -1)
		return ((int)write(2, "Error\n", 6));
	top[0] = argc - 1;
	top[1] = 0;
	if (!(a = (int*)malloc(sizeof(int) * top[0])))
		return (-1);
	if (!(b = (int*)malloc(sizeof(int) * top[0])))
		return (-1);
	while (--top[0] > 0)
		a[top[1]++] = ft_atoi(argv[top[0] + 1]);
	a[top[1]] = ft_atoi(argv[top[0] + 1]);
	top[0] = argc - 1;
	top[1] = 0;
	if (check_dbl(a, b, top[0]) == -1 || run_algo(a, b, top) == -1)
		return ((int)write(2, "Error\n", 6));
	check_arr(a, top[0], top[1]) == -1 ? ft_putstr("KO\n") : ft_putstr("OK\n");
	ft_memdel((void**)&a);
	ft_memdel((void**)&b);
	return (0);
}
