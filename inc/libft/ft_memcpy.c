/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:17:13 by mdouzi            #+#    #+#             */
/*   Updated: 2022/10/02 20:57:43 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pt_src;
	unsigned char	*pt_dst;
	int				i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	pt_src = (unsigned char *)src;
	pt_dst = (unsigned char *)dst;
	while (n > 0)
	{
		pt_dst[i] = pt_src[i];
		i++;
		n--;
	}
	return (dst);
}
