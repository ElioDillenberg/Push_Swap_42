/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_arrays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:09:14 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/07 17:27:49 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

char	**join_tabs(char **one, char **two)
{
	char	**res;
	u_int	len_one;
	u_int	len_two;
	u_int	i;

	len_one = 0;
	len_two = 0;
	i = 0;
	ft_printf("DEBUG_JOINTABS_1\n");
	while (one[len_one] != 0)
		len_one++;
	ft_printf("DEBUG_JOINTABS_2\n");
	if (two)
		while (two[len_two] != 0)
			len_two++;
	ft_printf("DEBUG_JOINTABS_3\n");
	if (!(res = (char**)malloc(sizeof(char*) * len_one + len_two + 1)))
	{
		ft_memdel((void**)one);
		ft_memdel((void**)two);
		return (NULL);
	}
	ft_printf("DEBUG_JOINTABS_4\n");
	while (i < len_one)
	{
		if (!(res[i] = ft_strdup(one[i])))
		{
			ft_memdel((void**)res);
			ft_memdel((void**)one);
			ft_memdel((void**)two);
			return (NULL);
		}
		i++;
	}
	ft_printf("DEBUG_JOINTABS_5\n");
	ft_printf("len_two = %u\n", len_two);
	i = 0;
	while (i < len_two)
	{
		if (!(res[len_one + i] = ft_strdup(two[i])))
		{
			ft_memdel((void**)res);
			ft_memdel((void**)one);
			ft_memdel((void**)two);
			return (NULL);
		}
		i++;
	}
	ft_printf("DEBUG_JOINTABS_6\n");
	ft_memdel((void**)one);
	ft_memdel((void**)two);
	return (res);
}



u_int	build_arrays(int argc, char **argv, int *a, int *b)
{
	char	**final;
	char	**cr;
	u_int	i;
	u_int	j;
	u_int	ret;

	final = NULL;
	i = 0;
	j = 0;
	ft_printf("DEBUG1\n");
	while (++i < (u_int)argc)
	{
		if (!(cr = ft_split_whitespaces(argv[i])))
		{
			ft_memdel((void**)&cr);
			return (0);
		}
		ft_printf("DEBUG1.5\n");
		if (!(final = join_tabs(cr, final)))
			return (0);
		ft_printf("DEBUG1.52\n");
	}
	ft_printf("DEBUG2\n");
	ft_memdel((void**)&cr);
	i = 0;
	while (final[i] != 0) 
		i++;
	ret = i;
	ft_printf("DEBUG3\n");
	if (check_integers(i, final) == -1)
	{
		ft_putstr("Error\n");
		ft_memdel((void**)final);
		return (0);
	}
	ft_printf("DEBUG4\n");
	if (!(a = (int*)malloc(sizeof(int) * i)))
	{
		ft_memdel((void**)final);
		return (0);
	}
	if (!(b = (int*)malloc(sizeof(int) * i)))
	{
		ft_memdel((void**)final);
		ft_memdel((void**)a);
		return (0);
	}
	ft_printf("DEBUG5\n");
	while (--i > 0)
		a[j++] = ft_atoi(final[i] + 1);
	ft_printf("DEBUG6\n");
	return (ret);
}
