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

size_t	calc_cost_rx_ry(t_info *info)
{
	size_t	cost;
	size_t	min_idx;
	size_t	max_idx;

	min_idx = minsize(info->cost->out_idx, info->cost->in_idx);
	max_idx = maxsize(info->cost->out_idx, info->cost->in_idx);
	cost = min_idx; // rr
	cost += max_idx - min_idx; // rx or ry
	cost += 1; // py
	return (cost);
}

size_t	calc_cost_rx_rry(t_info *info)
{
	size_t	cost;

	cost = info->cost->out_idx; // rx
	cost += info->cost->in_from_bottom; // rry
	cost += 1; // py
	return (cost);
}

size_t	calc_cost_rrx_ry(t_info *info)
{
	size_t	cost;

	cost = info->cost->out_from_bottom; // rrx
	cost += info->cost->in_idx; //rry
	cost += 1; // py
	return (cost);
}

size_t	calc_cost_rrx_rry(t_info *info)
{
	size_t	cost;
	size_t	min_idx;
	size_t	max_idx;

	min_idx = minsize(info->cost->out_from_bottom, info->cost->in_from_bottom);
	max_idx = maxsize(info->cost->out_from_bottom, info->cost->in_from_bottom);
	cost = min_idx; // rrr
	cost += max_idx - min_idx; // rrx or rry
	cost += 1; // py
	return (cost);
}

size_t get_min_in_four_nums(size_t x, size_t y, size_t z, size_t n)
{
	return (minsize(minsize(minsize(x, y), z), n));
}

void	get_cost_params(t_info *info, int push_num, t_push_stk op_stk)
{
	t_stack	*stk_x;
	t_stack	*stk_y;
	int		is_sort_a2z;

	stk_x = info->stk_a;
	stk_y = info->stk_b;
	is_sort_a2z = 0;
	if (op_stk == E_PUSH_B2A)
	{
		stk_x = info->stk_b;
		stk_y = info->stk_a;
		is_sort_a2z = 1;
	}
	info->cost->out_idx = get_val_idx(stk_x, push_num);
	info->cost->in_idx = get_in_idx(stk_y, push_num, is_sort_a2z);
	info->cost->size_x = get_stack_size(stk_x);
	info->cost->size_y = get_stack_size(stk_y);
	info->cost->out_from_bottom = info->cost->size_x - info->cost->out_idx;
	info->cost->in_from_bottom = info->cost->size_y - info->cost->in_idx;
}

size_t	calc_x2y_cost_controller(t_info *info, int push_num, t_push_stk op_stk)
{
	size_t	min_cost;

	get_cost_params(info, push_num, op_stk);
	info->cost->cost_rx_ry = calc_cost_rx_ry(info);
	info->cost->cost_rx_rry = calc_cost_rx_rry(info);
	info->cost->cost_rrx_ry = calc_cost_rrx_ry(info);
	info->cost->cost_rrx_rry = calc_cost_rrx_rry(info);
	min_cost = get_min_in_four_nums(info->cost->cost_rx_ry, \
	info->cost->cost_rx_rry, info->cost->cost_rrx_ry, info->cost->cost_rrx_rry);
//	printf("[calc]num:%d :: r-r:%zu, r-rr:%zu, rr-r:%zu, rr-rr:%zu, min:%zu]\n", push_num, info->cost->cost_rx_ry, info->cost->cost_rx_rry, info->cost->cost_rrx_ry, info->cost->cost_rrx_rry, min_cost);
	if (min_cost == info->cost->cost_rx_ry)
		info->cost->shift_type = E_RX_RY;
	else if (min_cost == info->cost->cost_rx_rry)
		info->cost->shift_type = E_RX_RRY;
	else if (min_cost == info->cost->cost_rrx_ry)
		info->cost->shift_type = E_RRX_RY;
	else
		info->cost->shift_type = E_RRX_RRY;
	return (min_cost);
}


//size_t	calc_x2y_cost_controller(t_info *info, t_stack *stk_x, t_stack *stk_y)
//{
//	size_t	min_cost;
//
//	info->cost->out_idx = get_val_idx(stk_x, info->cost->push_num);
//	info->cost->in_idx = get_in_idx(stk_y, info->cost->push_num, info->cost->is_sort_a2z);
//	info->cost->size_x = get_stack_size(stk_x);
//	info->cost->size_y = get_stack_size(stk_y);
//	info->cost->out_from_bottom = info->cost->size_x - info->cost->out_idx;
//	info->cost->in_from_bottom = info->cost->size_y - info->cost->in_idx;
//	info->cost->cost_rx_ry = calc_cost_rx_ry(info);
//	info->cost->cost_rx_rry = calc_cost_rx_rry(info);
//	info->cost->cost_rrx_ry = calc_cost_rrx_ry(info);
//	info->cost->cost_rrx_rry = calc_cost_rrx_rry(info);
//	min_cost = get_min_in_four_nums(info->cost->cost_rx_ry, \
//	info->cost->cost_rx_rry, info->cost->cost_rrx_ry, info->cost->cost_rrx_rry);
//	if (min_cost == info->cost->cost_rx_ry)
//		info->cost->shift_type = E_RX_RY;
//	else if (min_cost == info->cost->cost_rx_rry)
//		info->cost->shift_type = E_RX_RRY;
//	else if (min_cost == info->cost->cost_rrx_ry)
//		info->cost->shift_type = E_RRX_RY;
//	else
//		info->cost->shift_type = E_RRX_RRY;
//	return (min_cost);
//}

//size_t	get_cost_x_to_y(int num, t_stack *stk_x, t_stack *stk_y, int is_sort_a2z)
//{
//	size_t	cost;
//	size_t	insert_idx = get_in_idx(stk_y, num, is_sort_a2z);
//	size_t	r_times = get_r_times(stk_x, num);
//
//	// TODO: shift_type upが前提, shift_type downも考える
//	cost = minsize(insert_idx, r_times); // rr
//	cost += maxsize(insert_idx, r_times) - cost; // rx or ry
//	cost += 1; // px
////	printf(" [get_cost] cost:%zu, num:%d, y_insert_idx:%zu, rx_times:%zu\n", cost, num, insert_idx, r_times);
//	return (cost);
//}

//size_t	get_r_times(t_stack *stk, int num)
//{
//	size_t			shift_times;
////	const size_t	stk_size = get_stack_size(stk);
//
//	shift_times = 0;
//	while (stk)
//	{
//		if (stk->val == num)
//			break ;
//		shift_times++;
//		stk = stk->next;
//	}
//// TODO
////	if (shift_times > stk_size / 2)
////		shift_times = stk_size - shift_times;
//	return (shift_times);
//}

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
size_t	get_in_idx(t_stack *stk, int num, int is_a2z)
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

size_t	get_outidx_stk_x(t_info *info, int num, t_push_stk op_stk)
{
	if (op_stk == E_PUSH_A2B)
		return (get_val_idx(info->stk_a, num));
	return (get_val_idx(info->stk_b, num));
}

size_t	get_inidx_stky(t_info *info, int num, t_push_stk op_stk, int is_a2z)
{
	if (op_stk == E_PUSH_A2B)
		return (get_in_idx(info->stk_b, num, is_a2z));
	return (get_in_idx(info->stk_a, num, is_a2z));
}

size_t	get_ri_times(size_t rx_times, size_t y_insert_idx)
{
	if (rx_times > y_insert_idx)
		return (rx_times - y_insert_idx);
	return (y_insert_idx - rx_times);
}
