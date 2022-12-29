/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:07:32 by takira            #+#    #+#             */
/*   Updated: 2022/12/29 17:07:32 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	init_calc_cost_params(t_info *info)
{
	info->cost_m->shift_type = E_RX_RY;
	info->cost_m->out_idx = 0;
	info->cost_m->in_idx = 0;
	info->cost_m->out_frm_bottom = 0;
	info->cost_m->in_frm_bottom = 0;
	info->cost_m->size_x = 0;
	info->cost_m->size_y = 0;
	info->cost_m->cost_rx_ry = 0;
	info->cost_m->cost_rx_rry = 0;
	info->cost_m->cost_rrx_ry = 0;
	info->cost_m->cost_rrx_rry = 0;
}

t_info	*init_params(int argc)
{
	t_info		*info_m;

	info_m = (t_info *)malloc(sizeof(t_info));
	if (!info_m)
		return (NULL);
	info_m->stk_a = NULL;
	info_m->stk_b = NULL;
	info_m->op_list = NULL;
	info_m->input_num_cnt = (size_t)argc - 1;
	info_m->sorted_array_m = NULL;
	info_m->is_already_sorted = true;
	info_m->cost_m = (t_cost *)malloc(sizeof(t_cost));
	if (!info_m->cost_m)
	{
		free(info_m);
		return (NULL);
	}
	init_calc_cost_params(info_m);
	return (info_m);
}
