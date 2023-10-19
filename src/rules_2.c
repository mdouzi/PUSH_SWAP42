/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:31:29 by mdouzi            #+#    #+#             */
/*   Updated: 2023/03/19 02:28:08 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	pb(t_stack *a, t_stack *b)
{
	if (a->top >= 0)
	{
		b->top++;
		b->data[b->top] = a->data[a->top];
		a->data[a->top] = 0;
		a->top--;
		ft_printf("pb\n");
		return (1);
	}
	else
		return (0);
}

int	pa(t_stack *a, t_stack *b)
{
	if (b->top >= 0)
	{
		a->top++;
		a->data[a->top] = b->data[b->top];
		b->data[b->top] = 0;
		b->top--;
		ft_printf("pa\n");
		return (1);
	}
	else
		return (0);
}

int	sa(t_stack *a)
{
	int	temp;

	if (a->top >= 1)
	{
		temp = a->data[a->top];
		a->data[a->top] = a->data[a->top - 1];
		a->data[a->top - 1] = temp;
		ft_printf("sa\n");
		return (1);
	}
	else
		return (0);
}

int	sb(t_stack *b)
{
	int	temp;

	if (b->top >= 1)
	{
		temp = b->data[b->top];
		b->data[b->top] = b->data[b->top - 1];
		b->data[b->top - 1] = temp;
		ft_printf("sb\n");
		return (1);
	}
	else
		return (0);
}

int	ss(t_stack *a, t_stack *b)
{
	int	temp_a;
	int	temp_b;

	if (a->top >= 1 && b->top >= 1)
	{
		temp_a = a->data[a->top];
		a->data[a->top] = a->data[a->top - 1];
		a->data[a->top - 1] = temp_a;
		temp_b = b->data[b->top];
		b->data[b->top] = b->data[b->top - 1];
		b->data[b->top - 1] = temp_b;
		ft_printf("ss");
		return (1);
	}
	else
		return (0);
}
