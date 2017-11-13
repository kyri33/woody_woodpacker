/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:30:51 by kioulian          #+#    #+#             */
/*   Updated: 2016/07/24 17:18:13 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (*(unsigned char *)&s1[i] < *(unsigned char *)&s2[i])
			return (-1);
		else if (*(unsigned char *)&s1[i] > *(unsigned char *)&s2[i])
			return (1);
		i++;
	}
	return (0);
}
