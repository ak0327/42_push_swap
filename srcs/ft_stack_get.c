/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:41:50 by takira            #+#    #+#             */
/*   Updated: 2022/12/27 18:41:51 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

size_t	get_stack_size(t_stack *stk)
{
	size_t	size;

	size = 0;
	while (stk)
	{
		stk = stk->next;
		size++;
	}
	return (size);
}

int	get_max_val(t_stack *stk)
{
	int	max_val;

	max_val = INT_MIN;
	while (stk)
	{
		max_val = max_int(max_val, stk->val);
		stk = stk->next;
	}
	return (max_val);
}

int	get_min_val(t_stack *stk)
{
	int	min_val;

	min_val = INT_MAX;
	while (stk)
	{
		min_val = min_int(min_val, stk->val);
		stk = stk->next;
	}
	return (min_val);
}
