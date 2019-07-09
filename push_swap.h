/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:43:00 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/09 16:42:02 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <string.h>

typedef struct	s_target
{
	size_t	ra;
	bool	ra_toggle;
	size_t	rra;
	bool	rra_toggle;
	size_t	rb;
	bool	rb_toggle;
	size_t	rrb;
	bool	rrb_toggle;
	size_t	rr;
	bool	rr_toggle;
	size_t	rrr;
	size_t	rrr_toggle;
	size_t	index;
	int		value;
	size_t	instr;
}				t_target;

int		swap_a_b(int *a_b, size_t top);
int		swap_both(int *a, size_t top_a, int *b, size_t top_b);
int		push_a_b(int *src, size_t *top_src, int *dst, size_t *top_b);
int		rotate_a_b(int *a_b, size_t top);
int		rotate_both(int *a, size_t top_a, int *b, size_t top_b);

int		rev_rotate_a_b(int *a_b, size_t top);
int		rev_rotate_both(int *a, size_t top_a, int *b, size_t top_b);
int		check_input_arrays(int argc, char **argv);
int		check_doubles(int *a, size_t top_a);
int		check_integers(int argc, char **argv);

int		run_algo(int *a, size_t *top_a, int *b, size_t *top_b);
int		check_array(int *a, size_t *top_a, size_t *top_b);

int		algo(int *a, int *b, size_t *top);

void	sort_three(int *a, size_t *top);
void	less_than_four(int *a, size_t *top);

int		check_arr(int *a, size_t top_a, size_t top_b);
#endif
