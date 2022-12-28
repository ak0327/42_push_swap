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

//// TODO: 4パターン計算してminを実行する  ここではなく、get_coostでこれをやって、min_numを決める、その方法を記録しておき実行する
//void	shift_elems_for_min_cost(t_info *info, int num, t_shift_type shift_op)
//{
//	size_t			rr_times;
//	const size_t	rx_times = get_outidx_stk_x(info, num, op_stk);// TODO: size vs rx times->opt?
//	const size_t	y_insert_idx = get_inidx_stky(info, num, op_stk,
//												  is_a2z);
//
//	rr_times = minsize(y_insert_idx, rx_times);
////	printf(" [move x->y] x_r_times:%zu, y_insert_idx:%zu, rr_time:%zu\n", rx_times, y_insert_idx, rr_times);
//	while (rr_times)
//	{
//		operation_controller(info, E_RR);
//		rr_times--;
//	}
//}

//void	move_elem_x2y(t_info *info, int num, t_shift_type shit_op, t_push_stk op_stk) // rr->r->px
//{
//	size_t	x_out_idx;
//	size_t	y_in_idx;
//	size_t	ri_times;
//	t_op	ri_cmd;
//
//	x_out_idx = get_outidx_stk_x(info, num, op_stk);
//	y_in_idx = get_inidx_stky(info, num, op_stk, info->cost->is_sort_a2z);
//	shift_elems_for_min_cost(info, num, shit_op);
//	ri_times = get_ri_times(x_out_idx, y_in_idx);
//	ri_cmd = get_ri_cmd(op_stk, x_out_idx, y_in_idx);
//	while (ri_times--)
//		operation_controller(info, ri_cmd);
//}

void	push_num_rx_ry(t_info *info, t_push_stk op_stk)
{
	size_t	rr_times;
	size_t	ri_times;
	t_op	rx_cmd;
	t_op 	ry_cmd;

	rr_times = minsize(info->cost->out_idx, info->cost->in_idx);
	ri_times = maxsize(info->cost->out_idx, info->cost->in_idx) - rr_times;
	rx_cmd = E_RA;
	ry_cmd = E_RB;
	if (op_stk == E_PUSH_B2A)
	{
		rx_cmd = E_RB;
		ry_cmd = E_RA;
	}
	while (rr_times--)
		operation_controller(info, E_RR);
	if (ri_times && info->cost->out_idx > info->cost->in_idx)
		while (ri_times--)
			operation_controller(info, rx_cmd);
	else if (ri_times && info->cost->out_idx < info->cost->in_idx)
		while (ri_times--)
			operation_controller(info, ry_cmd);
}

void	push_num_rx_rry(t_info *info, t_push_stk op_stk)
{
	t_op	rx_cmd;
	t_op 	rry_cmd;
	size_t	rx_times;
	size_t	rry_times;

	rx_cmd = E_RA;
	rry_cmd = E_RRB;
	if (op_stk == E_PUSH_B2A)
	{
		rx_cmd = E_RB;
		rry_cmd = E_RRA;
	}
	rx_times = info->cost->out_idx;
	rry_times = info->cost->in_from_bottom;
	while (rx_times--)
		operation_controller(info, rx_cmd);
	while (rry_times--)
		operation_controller(info, rry_cmd);
}

void	push_num_rrx_ry(t_info *info, t_push_stk op_stk)
{
	t_op	rrx_cmd;
	t_op 	ry_cmd;
	size_t	rrx_times;
	size_t	ry_times;

	rrx_cmd = E_RRA;
	ry_cmd = E_RB;
	if (op_stk == E_PUSH_B2A)
	{
		rrx_cmd = E_RRB;
		ry_cmd = E_RA;
	}
	rrx_times = info->cost->out_from_bottom;
	ry_times = info->cost->in_idx;
	while (rrx_times--)
		operation_controller(info, rrx_cmd);
	while (ry_times--)
		operation_controller(info, ry_cmd);
}

void	push_num_rrx_rry(t_info *info, t_push_stk op_stk)
{
	size_t	rrr_times;
	size_t	rri_times;
	t_op	rrx_cmd;
	t_op 	rry_cmd;

	rrr_times = minsize(info->cost->out_from_bottom, info->cost->in_from_bottom);
	rri_times = maxsize(info->cost->out_from_bottom, info->cost->in_from_bottom) - rrr_times;
	rrx_cmd = E_RRA;
	rry_cmd = E_RRB;
	if (op_stk == E_PUSH_B2A)
	{
		rrx_cmd = E_RRB;
		rry_cmd = E_RRA;
	}
	while (rrr_times--)
		operation_controller(info, E_RRR);
	if (rri_times && info->cost->out_from_bottom > info->cost->in_from_bottom)
		while (rri_times--)
			operation_controller(info, rrx_cmd);
	else if (rri_times && info->cost->out_from_bottom < info->cost->in_from_bottom)
		while (rri_times--)
			operation_controller(info, rry_cmd);

}

void	push_num_x2y(t_info *info, int push_num, t_push_stk op_stk, t_shift_type shit_op)
{
	get_cost_params(info, push_num, op_stk);
	if (shit_op == E_RX_RY)
		push_num_rx_ry(info, op_stk);
	else if (shit_op == E_RX_RRY)
		push_num_rx_rry(info, op_stk);
	else if (shit_op == E_RRX_RY)
		push_num_rrx_ry(info, op_stk);
	else
		push_num_rrx_rry(info, op_stk);
	if (op_stk == E_PUSH_A2B)
		operation_controller(info, E_PB);
	else
		operation_controller(info, E_PA);
}

void	push_a2b_opt_elem_for_z2a(t_info *info)
{
	size_t	min_cost;
	size_t	tmp_cost;
	int		min_cost_num;
	t_shift_type	min_cost_op;
	t_stack	*stk_a;

	min_cost = SIZE_MAX;
	stk_a = info->stk_a;
//	printf("\n\n#[Calc cost a->b]\n");
	while (stk_a)
	{
//		info->cost->push_num = stk_a->val;
		tmp_cost = calc_x2y_cost_controller(info, stk_a->val, E_PUSH_A2B);
//		tmp_cost = get_cost_x_to_y(stk_a->val, info->stk_a, info->stk_b, 0);
		if (tmp_cost < min_cost)
		{
			min_cost = tmp_cost;
			min_cost_op = info->cost->shift_type;
			min_cost_num = stk_a->val;
		}
//		printf("  [COST] push_num:%d, tmp_cost:%zu, min:%zu, min_cost_num:%d\n", stk_a->val, tmp_cost, min_cost, min_cost_num);
		stk_a = stk_a->next;
	}
//	printf("\n\n#[Move min cost num]");
//	move_elem_x2y(info, min_cost_num, min_cost_op, E_PUSH_A2B);
	push_num_x2y(info, min_cost_num, E_PUSH_A2B, min_cost_op);
}

void	push_b2a_opt_elem_for_a2z(t_info *info)
{
	size_t	min_cost;
	size_t	tmp_cost;
	int		min_cost_num;
	t_shift_type	min_cost_op;
	t_stack	*stk_b;

	min_cost = SIZE_MAX;
	stk_b = info->stk_b;
//	printf("\n#[Calc cost a<-b]\n");
	while (stk_b)
	{
//		info->cost->push_num = stk_b->val;
		tmp_cost = calc_x2y_cost_controller(info, stk_b->val, E_PUSH_B2A);
//		tmp_cost = get_cost_x_to_y(stk_b->val, info->stk_b, info->stk_a, 1);
		if (tmp_cost < min_cost)
		{
			min_cost = tmp_cost;
			min_cost_op = info->cost->shift_type;
			min_cost_num = stk_b->val;
		}
//		printf("  [COST] val:%d, tmp_cost:%zu, min:%zu, min_cost_num:%d\n\n", stk_b->val, tmp_cost, min_cost, min_cost_num);
		stk_b = stk_b->next;
	}
//	printf("\n\n#[Move min cost num]\n");
//	move_elem_x2y(info, min_cost_num, min_cost_op, E_PUSH_B2A);
	push_num_x2y(info, min_cost_num, E_PUSH_B2A, min_cost_op);
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
		push_a2b_opt_elem_for_z2a(info);
//		print_stacks(info, "while push a->b 1 elem");
	}
//	printf("\n********** stk b->a **********\n");
	while (get_stack_size(info->stk_b))
	{
		push_b2a_opt_elem_for_a2z(info);
//		print_stacks(info, "  ## while push a<-b 1 elem");
	}
	sort_stk_a_by_r_a2z(info);
//	print_stacks(info, "4. after sort A");
}

