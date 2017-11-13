/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:55:46 by kioulian          #+#    #+#             */
/*   Updated: 2016/05/12 10:23:34 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*str;
	int			len;
	size_t		i;

	str = s1;
	len = 0;
	i = 0;
	while (str[len] != '\0')
		len++;
	while (i < n && s2[i] != '\0')
	{
		str[len] = s2[i];
		i++;
		len++;
	}
	str[len] = '\0';
	return (s1);
}
