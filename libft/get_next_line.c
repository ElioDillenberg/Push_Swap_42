/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:12:27 by edillenb          #+#    #+#             */
/*   Updated: 2019/07/17 11:34:20 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int		m_stor(char **stor)
{
	if (!*stor)
	{
		if (!(*stor = (char*)malloc(sizeof(char) * 1)))
			return (-1);
		(*stor)[0] = '\0';
	}
	return (0);
}

char	*trim_to_eol(char **str)
{
	char	*result;
	char	*new_str;
	int		len;
	int		i;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len])
		len++;
	i = ft_strlen(*str) - len;
	if (!(result = ft_strsub((const char**)str, 0, len, 0)))
	{
		ft_memdel((void**)str);
		return (NULL);
	}
	if (!(new_str = ft_strsub((const char**)str, len + 1, i, 0)))
	{
		ft_memdel((void**)str);
		ft_memdel((void**)result);
		return (NULL);
	}
	free(*str);
	*str = new_str;
	return (result);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*stor = NULL;
	char			*temp;

	if (!line || fd < 0 || fd > OM || BUFF_SIZE < 1 || m_stor(&stor) == -1)
		return (-1);
	while (!(ft_strchr(stor, '\n')) && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (ret == -1 || !(temp = ft_strjoin(stor, buf)))
		{
			ft_memdel((void**)&stor);
			return (-1);
		}
		free(stor);
		stor = temp;
	}
	if (ret == 0 && ft_strlen(stor) == 0)
		return (0);
	if (!(*line = trim_to_eol(&stor)))
		return (-1);
	if (ret == 0 && ft_strlen(stor) == 0)
		ft_memdel((void**)&stor);
	return (1);
}
