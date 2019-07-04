/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:43:00 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/04 14:47:29 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define u_int	unsigned int

typedef struct	s_target
{
	u_int	ra;
	bool	ra_toggle;
	u_int	rra;
	bool	rra_toggle;
	u_int	rb;
	bool	rb_toggle;
	u_int	rrb;
	bool	rrb_toggle;
	u_int	rr;
	bool	rr_toggle;
	u_int	rrr;
	u_int	rrr_toggle;
	u_int	index;
	int		value;
	u_int	instr;
}				t_target;

int		swap_a_b(int *a_b, u_int top);
int		swap_both(int *a, u_int top_a, int *b, u_int top_b);
int		push_a_b(int *src, u_int *top_src, int *dst, u_int *top_b);
int		rotate_a_b(int *a_b, u_int top);
int		rotate_both(int *a, u_int top_a, int *b, u_int top_b);

int		rev_rotate_a_b(int *a_b, u_int top);
int		rev_rotate_both(int *a, u_int top_a, int *b, u_int top_b);
int		check_input_arrays(int argc, char **argv);
int		check_doubles(int *a, u_int top_a);
int		check_integers(int argc, char **argv);

int		check_arr(int *a, u_int top_a, u_int top_b);
int		run_algo(int *a, u_int *top_a, int *b, u_int *top_b);
int		check_array(int *a, u_int *top_a, u_int *top_b);

void	get_min_algo(int *a, int *b, u_int *top);

u_int	quick_sort(int *a, u_int p, u_int j, u_int *top);

#endif
