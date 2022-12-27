/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 08:42:17 by takira            #+#    #+#             */
/*   Updated: 2022/12/20 08:42:18 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	operation_controller(t_info *info, t_op cmd)
{
	if (cmd == E_SA || cmd == E_SB)
		swap(info, cmd, true);
	if (cmd == E_SS)
		ss(info);
	if (cmd == E_PA || cmd == E_PB)
		push(info, cmd, true);
	if (cmd == E_RA || cmd == E_RB)
		rotate(info, cmd, true);
	if (cmd == E_RR)
		rr(info);
	if (cmd == E_RRA || cmd == E_RRB)
		reverse_rotate(info, cmd, true);
	if (cmd == E_RRR)
		rrr(info);
}
