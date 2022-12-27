/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:57:57 by takira            #+#    #+#             */
/*   Updated: 2022/12/27 18:58:00 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

size_t	get_cost_x_to_y(int num, t_stack *stk_x, t_stack *stk_y, int is_sort_a2z)
{
	size_t	cost;
	size_t	insert_idx = get_insert_idx(stk_y, num, is_sort_a2z);
	size_t	r_times = get_r_times(stk_x, num);

	cost = minsize(insert_idx, r_times); // rr
	cost += maxsize(insert_idx, r_times) - cost; // rx or ry
	cost += 1; // px
//	printf(" [get_cost] cost:%zu, num:%d, y_insert_idx:%zu, rx_times:%zu\n", cost, num, insert_idx, r_times);
	return (cost);
}

size_t	get_r_times(t_stack *stk, int num)
{
	size_t			shift_times;
//	const size_t	stk_size = get_stack_size(stk);

	shift_times = 0;
	while (stk)
	{
		if (stk->val == num)
			break ;
		shift_times++;
		stk = stk->next;
	}

//	if (shift_times > stk_size / 2)
//		shift_times = stk_size - shift_times;
	return (shift_times);
}

// z2a  num > max(ni) となるi
// 2 1 5 3
//0  ^b      a
//6    ^a    b

//  M     m
//  6 4 2 0
// ^ ^ ^ ^ ^
// 7 5 3 1 7

//  m M
//  0 6 4 2
// ^ ^ ^ ^ ^
// 1 7 5 3 1

//    m M
//  2 0 6 4
// ^ ^ ^ ^ ^

//      m M
//  4 2 0 6
// ^ ^ ^ ^ ^

// a2z  num < min(ni)となるi or num > max(ni)となるi+1
//  m     M
//  2 4 6 8
// ^ ^ ^ ^ ^
// 1 3 5 7 9
//
//      M m
//  4 6 8 2
// ^ ^ ^ ^ ^
//
//    M m
//  6 8 2 4
// ^ ^ ^ ^ ^
//
//  M m
//  8 2 4 6
// ^ ^ ^ ^ ^
//
size_t	get_insert_idx(t_stack *stk, int num, int is_a2z)
{
	const size_t	stk_size = get_stack_size(stk);
	size_t			insert_idx;
	int				max_lower_than_num;
	const int		min_val = get_min_val(stk);
	const int		max_val = get_max_val(stk);
	size_t			i;

	insert_idx = 0;
	if (!stk)
		return (insert_idx);
	if (num < min_val)
	{
		insert_idx = get_val_idx(stk, min_val) + 1 - is_a2z;
//		max_lower_than_num = min_val;
//		return (get_val_idx(stk, min_val));
	}
	else if (num > max_val)
	{
		insert_idx = get_val_idx(stk, max_val) + is_a2z;
//		max_lower_than_num = max_val;
//		return (get_val_idx(stk, max_val));
	}
	else
	{
		i = 0;
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
	}
	if (insert_idx == stk_size)
		insert_idx = 0;
//	printf(" [ins_idx %s] num:%d, stk_size:%zu, insert_idx:%zu\n", is_a2z ? "a2z" : "z2a", num, stk_size, insert_idx);
	return (insert_idx);
}

size_t	get_rx_times(t_info *info, int num, t_p_stk op_stk)
{
	if (op_stk == E_PUSH_A2B)
		return (get_r_times(info->stk_a, num));
	return (get_r_times(info->stk_b, num));
}

size_t	get_y_insert_idx(t_info *info, int num, t_p_stk op_stk, int is_a2z)
{
	if (op_stk == E_PUSH_A2B)
		return (get_insert_idx(info->stk_b, num, is_a2z));
	return (get_insert_idx(info->stk_a, num, is_a2z));
}

size_t	get_ri_times(size_t rx_times, size_t y_insert_idx)
{
	if (rx_times > y_insert_idx)
		return (rx_times - y_insert_idx);
	return (y_insert_idx - rx_times);
}
