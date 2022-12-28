/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:05:14 by takira            #+#    #+#             */
/*   Updated: 2022/12/28 15:05:17 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

size_t	calc_cost_rx_ry(t_info *info)
{
	size_t	cost;
	size_t	min_idx;
	size_t	max_idx;

	min_idx = minsize(info->cost_m->out_idx, info->cost_m->in_idx);
	max_idx = maxsize(info->cost_m->out_idx, info->cost_m->in_idx);
	cost = min_idx;
	cost += max_idx - min_idx;
	cost += 1;
	return (cost);
}

size_t	calc_cost_rx_rry(t_info *info)
{
	size_t	cost;

	cost = info->cost_m->out_idx;
	cost += info->cost_m->in_frm_bottom;
	cost += 1;
	return (cost);
}

size_t	calc_cost_rrx_ry(t_info *info)
{
	size_t	cost;

	cost = info->cost_m->out_frm_bottom;
	cost += info->cost_m->in_idx;
	cost += 1;
	return (cost);
}

size_t	calc_cost_rrx_rry(t_info *info)
{
	size_t	cost;
	size_t	min_idx;
	size_t	max_idx;

	min_idx = \
	minsize(info->cost_m->out_frm_bottom, info->cost_m->in_frm_bottom);
	max_idx = \
	maxsize(info->cost_m->out_frm_bottom, info->cost_m->in_frm_bottom);
	cost = min_idx;
	cost += max_idx - min_idx;
	cost += 1;
	return (cost);
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
	info->cost_m->out_idx = get_val_idx(stk_x, push_num);
	info->cost_m->in_idx = get_in_idx(stk_y, push_num, is_sort_a2z);
	info->cost_m->size_x = get_stack_size(stk_x);
	info->cost_m->size_y = get_stack_size(stk_y);
	info->cost_m->out_frm_bottom = info->cost_m->size_x - info->cost_m->out_idx;
	info->cost_m->in_frm_bottom = info->cost_m->size_y - info->cost_m->in_idx;
}
