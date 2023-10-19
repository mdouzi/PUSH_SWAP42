/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:09:52 by mdouzi            #+#    #+#             */
/*   Updated: 2023/03/19 02:26:42 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_range(int a, int list[], int start, int end)
{
	int	k;

	k = start;
	while (k <= end)
	{
		if (a < list[start])
			return (2);
		if (a == list[k])
			return (1);
		k++;
	}
	return (0);
}

void	sort_range_max(t_stack *a, t_stack *b, int list[])
{
	t_range	max;

	max.start = 0;
	max.end = 35;
	while (a->top != -1)
	{
		max.range = ft_range(a->data[a->top], list, max.start, max.end);
		if (max.range == 1)
		{
			pb(a, b);
			max.start++;
			max.end++;
		}
		else if (max.range == 0)
			ra(a);
		else if (max.range == 2)
		{
			pb(a, b);
			rb(b);
			max.start++;
			max.end++;
		}
	}
	push_top(a, b);
}

void	sort_range_min(t_stack *a, t_stack *b, int list[])
{
	t_range	min;

	min.start = 0;
	min.end = 15;
	while (a->top != -1)
	{
		min.range = ft_range(a->data[a->top], list, min.start, min.end);
		if (min.range == 1)
		{
			pb(a, b);
			min.start++;
			min.end++;
		}
		else if (min.range == 0)
			ra(a);
		else if (min.range == 2)
		{
			pb(a, b);
			rb(b);
			min.start++;
			min.end++;
		}
	}
	push_top(a, b);
}

void	push_top(t_stack *a, t_stack *b)
{
	int	max;

	while (b->top != -1)
	{
		max = ft_max(b);
		while (max != b->top)
		{
			if (max > b->top / 2)
				rb(b);
			if (max <= b->top / 2)
				rrb(b);
			max = ft_max(b);
		}
		if (max == b->top)
			pa(a, b);
	}
}
