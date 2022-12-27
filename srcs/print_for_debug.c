/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:22:57 by takira            #+#    #+#             */
/*   Updated: 2022/12/27 18:22:59 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	print_num_array(int *array, size_t elem_cnt, char *str)
{
	size_t i = 0;
	ft_printf("%s :: [", str);
	while (i < elem_cnt)
	{
		ft_printf("%d", array[i]);
		if (i + 1 < elem_cnt)
			ft_printf(", ");
		else
			ft_printf("]\n");
		i++;
	}
}

void	print_cmd_list_with_msg(t_op_list *list, char *msg)
{
	size_t		i;

	i = 1;
	ft_printf("## OP Cmd :: %s ##\n", msg);
	while (list)
	{
		ft_printf(" %02d: %s\n", i, get_cmd(list->cmd));
		list = list->next;
		i++;
	}
	ft_printf("\n");
}

void	print_stack_value(t_stack *stk, char *str)
{
	ft_printf(" Stack %s:[", str);
	while (stk)
	{
		ft_printf("%d", stk->val);
		stk = stk->next;
		if (stk)
			ft_printf(", ");
	}
	ft_printf("]\n");
}

void	print_stacks(t_info *info, char *str)
{
	t_stack *stk_a = info->stk_a;
	t_stack *stk_b = info->stk_b;

	ft_printf("### Stack :: %s ###\n", str);
	print_stack_value(stk_a, "A");
	print_stack_value(stk_b, "B");
	ft_printf("\n");
}

static void	print_stacks_recursion(t_stack *stk_a, t_stack *stk_b)
{
	t_stack	*prev_a;
	t_stack	*prev_b;

	if (!stk_a && !stk_b)
	{
		ft_printf(" |                                                                          |                                                                           |\n");
		return ;
	}
	prev_a = NULL;
	prev_b = NULL;
	if (stk_a)
		prev_a = stk_a->prev;
	if (stk_b)
		prev_b = stk_b->prev;
	print_stacks_recursion(prev_a, prev_b);
	if (stk_a)
		ft_printf(" |val:%03d, stk:%15p, prev:%15p, next:%15p  |", stk_a->val, stk_a, stk_a->prev, stk_a->next);
	else
		ft_printf(" |                                                                          |");
	if (stk_b)
		ft_printf("val:%03d, stk:%15p, prev:%15p, next:%15p   |\n", stk_b->val, stk_b, stk_b->prev, stk_b->next);
	else
		ft_printf("                                                                           |\n");
}

void	print_stacks_val_and_ptr(t_info *info, char *str)
{
	t_stack	*stk_a = info->stk_a;
	t_stack	*stk_b = info->stk_b;

	ft_printf("## Stack :: %s ##\n", str);
	printf("size a:%zu, b:%zu\n", get_stack_size(stk_a), get_stack_size(stk_b));
	while (stk_a && stk_a->next)
		stk_a = stk_a->next;
	while (stk_b && stk_b->next)
		stk_b = stk_b->next;
	print_stacks_recursion(stk_a, stk_b);
	ft_printf(" |--------------------------------------------------------------------------|---------------------------------------------------------------------------|\n");
	ft_printf(" |[a] val   stk               prev                  next                    | [b] val   prev                  next                                      |\n");
	ft_printf(" |--------------------------------------------------------------------------|---------------------------------------------------------------------------|\n\n");
}
