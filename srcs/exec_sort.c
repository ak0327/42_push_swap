/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:25:58 by takira            #+#    #+#             */
/*   Updated: 2022/12/24 18:25:58 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

/* prototype declaration*/
static void	sort_a_a2z_small_case(t_info *info, size_t size);
static void	sort_stk_a_by_r_a2z(t_info *info);
//static void	sort_stk_b_by_r_z2a(t_info *info);

/* function */
void	exec_sort(t_info *info, t_init_push pattern)
{
	size_t	i;

	if (info->input_num_cnt <= 3)
		return (sort_a_a2z_small_case(info, info->input_num_cnt));
	i = 0;
	if (pattern == E_MIDDLE)
		while (i++ < info->input_num_cnt / 4)
			operation_controller(info, E_RA);
	operation_controller(info, E_PB);
	operation_controller(info, E_PB);
	while (get_stack_size(info->stk_a) > 2)
		push_a2b_opt_elem_for_z2a(info);
	while (get_stack_size(info->stk_b))
		push_b2a_opt_elem_for_a2z(info);
	sort_stk_a_by_r_a2z(info);
}

static void	sort_a_a2z_small_case(t_info *info, size_t size)
{
	const int	first_val = info->stk_a->val;
	const int	second_val = info->stk_a->next->val;

	if (size == 2)
	{
		operation_controller(info, E_RA);
		return ;
	}
	if (first_val == 0 || (first_val == 1 && second_val == 0))
	{
		operation_controller(info, E_SA);
		if (second_val == 2)
			operation_controller(info, E_RA);
		return ;
	}
	operation_controller(info, E_RA);
	if (second_val == 2)
		operation_controller(info, E_RA);
	if (second_val == 1)
		operation_controller(info, E_SA);
}

/*
static void	sort_stk_b_by_r_z2a(t_info *info)
{
	t_stack		*stk;
	size_t		stk_size;
	size_t		max_val_idx;
	t_op		op_cmd;
	size_t		op_times;

	stk = info->stk_b;
	stk_size = get_stack_size(stk);
	if (stk_size == 0)
		return ;
	max_val_idx = get_val_idx(stk, (int)stk_size - 1);
	if (max_val_idx > stk_size - max_val_idx)
	{
		op_times = stk_size - max_val_idx;
		op_cmd = E_RRB;
	}
	else
	{
		op_times = max_val_idx;
		op_cmd = E_RB;
	}
	while (op_times--)
		operation_controller(info, op_cmd);
}
*/

static void	sort_stk_a_by_r_a2z(t_info *info)
{
	t_stack		*stk;
	size_t		stk_size;
	size_t		min_val_idx;
	t_op		op_cmd;
	size_t		op_times;

	stk = info->stk_a;
	stk_size = get_stack_size(stk);
	if (stk_size == 0)
		return ;
	min_val_idx = get_val_idx(stk, 0);
	if (min_val_idx > stk_size - min_val_idx)
	{
		op_times = stk_size - min_val_idx;
		op_cmd = E_RRA;
	}
	else
	{
		op_times = min_val_idx;
		op_cmd = E_RA;
	}
	while (op_times--)
		operation_controller(info, op_cmd);
}
