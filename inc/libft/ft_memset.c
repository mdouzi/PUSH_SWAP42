/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:40:35 by mdouzi            #+#    #+#             */
/*   Updated: 2022/10/08 02:37:35 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	temp;
	size_t			i;

	p = (unsigned char *)b;
	temp = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		p[i] = temp;
		i++;
	}
	return (p);
}
