/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 10:27:28 by kioulian          #+#    #+#             */
/*   Updated: 2016/05/15 14:49:29 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_is_negative(int *negative, int *n)
{
	if (*n < 0)
	{
		*negative = 1;
		*n *= -1;
	}
}

char	*ft_itoa(int n)
{
	int		temp;
	int		len;
	char	*str;
	int		negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 2;
	temp = n;
	negative = 0;
	ft_is_negative(&negative, &n);
	while (temp /= 10)
		len++;
	len += negative;
	str = (char*)malloc(sizeof(char) * len);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative == 1)
		str[0] = '-';
	return (str);
}
