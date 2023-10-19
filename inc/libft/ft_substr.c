/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:02:55 by mdouzi            #+#    #+#             */
/*   Updated: 2022/10/19 23:40:06 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	j;
	size_t	l;

	if (!s)
		return (NULL);
	j = 0;
	l = ft_strlen(s);
	if (len > l)
		len = l;
	if (start > l)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[j + start] && j < len)
	{
		str[j] = s[j + start];
		j++;
	}
	str[j] = '\0';
	return (str);
}
