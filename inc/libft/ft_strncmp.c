/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 07:21:36 by mdouzi            #+#    #+#             */
/*   Updated: 2022/10/05 01:02:37 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*pt_s1;
	unsigned char	*pt_s2;

	pt_s1 = (unsigned char *)s1;
	pt_s2 = (unsigned char *)s2;
	i = 0;
	if (!pt_s1 && !pt_s2)
		return (0);
	while (pt_s1[i] != '\0' && pt_s2[i] != '\0' && i < n)
	{
		if (pt_s1[i] != pt_s2[i])
		{
			return (pt_s1[i] - pt_s2[i]);
		}
		i++;
	}
	if (i != n)
		return (pt_s1[i] - pt_s2[i]);
	return (0);
}
