/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:38:18 by mseinic           #+#    #+#             */
/*   Updated: 2015/12/03 16:28:57 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	n1;
	size_t	n2;

	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	if (!(str = (char *)ft_memalloc(n1 + n2 + 1)))
		return (0);
	ft_memcpy(str, s1, n1);
	ft_memcpy(str + n1, s2, n2);
	str[n1 + n2] = '\0';
	return (str);
}
