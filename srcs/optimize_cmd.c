/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:09:05 by takira            #+#    #+#             */
/*   Updated: 2022/12/27 19:09:06 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

static int	optimize_op_s(t_op_list **list);
static int	optimize_op_r(t_op_list **list);
static int	optimize_op_rr(t_op_list **list);

void	optimize_cmd(t_info *info)
{
	while (true)
	{
		if (!optimize_op_s(&info->op_list) \
		&& !optimize_op_r(&info->op_list) \
		&& !optimize_op_rr(&info->op_list))
			break ;
	}
}

static int	optimize_op_s(t_op_list **list)
{
	int			is_optimized;
	t_op_list	*ptr;
	t_op_list	*tmp_next_next;

	is_optimized = false;
	if (!list || !*list)
		return (is_optimized);
	ptr = *list;
	while (ptr && ptr->next)
	{
		if ((ptr->cmd == E_SA && ptr->next->cmd == E_SB) \
			|| (ptr->cmd == E_SB && ptr->next->cmd == E_SA))
		{
			ptr->cmd = E_SS;
			tmp_next_next = ptr->next->next;
			free(ptr->next);
			ptr->next = tmp_next_next;
			is_optimized = true;
		}
		ptr = ptr->next;
	}
	return (is_optimized);
}

static int	optimize_op_r(t_op_list **list)
{
	int			is_optimized;
	t_op_list	*ptr;
	t_op_list	*tmp_next_next;

	is_optimized = false;
	if (!list || !*list)
		return (is_optimized);
	ptr = *list;
	while (ptr && ptr->next)
	{
		if ((ptr->cmd == E_RA && ptr->next->cmd == E_RB) \
			|| (ptr->cmd == E_RB && ptr->next->cmd == E_RA))
		{
			ptr->cmd = E_RR;
			tmp_next_next = ptr->next->next;
			free(ptr->next);
			ptr->next = tmp_next_next;
			is_optimized = true;
		}
		ptr = ptr->next;
	}
	return (is_optimized);
}

static int	optimize_op_rr(t_op_list **list)
{
	int			is_optimized;
	t_op_list	*ptr;
	t_op_list	*tmp_next_next;

	is_optimized = false;
	if (!list || !*list)
		return (is_optimized);
	ptr = *list;
	while (ptr && ptr->next)
	{
		if ((ptr->cmd == E_RRA && ptr->next->cmd == E_RRB) \
			|| (ptr->cmd == E_RRB && ptr->next->cmd == E_RRA))
		{
			ptr->cmd = E_RRR;
			tmp_next_next = ptr->next->next;
			free(ptr->next);
			ptr->next = tmp_next_next;
			is_optimized = true;
		}
		ptr = ptr->next;
	}
	return (is_optimized);
}
