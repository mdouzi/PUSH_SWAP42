/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:34:07 by mdouzi            #+#    #+#             */
/*   Updated: 2023/03/19 03:33:54 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long long	my_atoi(const char *str)
{
	long long	res;
	int			n;
	int			i;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
	{
		n *= -n;
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res < 0 || (res > 2147483647 && n == 1)
			|| (res > 2147483648 && n == -1))
			error_f();
		i++;
	}
	return (res * n);
}

void	error_f(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	create_stack(t_stack *a, int size, int top)
{
	a->data = (int *)malloc(sizeof(int) * size);
	a->top = top;
}

char	*join_helper_get(char *ret, char *str1, char *str2)
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
	ret[j++] = ' ';
	i = 0;
	while (str2[i])
	{
		ret[j] = str2[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*ft_strjoin_kill(char *str1, char *str2)
{
	int		str1_len;
	int		str2_len;
	char	*ret;

	str1_len = 0;
	str2_len = 0;
	ret = NULL;
	if (str1)
		str1_len = strlen(str1);
	if (!str1)
	{
		str1 = "";
		str1_len = 0;
	}
	if (!str2)
		return (NULL);
	str2_len = strlen(str2);
	ret = (char *)ft_calloc(sizeof(char), str1_len + str2_len + 2);
	if (!ret)
		return (NULL);
	ret = join_helper_get(ret, str1, str2);
	free((void *)str1);
	return (ret);
}
