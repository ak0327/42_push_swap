/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:57:57 by takira            #+#    #+#             */
/*   Updated: 2022/12/27 18:58:00 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

size_t	calc_x2y_cost_controller(t_info *info, int push_num, t_push_stk op_stk)
{
	size_t	min_cost;

	get_cost_params(info, push_num, op_stk);
	info->cost_m->cost_rx_ry = calc_cost_rx_ry(info);
	info->cost_m->cost_rx_rry = calc_cost_rx_rry(info);
	info->cost_m->cost_rrx_ry = calc_cost_rrx_ry(info);
	info->cost_m->cost_rrx_rry = calc_cost_rrx_rry(info);
	min_cost = get_min_in_four_nums(info->cost_m->cost_rx_ry, \
	info->cost_m->cost_rx_rry, \
	info->cost_m->cost_rrx_ry, \
	info->cost_m->cost_rrx_rry);
	if (min_cost == info->cost_m->cost_rx_ry)
		info->cost_m->shift_type = E_RX_RY;
	else if (min_cost == info->cost_m->cost_rx_rry)
		info->cost_m->shift_type = E_RX_RRY;
	else if (min_cost == info->cost_m->cost_rrx_ry)
		info->cost_m->shift_type = E_RRX_RY;
	else
		info->cost_m->shift_type = E_RRX_RRY;
	return (min_cost);
}
