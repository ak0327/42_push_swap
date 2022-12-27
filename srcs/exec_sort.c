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

int	add_cmd_to_list(t_op_list **list, t_op_cmd cmd)
{
	t_op_list 	*new_node;
	t_op_list 	*last;

	if (!list)
		return (PASS);
	new_node = (t_op_list *)malloc(sizeof(t_op_list));
	if (!new_node)
		return (FAIL);
	new_node->cmd = cmd;
	new_node->next = NULL;
	if (!*list)
		*list = new_node;
	else
	{
		last = *list;
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
	return (PASS);
}

//021 sa ra
//102 sa

//120 ra ra
//201 ra
//210 ra sa
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

/*
void	sort_descending(t_stack **stk, t_op_list **list)
{

}

*/

int max_int(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int min_int(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	get_max_val(t_stack *stk)
{
	int	max_val;

	max_val = INT_MIN;
	while (stk)
	{
		max_val = max_int(max_val, stk->val);
		stk = stk->next;
	}
	return (max_val);
}

int get_min_val(t_stack *stk)
{
	int	min_val;

	min_val = INT_MAX;
	while (stk)
	{
		min_val = min_int(min_val, stk->val);
		stk = stk->next;
	}
	return (min_val);
}

int get_val_idx(t_stack *stk, int val)
{
	size_t			idx;
//	const size_t	stk_size = get_stack_size(stk);

	idx = 0;
	while (stk)
	{
		if (stk->val == val)
			break ;
		stk = stk->next;
		idx++;
	}
//	if (idx == stk_size)
//		idx = 0;
	return (idx);
}

int get_bottom_val(t_stack *stk)
{
	if (!stk)
		return (0);//TODO
	while (stk->next)
		stk = stk->next;
	return (stk->val);
}

int	is_insert_top(t_stack *stk, int num)
{
	const int max_val = get_max_val(stk);
	const int min_val = get_min_val(stk);
	const int top_val = stk->val;

	return ((top_val == min_val || top_val == max_val) && (num < min_val || max_val < num));
}


// num > max(ni) となるi

// z2a
// TODO: min or max
//   0,6 num
//    V
// 2 1 5 3
//0  ^b      a
//6    ^a    b

//  M     m
//  6 4 2 0
// ^ ^ ^ ^ ^
// 7 5 3 1 7  num > max(ni) となるi

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
//size_t	get_insert_idx_z2a(t_stack *stk, int num)
//{
//	const size_t	stk_size = get_stack_size(stk);
//	size_t			insert_idx;
//	int				max_lower_than_num;
//	const int		min_val = get_min_val(stk);
//	const int		max_val = get_max_val(stk);
//	size_t			i;
//
//	insert_idx = 0;
//	if (!stk)
//		return (insert_idx);
//	if (num < min_val)
//	{
//		insert_idx = get_val_idx(stk, min_val) + 1;
//		max_lower_than_num = min_val;
////		return (get_val_idx(stk, min_val));
//	}
//	else if (num > max_val)
//	{
//		insert_idx = get_val_idx(stk, max_val); //TODO +1?
//		max_lower_than_num = max_val;
////		return (get_val_idx(stk, max_val));
//	}
//	else
//	{
//		i = 0;
//		max_lower_than_num = min_val;
//		while (stk)
//		{
//			if (num > stk->val && stk->val >= max_lower_than_num)
//			{
//				max_lower_than_num = stk->val;
//				insert_idx = i;
//			}
//			stk = stk->next;
//			i++;
//		}
//	}
//	if (insert_idx == stk_size)
//		insert_idx = 0;
////	printf(" [get_insert_idx_z2a] num:%d, insert_pos_num: %d, stk_size:%zu, insert_idx:%zu\n", num, max_lower_than_num, stk_size, insert_idx);
//	return (insert_idx);
//}

// num < min(ni)となるi or num > max(ni)となるi+1
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

void	move_elem_x2y(t_info *info, int num, t_p_stk op_stk, int is_a2z) // rr->r->px, TODO: rrr or rr
{
	size_t		rx_times;
	size_t		y_insert_idx;
	size_t		rr_times;
	size_t		ri_times;
	t_op_cmd	ri_cmd;

	if (op_stk == E_PUSH_A2B)
	{
		rx_times = get_r_times(info->stk_a, num);
		y_insert_idx = get_insert_idx(info->stk_b, num, is_a2z);
	}
	else
	{
		rx_times = get_r_times(info->stk_b, num);
		y_insert_idx = get_insert_idx(info->stk_a, num, is_a2z);
	}
	rr_times = minsize(y_insert_idx, rx_times);
//	printf(" [move x->y] x_r_times:%zu, y_insert_idx:%zu, rr_time:%zu\n", rx_times, y_insert_idx, rr_times);
	while (rr_times)
	{
		operation_controller(info, E_RR);
		rr_times--;
	}
	ri_times = 0;
	if (rx_times > y_insert_idx)
		ri_times = rx_times - y_insert_idx;
	else
		ri_times = y_insert_idx - rx_times;
	if (op_stk == E_PUSH_A2B)
	{
		if (y_insert_idx > rx_times)
			ri_cmd = E_RB;
		else if (y_insert_idx < rx_times)
			ri_cmd = E_RA;
	}
	if (op_stk == E_PUSH_B2A)
	{
		if (y_insert_idx > rx_times)
			ri_cmd = E_RA;
		else if (y_insert_idx < rx_times)
			ri_cmd = E_RB;
	}
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
	t_op_cmd	op_cmd;
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
	t_op_cmd	op_cmd;
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

/*
void	optimize_cmds(t_info *info)
{

}
*/