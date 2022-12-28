/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_idx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:03:33 by takira            #+#    #+#             */
/*   Updated: 2022/12/28 15:03:34 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int	get_val_idx(t_stack *stk, int val)
{
	int	idx;

	idx = 0;
	while (stk)
	{
		if (stk->val == val)
			break ;
		stk = stk->next;
		idx++;
	}
	return (idx);
}

static size_t	get_insert_idx(t_stack *stk, int num, int is_a2z, int min_val)
{
	size_t	i;
	size_t	insert_idx;
	int		max_lower_than_num;

	i = 0;
	insert_idx = 0;
	max_lower_than_num = min_val;
	while (stk)
	{
		if (num > stk->val && stk->val >= max_lower_than_num)
		{
			max_lower_than_num = stk->val;
			insert_idx = i;
		}
		stk = stk->next;
		i++;
	}
	insert_idx += is_a2z;
	return (insert_idx);
}

size_t	get_in_idx(t_stack *stk, int num, int is_a2z)
{
	const size_t	stk_size = get_stack_size(stk);
	size_t			insert_idx;
	const int		min_val = get_min_val(stk);
	const int		max_val = get_max_val(stk);

	insert_idx = 0;
	if (!stk)
		return (insert_idx);
	if (num < min_val)
		insert_idx = get_val_idx(stk, min_val) + 1 - is_a2z;
	else if (num > max_val)
		insert_idx = get_val_idx(stk, max_val) + is_a2z;
	else
		insert_idx = get_insert_idx(stk, num, is_a2z, min_val);
	if (insert_idx == stk_size)
		insert_idx = 0;
	return (insert_idx);
}

//	printf(" [ins_idx %s] num:%d, stk_size:%zu, insert_idx:%zu\n",
//	is_a2z ? "a2z" : "z2a", num, stk_size, insert_idx);