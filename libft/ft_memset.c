/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 08:32:43 by kioulian          #+#    #+#             */
/*   Updated: 2016/05/13 10:15:50 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*character;

	if (len == 0)
	{
		return (b);
	}
	character = (unsigned char *)b;
	while (len--)
	{
		*character = (unsigned char)c;
		if (len)
			character++;
	}
	return (b);
}
