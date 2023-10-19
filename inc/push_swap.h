/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:33:19 by mdouzi            #+#    #+#             */
/*   Updated: 2023/03/19 02:30:23 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		*sort_list;
	char	**args;
	int		zero;
	int		i;
	int		j;
}			t_need;

typedef struct push_stack
{
	int		*data;
	int		top;

}			t_stack;

typedef struct s_range
{
	int		start;
	int		end;
	int		range;
}			t_range;

typedef struct s_rules
{
	int		i;
	int		temp;

}			t_rule;

long long	my_atoi(const char *str);
char		*ft_strjoin_kill(char *str1, char *str2);
void		error_f(void);
void		create_stack(t_stack *a, int size, int top);
char		*split_args(char *argv[], int argc);
int			size_arr(char **str);
void		ft_check(int a[], int b, int len);
int			check_input(char *str);
void		ft_swap(int *a, int *b);

int			*bubble_sort(t_stack *a);
int			ft_min(t_stack *a);
int			ft_max(t_stack *b);
int			sa(t_stack *a);
int			sb(t_stack *b);
int			ss(t_stack *a, t_stack *b);
int			pa(t_stack *a, t_stack *b);
int			pb(t_stack *a, t_stack *b);
int			ra(t_stack *a);
int			rb(t_stack *b);
int			rr(t_stack *a, t_stack *b);
int			rra(t_stack *a);
int			rrb(t_stack *b);
int			rrr(t_stack *a, t_stack *b);
void		print_stacks(t_stack *a, t_stack *b);
void		sort_push_swap(t_stack *a, t_stack *b);
int			is_sorted(t_stack *a);
void		short_sort(t_stack *a, t_stack *b);
void		sort_3(t_stack *a, t_stack *b);
void		sort_5(t_stack *a, t_stack *b);
void		check_argument(char **str);
void		check_helper(char *str, int i, int sign, int number);
void		stack_func(t_stack *a, t_stack *b, t_need *s, char *res);
void		init_stack(t_stack *a, t_stack *b, int len);
void		to_stack(t_stack *a, t_need *s);
void		sort_stack(t_stack *a, t_stack *b, t_need *s);

void		push_top(t_stack *a, t_stack *b);
void		sort_range(t_stack *a, t_stack *b, int list[]);
void		sort_range_max(t_stack *a, t_stack *b, int list[]);
void		sort_range_min(t_stack *a, t_stack *b, int list[]);

#endif
