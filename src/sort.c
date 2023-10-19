/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:57:11 by mdouzi            #+#    #+#             */
/*   Updated: 2023/03/19 02:28:38 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_5(t_stack *a, t_stack *b)
{
	int	min_index;

	while (a->top > 2)
	{
		min_index = ft_min(a);
		if (min_index == a->top)
			pb(a, b);
		else if (min_index > a->top - min_index)
			ra(a);
		else if (min_index <= a->top - min_index)
			rra(a);
	}
	sort_3(a, b);
	while (b->top >= 0)
		pa(a, b);
}

void	sort_3(t_stack *a, t_stack *b)
{
	int	mini;

	mini = ft_min(a);
	if (is_sorted(a) == 1 && b->top == -1)
		exit(1);
	while (is_sorted(a) == 0 && a->top <= 2)
	{
		if (mini == a->top - 2 && a->data[a->top] > a->data[a->top - 1])
		{
			sa(a);
			rra(a);
		}
		else if (mini == a->top - 1 && a->data[a->top] > a->data[a->top - 2])
			ra(a);
		else if (mini == a->top - 1)
			sa(a);
		else if (a->top == mini && a->data[a->top - 1] > a->data[a->top - 2])
		{
			sa(a);
			ra(a);
		}
		else if (a->top - 2 == mini && a->data[a->top] < a->data[a->top - 1])
			rra(a);
	}
}

int	is_sorted(t_stack *a)
{
	int	i;

	if (a->top <= 0)
		return (1);
	i = 0;
	while (i < a->top)
	{
		if (a->data[i] < a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_min(t_stack *a)
{
	int	i;
	int	min;
	int	k;

	i = 0;
	k = 0;
	min = 2147483647;
	while (i <= a->top)
	{
		if (a->data[i] < min)
		{
			min = a->data[i];
			k = i;
		}
		i++;
	}
	return (k);
}

int	ft_max(t_stack *b)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i <= b->top)
	{
		if (b->data[i] > b->data[max])
			max = i;
		i++;
	}
	return (max);
}
