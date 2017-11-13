/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:34:43 by kioulian          #+#    #+#             */
/*   Updated: 2016/07/24 13:48:08 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabsize(char *s, char c)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			i++;
			size++;
		}
	}
	return (size);
}

int		ft_len(char *s, char c, int start)
{
	int		len;

	len = 0;
	while (s[start] != c && s[start])
	{
		len++;
		start++;
	}
	return (len);
}

char	*ft_createstr(char *str, char *s2, char c, int start)
{
	int		i;

	i = 0;
	while (s2[start] && s2[start] != c)
	{
		str[i] = s2[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_createtab(char **tab, char *s, char c, int start)
{
	int		i;
	int		j;
	int		len;

	j = 0;
	len = 0;
	i = start;
	while (s[i])
	{
		len = ft_len(s, c, start);
		tab[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (tab[j])
		{
			tab[j] = ft_createstr(tab[j], (char *)s, c, start);
			j++;
			i += ft_len(s, c, start);
			while (s[i] == c && s[i])
				i++;
			start = i;
		}
		else
			return (NULL);
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (s)
	{
		size = ft_tabsize((char *)s, c);
		tab = (char **)malloc(sizeof(char*) * (size + 1));
		if (tab)
		{
			while (s[i] == c)
				i++;
			tab = ft_createtab(tab, (char *)s, c, i);
			return (tab);
		}
		return (NULL);
	}
	return (NULL);
}
