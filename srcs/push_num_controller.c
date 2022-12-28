/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_num_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:48:05 by takira            #+#    #+#             */
/*   Updated: 2022/12/28 14:48:07 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	push_a2b_opt_elem_for_z2a(t_info *info)
{
	size_t		min_cost;
	size_t		tmp_cost;
	int			min_cost_num;
	t_op_type	min_cost_op;
	t_stack		*stk_a;

	min_cost = SIZE_MAX;
	stk_a = info->stk_a;
	while (stk_a)
	{
		tmp_cost = calc_x2y_cost_controller(info, stk_a->val, E_PUSH_A2B);
		if (tmp_cost < min_cost)
		{
			min_cost = tmp_cost;
			min_cost_op = info->cost_m->shift_type;
			min_cost_num = stk_a->val;
		}
		stk_a = stk_a->next;
	}
	push_num_x2y(info, min_cost_num, E_PUSH_A2B, min_cost_op);
}

void	push_b2a_opt_elem_for_a2z(t_info *info)
{
	size_t		min_cost;
	size_t		tmp_cost;
	int			min_cost_num;
	t_op_type	min_cost_op;
	t_stack		*stk_b;

	min_cost = SIZE_MAX;
	stk_b = info->stk_b;
	while (stk_b)
	{
		tmp_cost = calc_x2y_cost_controller(info, stk_b->val, E_PUSH_B2A);
		if (tmp_cost < min_cost)
		{
			min_cost = tmp_cost;
			min_cost_op = info->cost_m->shift_type;
			min_cost_num = stk_b->val;
		}
		stk_b = stk_b->next;
	}
	push_num_x2y(info, min_cost_num, E_PUSH_B2A, min_cost_op);
}

//	printf("\n#[Calc cost_m a<-b]\n");
//	printf("  [COST] val:%d, tmp_cost:%zu, min:%zu,
//	min_cost_num:%d\n\n", stk_b->val, tmp_cost, min_cost, min_cost_num);