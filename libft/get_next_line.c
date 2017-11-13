/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 10:30:41 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/25 17:29:58 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_read(char **stock, char *str, char **line, int index)
{
	char	*tmp;

	str[index] = '\0';
	if ((tmp = ft_strchr(str, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(*stock, str);
		tmp = NULL;
		free(str);
		str = NULL;
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char	*stock;
	char	*temp;
	char	*str;
	int		index;

	stock = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((index = read(fd, str, BUFF_SIZE)) > 0)
	{
		if (check_read(&stock, str, line, index))
		{
			free(stock);
			stock = NULL;
			return (1);
		}
		temp = stock;
		stock = ft_strjoin(stock, str);
		free(temp);
	}
	return (0);
}
