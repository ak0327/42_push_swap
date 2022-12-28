/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:37:12 by takira            #+#    #+#             */
/*   Updated: 2022/12/27 18:37:12 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	ss(t_info *info)
{
	swap(info, E_SA, false);
	swap(info, E_SB, false);
	if (add_cmd_to_list(&(info->op_list), E_SS) == FAIL)
		free_and_exit_with_msg_fd(info, EXIT_FAILURE, "Error\n", STDERR_FILENO);
}

void	rr(t_info *info)
{
	rotate(info, E_RA, false);
	rotate(info, E_RB, false);
	if (add_cmd_to_list(&info->op_list, E_RR) == FAIL)
		free_and_exit_with_msg_fd(info, EXIT_FAILURE, "Error\n", STDERR_FILENO);
}

void	rrr(t_info *info)
{
	reverse_rotate(info, E_RRA, false);
	reverse_rotate(info, E_RRB, false);
	if (add_cmd_to_list(&info->op_list, E_RRR) == FAIL)
		free_and_exit_with_msg_fd(info, EXIT_FAILURE, "Error\n", STDERR_FILENO);
}
