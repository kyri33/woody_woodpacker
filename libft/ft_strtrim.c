/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:23:48 by kioulian          #+#    #+#             */
/*   Updated: 2016/05/13 11:36:39 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	j = 0;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == 32)
		i++;
	while (s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	j = j - 1;
	while (str[j] == '\n' || str[j] == '\t' || str[j] == 32)
		j--;
	j = j + 1;
	while (str[j] != '\0')
	{
		str[j] = '\0';
		j++;
	}
	return (str);
}
