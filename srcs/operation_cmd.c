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
	t_op_list	*new_node;
	t_op_list	*last;

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

size_t	get_oplist_size(t_op_list *list)
{
	size_t	size;

	size = 0;
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}

void	print_op_list(t_op_list *list, bool is_print_cnt)
{
	int	cnt;

	cnt = 0;
	while (list)
	{
		ft_printf("%s\n", get_cmd(list->cmd));
		list = list->next;
		cnt++;
	}
	if (is_print_cnt)
		ft_printf("cmd:%d\n", cnt);
}

void	cmd_list_clear(t_op_list **list)
{
	t_op_list	*next;

	if (!list)
		return ;
	while (*list)
	{
		next = (*list)->next;
		free(*list);
		*list = next;
	}
	*list = NULL;
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
