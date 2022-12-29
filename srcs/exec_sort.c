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
//	print_stacks(info, "1. initial");
//	printf("\n********** stk a->b **********\n");
/*
	// push a->b for 2 steps small/big
	push_a2b_step_by_step(info);

//	print_stacks(info, "2. after push step by step");

//	printf("\n********** stk a<-b **********\n");
	while (get_stack_size(info->stk_b))
	{
		push_b2a_opt_elem_for_a2z(info);
//		print_stacks(info, "  ## while push a<-b 1 elem");
	}
	sort_stk_a_by_r_a2z(info);

	print_stacks(info, "4. after sort A");
*/

//	print_stacks(info, "1. initial");
//	printf("\n********** stk a->b **********\n");

	//これは不要かも
//	min_val_idx = get_val_idx(info->stk_a, 0);
//	max_val_idx = get_val_idx(info->stk_a, (int)info->input_num_cnt - 1);

/*
	size_t cost_min = calc_x2y_cost_controller(info, 0, E_PUSH_A2B);
	size_t cost_max = calc_x2y_cost_controller(info, (int)info->input_num_cnt - 1, E_PUSH_A2B);
	if (cost_min < cost_max)
	{
		calc_x2y_cost_controller(info, 0, E_PUSH_A2B);
		push_num_x2y(info, 0, E_PUSH_A2B, info->cost_m->shift_type);
//		calc_x2y_cost_controller(info, (int)info->input_num_cnt - 1, E_PUSH_A2B);
//		push_num_x2y(info, (int)info->input_num_cnt - 1, E_PUSH_A2B, info->cost_m->shift_type);
	}
	else
	{
		calc_x2y_cost_controller(info, (int)info->input_num_cnt - 1, E_PUSH_A2B);
		push_num_x2y(info, (int)info->input_num_cnt - 1, E_PUSH_A2B, info->cost_m->shift_type);
//		calc_x2y_cost_controller(info, 0, E_PUSH_A2B);
//		push_num_x2y(info, 0, E_PUSH_A2B, info->cost_m->shift_type);
	}
//	print_stacks(info, "push min and max");
*/

//	if (min_val_idx * 2 <= info->input_num_cnt)
//		while (info->stk_a->val == 0)
//			operation_controller(info, E_RA);
//	else
//		while (info->stk_a->val == 0)
//			operation_controller(info, E_RRA);

//	int num1;
//	int num2;
//	num1 = (int)info->input_num_cnt / 3;
//	num2 = (int)info->input_num_cnt / 3 * 2;
//	while (num1 < info->stk_a->val && info->stk_a->val < num2)
//		operation_controller(info, E_RA);//TODO:RA or RRA

	i = 0;
	if (pattern == E_M)
		while (i++ < info->input_num_cnt / 4)
			operation_controller(info, E_RA);

	operation_controller(info, E_PB);
	operation_controller(info, E_PB);

//	print_stacks(info, "2. after pb x2");
//	print_stacks(info, "3. after push min cost_m 1 elem");
	while (get_stack_size(info->stk_a) > 2)
	{
		push_a2b_opt_elem_for_z2a(info);
//		print_stacks(info, "while push a->b 1 elem");
	}
//	sort_stk_b_by_r_z2a(info);
//	while (get_stack_size(info->stk_a) >= 3)
//		operation_controller(info, E_PB);
//	operation_controller(info, E_PB);
	//	printf("\n********** stk b->a **********\n");
	while (get_stack_size(info->stk_b))
	{
		push_b2a_opt_elem_for_a2z(info);
//		print_stacks(info, "  ## while push a<-b 1 elem");
	}
	sort_stk_a_by_r_a2z(info);
//	print_stacks(info, "4. after sort A");

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

//static void	sort_stk_b_by_r_z2a(t_info *info)
//{
//	t_stack		*stk;
//	size_t		stk_size;
//	size_t		max_val_idx;
//	t_op		op_cmd;
//	size_t		op_times;
//
//	stk = info->stk_b;
//	stk_size = get_stack_size(stk);
//	if (stk_size == 0)
//		return ;
//	max_val_idx = get_val_idx(stk, (int)stk_size - 1);
//	if (max_val_idx > stk_size - max_val_idx)
//	{
//		op_times = stk_size - max_val_idx;
//		op_cmd = E_RRB;
//	}
//	else
//	{
//		op_times = max_val_idx;
//		op_cmd = E_RB;
//	}
//	while (op_times--)
//		operation_controller(info, op_cmd);
//}

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
