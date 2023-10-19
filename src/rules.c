/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:04:00 by mdouzi            #+#    #+#             */
/*   Updated: 2023/03/19 02:28:25 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rb(t_stack *b)
{
	int	i;
	int	temp;

	if (b->top > 0)
	{
		i = b->top;
		temp = b->data[i];
		while (i > 0)
		{
			b->data[i] = b->data[i - 1];
			i--;
		}
		b->data[i] = temp;
		ft_printf("rb\n");
		return (1);
	}
	else
		return (0);
}

int	rr(t_stack *a, t_stack *b)
{
	t_rule	s;

	if (a->top > 0 && b->top > 0)
	{
		s.i = a->top;
		s.temp = a->data[s.i];
		while (s.i > 0)
		{
			a->data[s.i] = a->data[s.i - 1];
			s.i--;
		}
		a->data[s.i] = s.temp;
		s.i = b->top;
		s.temp = b->data[s.i];
		while (s.i > 0)
		{
			b->data[s.i] = b->data[s.i - 1];
			s.i--;
		}
		b->data[s.i] = s.temp;
		ft_printf("rr\n");
		return (1);
	}
	else
		return (0);
}

int	rra(t_stack *a)
{
	int	i;
	int	temp;

	if (a->top > 0)
	{
		i = 0;
		temp = a->data[0];
		while (i < a->top)
		{
			a->data[i] = a->data[i + 1];
			i++;
		}
		a->data[i] = temp;
		ft_printf("rra\n");
		return (1);
	}
	else
		return (0);
}

int	rrb(t_stack *b)
{
	int	i;
	int	temp;

	if (b->top > 0)
	{
		i = 0;
		temp = b->data[0];
		while (i < b->top)
		{
			b->data[i] = b->data[i + 1];
			i++;
		}
		b->data[i] = temp;
		ft_printf("rrb\n");
		return (1);
	}
	else
		return (0);
}

int	rrr(t_stack *a, t_stack *b)
{
	t_rule	s;

	if (a->top > 0 && b->top > 0)
	{
		s.i = 0;
		s.temp = a->data[0];
		while (s.i < a->top)
		{
			a->data[s.i] = a->data[s.i + 1];
			s.i++;
		}
		a->data[s.i] = s.temp;
		s.i = 0;
		s.temp = b->data[0];
		while (s.i < b->top)
		{
			b->data[s.i] = b->data[s.i + 1];
			s.i++;
		}
		b->data[s.i] = s.temp;
		printf("rrr\n");
		return (0);
	}
	else
		return (0);
}
