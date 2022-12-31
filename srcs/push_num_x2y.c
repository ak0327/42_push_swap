/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_num_x2y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:39:37 by takira            #+#    #+#             */
/*   Updated: 2022/12/28 14:39:39 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

/* prototype declaration*/
static void	push_num_rx_ry(t_info *info, t_push_stk op_stk);
static void	push_num_rx_rry(t_info *info, t_push_stk op_stk);
static void	push_num_rrx_ry(t_info *info, t_push_stk op_stk);
static void	push_num_rrx_rry(t_info *info, t_push_stk op_stk);

/* function */
void	push_num_x2y(t_info *info, int n, t_push_stk op_stk, t_op_type op_type)
{
	get_cost_params(info, n, op_stk);
	if (op_type == E_RX_RY)
		push_num_rx_ry(info, op_stk);
	else if (op_type == E_RX_RRY)
		push_num_rx_rry(info, op_stk);
	else if (op_type == E_RRX_RY)
		push_num_rrx_ry(info, op_stk);
	else
		push_num_rrx_rry(info, op_stk);
	if (op_stk == E_PUSH_A2B)
		operation_controller(info, E_PB);
	else
		operation_controller(info, E_PA);
}

static void	push_num_rx_ry(t_info *info, t_push_stk op_stk)
{
	size_t rr_times;
	size_t ri_times;
	t_op rx_cmd;
	t_op ry_cmd;

	rr_times = minsize(info->cost_m->out_idx, info->cost_m->in_idx);
	ri_times = maxsize(info->cost_m->out_idx, info->cost_m->in_idx) - rr_times;
	rx_cmd = E_RA;
	ry_cmd = E_RB;
	if (op_stk == E_PUSH_B2A)
	{
		rx_cmd = E_RB;
		ry_cmd = E_RA;
	}
	while (rr_times--)
		operation_controller(info, E_RR);
	if (ri_times && info->cost_m->out_idx > info->cost_m->in_idx)
		while (ri_times--)
			operation_controller(info, rx_cmd);
	else if (ri_times && info->cost_m->out_idx < info->cost_m->in_idx)
		while (ri_times--)
			operation_controller(info, ry_cmd);
}

static void	push_num_rx_rry(t_info *info, t_push_stk op_stk)
{
	t_op	rx_cmd;
	t_op	rry_cmd;
	size_t	rx_times;
	size_t	rry_times;

	rx_cmd = E_RA;
	rry_cmd = E_RRB;
	if (op_stk == E_PUSH_B2A)
	{
		rx_cmd = E_RB;
		rry_cmd = E_RRA;
	}
	rx_times = info->cost_m->out_idx;
	rry_times = info->cost_m->in_frm_bottom;
	while (rx_times--)
		operation_controller(info, rx_cmd);
	while (rry_times--)
		operation_controller(info, rry_cmd);
}

static void	push_num_rrx_ry(t_info *info, t_push_stk op_stk)
{
	t_op	rrx_cmd;
	t_op	ry_cmd;
	size_t	rrx_times;
	size_t	ry_times;

	rrx_cmd = E_RRA;
	ry_cmd = E_RB;
	if (op_stk == E_PUSH_B2A)
	{
		rrx_cmd = E_RRB;
		ry_cmd = E_RA;
	}
	rrx_times = info->cost_m->out_frm_bottom;
	ry_times = info->cost_m->in_idx;
	while (rrx_times--)
		operation_controller(info, rrx_cmd);
	while (ry_times--)
		operation_controller(info, ry_cmd);
}

static void	push_num_rrx_rry(t_info *info, t_push_stk op_stk)
{
	size_t	rrr_times;
	size_t	rri_times;
	t_op	rrx_cmd;
	t_op	rry_cmd;

	rrr_times = \
	minsize(info->cost_m->out_frm_bottom, info->cost_m->in_frm_bottom);
	rri_times = \
	maxsize(info->cost_m->out_frm_bottom, info->cost_m->in_frm_bottom);
	rri_times -= rrr_times;
	rrx_cmd = E_RRA;
	rry_cmd = E_RRB;
	if (op_stk == E_PUSH_B2A)
	{
		rrx_cmd = E_RRB;
		rry_cmd = E_RRA;
	}
	while (rrr_times--)
		operation_controller(info, E_RRR);
	if (rri_times && info->cost_m->out_frm_bottom > info->cost_m->in_frm_bottom)
		while (rri_times--)
			operation_controller(info, rrx_cmd);
	if (rri_times && info->cost_m->out_frm_bottom < info->cost_m->in_frm_bottom)
		while (rri_times--)
			operation_controller(info, rry_cmd);
}
