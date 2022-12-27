/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:49:22 by takira            #+#    #+#             */
/*   Updated: 2022/12/27 18:49:24 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int	add_cmd_to_list(t_op_list **list, t_op cmd)
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

void	print_cmd_list(t_op_list *list)
{
	while (list)
	{
		ft_printf("%s\n", get_cmd(list->cmd));
		list = list->next;
	}
}

size_t	get_cmd_list_size(t_op_list *list)
{
	size_t	cnt;

	cnt = 0;
	while (list)
	{
		list = list->next;
		cnt++;
	}
	return (cnt);
}

char	*get_cmd(t_op cmd)
{
	if (cmd == E_SA)
		return ("sa");
	if (cmd == E_SB)
		return ("sb");
	if (cmd == E_SS)
		return ("ss");
	if (cmd == E_PA)
		return ("pa");
	if (cmd == E_PB)
		return ("pb");
	if (cmd == E_RA)
		return ("ra");
	if (cmd == E_RB)
		return ("rb");
	if (cmd == E_RR)
		return ("rr");
	if (cmd == E_RRA)
		return ("rra");
	if (cmd == E_RRB)
		return ("rrb");
	if (cmd == E_RRR)
		return ("rrr");
	return ("Not Exist");
}

t_op	get_ri_cmd(t_p_stk op_stk, size_t rx_times, size_t y_insert_idx)
{
	if (op_stk == E_PUSH_A2B)
	{
		if (y_insert_idx > rx_times)
			return (E_RB);
		return (E_RA);
	}
	if (y_insert_idx > rx_times)
		return (E_RA);
	return (E_RB);
}