/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:20:44 by mdouzi            #+#    #+#             */
/*   Updated: 2023/03/19 03:34:21 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_num(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		++i;
	}
	while (n > 0)
	{
		++i;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	bb;
	char	*str;
	int		i;

	bb = n;
	i = len_num(bb);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (bb == 0 || bb == -0 || bb == +0)
		str[0] = '0';
	else if (bb < 0)
	{
		str[0] = '-';
		bb = bb * (-1);
	}
	while (bb != 0)
	{
		--i;
		str[i] = (bb % 10) + 48;
		bb = bb / 10;
	}
	return (str);
}
