/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:06:12 by kioulian          #+#    #+#             */
/*   Updated: 2016/05/15 15:09:34 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (*(unsigned char *)&s1[i] < *(unsigned char *)&s2[i])
			return (-1);
		if (*(unsigned char *)&s1[i] > *(unsigned char *)&s2[i])
			return (1);
		i++;
	}
	return (0);
}
