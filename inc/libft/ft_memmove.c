/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:11:15 by mdouzi            #+#    #+#             */
/*   Updated: 2022/10/19 22:36:57 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*pt_dest;
	char	*pt_src;
	int		b;

	b = 1;
	i = 0;
	pt_dest = (char *)dest;
	pt_src = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (pt_src > pt_dest)
		ft_memcpy(pt_dest, pt_src, n);
	else
	{
		while (i != n)
		{
			pt_dest[n - b] = pt_src[n - b];
			b++;
			i++;
		}
	}
	return (dest);
}
