/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 09:09:35 by kioulian          #+#    #+#             */
/*   Updated: 2016/05/13 09:17:23 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	character;
	size_t	i;
	char	*tmp;

	character = (unsigned char)c;
	i = 0;
	tmp = (char*)s;
	while (i < n)
	{
		if (tmp[i] == character)
			return (&tmp[i]);
		i++;
	}
	return (NULL);
}
