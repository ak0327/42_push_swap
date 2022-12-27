/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_single.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:37:06 by takira            #+#    #+#             */
/*   Updated: 2022/12/27 18:37:08 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	swap(t_info *info, t_op cmd, bool is_add_op)
{
	t_stack	*first_elem;
	t_stack	*second_elem;
	t_stack	**stk;

	if (cmd == E_SA)
		stk = &(info->stk_a);
	else
		stk = &(info->stk_b);
	if (!stk || get_stack_size(*stk) < 2)
		return ;
	first_elem = *stk;
	second_elem = first_elem->next;
	first_elem->prev = second_elem;
	first_elem->next = second_elem->next;
	if (second_elem->next)
		second_elem->next->prev = first_elem;
	second_elem->prev = NULL;
	second_elem->next = first_elem;
	*stk = second_elem;
	if (is_add_op && add_cmd_to_list(&(info->op_list), cmd) == FAIL)
		return ;//TODO
}

void	push(t_info *info, t_op cmd, bool is_add_op)
{
	t_stack	*popped_elem;
	t_stack	**push_from;
	t_stack	**push_to;

	push_from = &info->stk_b;
	push_to = &info->stk_a;
	if (cmd == E_PB)
	{
		push_from = &info->stk_a;
		push_to = &info->stk_b;
	}
	if (!push_from || !push_to)
		return ;
	popped_elem = pop_left(push_from);
	if (!popped_elem)
		return ;
	add_left(popped_elem, push_to);
	if (is_add_op && add_cmd_to_list(&info->op_list, cmd) == FAIL)
		return ;//TODO
}

void	rotate(t_info *info, t_op cmd, bool is_add_op)
{
	t_stack	*first_elem;
	t_stack	**stk;

	stk = &info->stk_a;
	if (cmd == E_RB)
		stk = &info->stk_b;
	if (!stk || get_stack_size(*stk) < 2)
		return ;
	first_elem = pop_left(stk);
	if (!first_elem)
		return ;
	add_right(first_elem, stk);
	if (is_add_op && add_cmd_to_list(&info->op_list, cmd) == FAIL)
		return ;//TODO
}

void	reverse_rotate(t_info *info, t_op cmd, bool is_add_op)
{
	t_stack	*last_elem;
	t_stack	**stk;

	stk = &info->stk_a;
	if (cmd == E_RRB)
		stk = &info->stk_b;
	if (!stk || get_stack_size(*stk) < 2)
		return ;
	last_elem = pop_right(stk);
	if (!last_elem)
		return ;
	add_left(last_elem, stk);
	if (is_add_op && add_cmd_to_list(&info->op_list, cmd) == FAIL)
		return ;//TODO
}
