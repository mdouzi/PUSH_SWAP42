/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:13:53 by mdouzi            #+#    #+#             */
/*   Updated: 2022/10/19 23:32:01 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		size;

	size = ft_strlen(s1) + 1;
	str = (char *)malloc(1 * (size));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}
