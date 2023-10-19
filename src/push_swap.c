/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi<mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:08:19 by mdouzi            #+#    #+#             */
/*   Updated: 2023/03/18 11:45:31 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	char	*res;
	t_need	s;
	t_stack	a;
	t_stack	b;

	res = NULL;
	s.zero = 0;
	if (argc >= 2)
	{
		if (argc == 2)
			if (check_input(argv[1]) == 0)
				error_f();
		res = split_args(argv, argc);
		s.args = ft_split(res, ' ');
		s.i = size_arr(s.args);
		init_stack(&a, &b, s.i);
		check_argument(s.args);
		to_stack(&a, &s);
		s.sort_list = bubble_sort(&a);
		sort_stack(&a, &b, &s);
	}
	else
		exit(0);
}
