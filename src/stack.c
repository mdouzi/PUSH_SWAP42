/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:12:17 by mdouzi            #+#    #+#             */
/*   Updated: 2023/03/19 02:29:18 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stack(t_stack *a, t_stack *b, int len)
{
	a->data = (int *)malloc(sizeof(int) * len);
	a->top = len;
	b->data = (int *)malloc(sizeof(int) * len);
	b->top = -1;
}

void	to_stack(t_stack *a, t_need *s)
{
	s->j = 0;
	while (s->i >= 0 && s->j <= size_arr(s->args))
	{
		if (my_atoi(s->args[s->j]) != 0)
			ft_check(a->data, my_atoi(s->args[s->j]), size_arr(s->args));
		if (my_atoi(s->args[s->j]) == 0 && s->zero != 0)
			error_f();
		if (my_atoi(s->args[s->j]) == 0)
			s->zero++;
		a->data[s->i] = ft_atoi(s->args[s->j]);
		s->i--;
		s->j++;
	}
}

void	sort_stack(t_stack *a, t_stack *b, t_need *s)
{
	if (is_sorted(a) == 0)
	{
		if (a->top <= 2)
			sort_3(a, b);
		else if (a->top <= 4)
			sort_5(a, b);
		else if (a->top >= 4 && a->top <= 100)
			sort_range_min(a, b, s->sort_list);
		else if (a->top > 100)
			sort_range_max(a, b, s->sort_list);
	}
}

int	ra(t_stack *a)
{
	int	i;
	int	temp;

	if (a->top > 0)
	{
		i = a->top;
		temp = a->data[i];
		while (i > 0)
		{
			a->data[i] = a->data[i - 1];
			i--;
		}
		a->data[i] = temp;
		ft_printf("ra\n");
		return (1);
	}
	else
		return (0);
}
