/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:39:02 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/07 16:52:53 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char *str)
{
	int i;
	int k;

	i = 1;
	k = 1;
	if (str[0] == '\0' || !str[0])
		return (-1);
	if (str[0] == 32 || (9 <= str[0] && str[0] <= 13))
		k = 0;
	while (str[i])
	{
		if (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
			i++;
		else if (str[i - 1] == 32 || (9 <= str[i - 1] && str[i - 1] <= 13))
		{
			i++;
			k++;
		}
		else
			i++;
	}
	return (k);
}

static int	malloc_str(char *str, char **tab)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
			i++;
		else
		{
			while (!(str[i] == 32 || (9 <= str[i] && str[i] <= 13)) && str[i])
			{
				k++;
				i++;
			}
			if (!(tab[j] = (char*)malloc(sizeof(char) * (k + 1))))
			{
				while (i > 0)
				return (-1);
			}
			k = 0;
			j++;
		}
	}
	return (0);
}

static void	fil_strings(char *str, char **tab)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
			i++;
		else
		{
			while (!(str[i] == 32 || (9 <= str[i] && str[i] <= 13)) && str[i])
			{
				tab[j][k] = str[i];
				k++;
				i++;
			}
			tab[j][k] = '\0';
			k = 0;
			j++;
		}
	}
}

char	**ft_split_whitespaces(char *str)
{
	int		nb_words;
	char	**tab;
	int		i;

	i = 0;
	nb_words = count_words(str);
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	if (malloc_str(str, tab) == -1)
	{
		ft_memdel((void**)tab);
		return (NULL);
	}
	fil_strings(str, tab);
	tab[nb_words] = 0;
	return (tab);
}
