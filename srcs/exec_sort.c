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

void sort_a_a2z_small_case(t_info *info, size_t size)
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

int	is_insert_top(t_stack *stk, int num)
{
	const int max_val = get_max_val(stk);
	const int min_val = get_min_val(stk);
	const int top_val = stk->val;

	return ((top_val == min_val || top_val == max_val) && (num < min_val || max_val < num));
}

void	move_elem_x2y(t_info *info, int num, t_p_stk op_stk, int is_a2z) // rr->r->px, TODO: rrr or rr
{
	const size_t	rx_times = get_rx_times(info, num, op_stk);
	const size_t	y_insert_idx = get_y_insert_idx(info, num, op_stk, is_a2z);
	size_t			rr_times;
	size_t			ri_times;
	t_op		ri_cmd;


	rr_times = minsize(y_insert_idx, rx_times);
//	printf(" [move x->y] x_r_times:%zu, y_insert_idx:%zu, rr_time:%zu\n", rx_times, y_insert_idx, rr_times);
	while (rr_times)
	{
		operation_controller(info, E_RR);
		rr_times--;
	}
	ri_times = get_ri_times(rx_times, y_insert_idx);
	ri_cmd = get_ri_cmd(op_stk, rx_times, y_insert_idx);
	while (ri_times--)
		operation_controller(info, ri_cmd);
	if (op_stk == E_PUSH_A2B)
		operation_controller(info, E_PB);
	else
		operation_controller(info, E_PA);
}

void	push_a2b_for_z2a(t_info *info)
{
	size_t	min_cost;
	size_t	tmp_cost;
	int		min_cost_num;
	t_stack	*stk_a;

	min_cost = SIZE_MAX;
	stk_a = info->stk_a;
//	printf("\n#[Calc cost a->b]\n");
	while (stk_a)
	{
		tmp_cost = get_cost_x_to_y(stk_a->val, info->stk_a, info->stk_b, 0);
		if (tmp_cost < min_cost)
		{
			min_cost = tmp_cost;
			min_cost_num = stk_a->val;
		}
//		printf("  [COST] val:%d, tmp_cost:%zu, min:%zu, min_cost_num:%d\n", stk_a->val, tmp_cost, min_cost, min_cost_num);
		stk_a = stk_a->next;
	}
//	printf("\n\n#[Move min cost num]");
	move_elem_x2y(info, min_cost_num, E_PUSH_A2B, 0);
}

void	push_b2a_for_a2z(t_info *info)
{
	size_t	min_cost;
	size_t	tmp_cost;
	int		min_cost_num;
	t_stack	*stk_b;

	min_cost = SIZE_MAX;
	stk_b = info->stk_b;
//	printf("\n#[Calc cost a<-b]\n");
	while (stk_b)
	{
		tmp_cost = get_cost_x_to_y(stk_b->val, info->stk_b, info->stk_a, 1);
		if (tmp_cost < min_cost)
		{
			min_cost = tmp_cost;
			min_cost_num = stk_b->val;
		}
//		printf("  [COST] val:%d, tmp_cost:%zu, min:%zu, min_cost_num:%d\n\n", stk_b->val, tmp_cost, min_cost, min_cost_num);
		stk_b = stk_b->next;
	}
//	printf("\n\n#[Move min cost num]\n");
	move_elem_x2y(info, min_cost_num, E_PUSH_B2A, 1);
}


// m M
// 0 1
// 0 4 3 2 1
//   ^r x1
//
//       m M
//       3 4
// 3 2 1 0 4
//       ^rr x1
void sort_stk_b_by_r_z2a(t_info *info)
{
	t_stack		*stk;
	size_t		stk_size;
	size_t		max_val_idx;
	t_op	op_cmd;
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

// 0 1 2 3 4
//
// 0 1
// M m
// 4 0 1 2 3
//   ^rr x1
//
//       M m
//       3 4
// 1 2 3 4 0
//         ^r x1
void sort_stk_a_by_r_a2z(t_info *info)
{
	t_stack		*stk;
	size_t		stk_size;
	size_t		min_val_idx;
	t_op	op_cmd;
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


void	exec_sort(t_info *info)
{
	const size_t	stk_a_size = get_stack_size(info->stk_a);

	if (stk_a_size < 4)
		return (sort_a_a2z_small_case(info, stk_a_size));
//	print_stacks(info, "1. initial");
//	printf("\n********** stk a->b **********\n");
	operation_controller(info, E_PB);
	operation_controller(info, E_PB);
//	print_stacks(info, "2. after pb x2");
//	print_stacks(info, "3. after push min cost 1 elem");
	while (get_stack_size(info->stk_a) > 2)
	{
		push_a2b_for_z2a(info);
//		print_stacks(info, "while push a->b 1 elem");
	}
//	printf("\n********** stk b->a **********\n");
	while (get_stack_size(info->stk_b))
	{
		push_b2a_for_a2z(info);
//		print_stacks(info, "  ## while push a<-b 1 elem");
	}
	sort_stk_a_by_r_a2z(info);
//	print_stacks(info, "4. after sort A");
}
