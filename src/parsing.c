/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:32:58 by mdouzi            #+#    #+#             */
/*   Updated: 2023/03/19 02:26:59 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_check(int a[], int b, int len)
{
	while (len > 0)
	{
		if (a[len] == b)
			error_f();
		len--;
	}
}

char	*split_args(char *argv[], int argc)
{
	int		i;
	char	*res;

	if (!argv || argc < 2)
		return (NULL);
	i = 1;
	res = ft_strdup("");
	while (argv[i] && argc > 1)
	{
		res = ft_strjoin_kill(res, argv[i]);
		i++;
		argc--;
	}
	return (res);
}

int	size_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}

int	*bubble_sort(t_stack *a)
{
	int	*res;
	int	i;
	int	j;

	res = (int *)malloc(sizeof(int) * (a->top + 1));
	i = 0;
	j = 0;
	while (i <= a->top)
	{
		res[i] = a->data[i];
		i++;
	}
	i = 0;
	while (i < a->top)
	{
		j = 0;
		while (j < a->top - i)
		{
			if (res[j] > res[j + 1])
				ft_swap(&res[j], &res[j + 1]);
			j++;
		}
		i++;
	}
	return (res);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
