/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:07:36 by mdouzi            #+#    #+#             */
/*   Updated: 2023/02/16 22:07:27 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_helper(char *ret, char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		ret[i] = str1[i];
		i++;
		j++;
	}
	i = 0;
	while (str2[i])
	{
		ret[j] = str2[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	free(str1);
	return (ret);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	int		str1_len;
	int		str2_len;
	char	*ret;

	i = 0;
	j = 0;
	if (str1)
		str1_len = ft_strlen(str1);
	if (!str1)
	{
		str1 = (char *)ft_calloc(sizeof(char), 1);
		str1[0] = '\0';
		str1_len = 0;
	}
	if (!str1 || !str2)
		return (NULL);
	str2_len = ft_strlen(str2);
	ret = (char *)ft_calloc(sizeof(char), (str1_len + str2_len + 1));
	if (!ret)
		return (NULL);
	ret = join_helper(ret, str1, str2);
	return (ret);
}
