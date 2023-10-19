/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 01:25:22 by mdouzi            #+#    #+#             */
/*   Updated: 2022/10/19 02:02:21 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	j;

	h = (char *)haystack;
	n = (char *)needle;
	if (!h && !len)
		return (NULL);
	if (!*n)
		return (h);
	while (*h && len)
	{
		j = 0;
		while (h[j] == n[j] && j < len && h[j])
			++j;
		if (!n[j])
			return (h);
		++h;
		--len;
	}
	return (0);
}
