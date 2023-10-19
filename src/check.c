/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:31:56 by mdouzi            #+#    #+#             */
/*   Updated: 2023/03/17 23:42:50 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_input(char *str)
{
	int	i;
	int	digit;

	i = 0;
	digit = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit++;
		i++;
	}
	if (digit == 0)
		return (0);
	return (1);
}

void	check_argument(char **str)
{
	int	sign;
	int	number;
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		sign = 0;
		number = 0;
		while (str[j][i])
		{
			check_helper(str[j], i, sign, number);
			i++;
		}
		j++;
	}
}

void	check_helper(char *str, int i, int sign, int number)
{
	while (str[i])
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '\0' && number == 0)
			error_f();
		if (str[i] == '-' || str[i] == '+')
		{
			sign++;
			i++;
		}
		if (str[i] != '-' && str[i] != '+' && !(str[i] >= '0' && str[i] <= '9')
			&& str[i] != 32 && !(str[i] >= 9 && str[i] <= 13))
			error_f();
		while (ft_isdigit(str[i]))
		{
			number++;
			i++;
		}
		if ((str[i] == '-' || str[i] == '+') && number >= 1)
			error_f();
		if (sign > 1)
			error_f();
	}
}
