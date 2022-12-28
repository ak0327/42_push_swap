/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:20:54 by takira            #+#    #+#             */
/*   Updated: 2022/12/14 22:20:56 by takira           ###   ########.fr       */
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
	info_m->num_cnt = (size_t)argc - 1;
	info_m->sorted_array_m = NULL;
	info_m->is_sorted = true;
	info_m->cost_m = (t_cost *)malloc(sizeof(t_cost));
	if (!info_m->cost_m)
	{
		free(info_m);
		return (NULL);
	}
	init_calc_cost_params(info_m);
	return (info_m);
}

int	get_input_nums(char ***argv, t_info *info)
{
	bool	is_atoi_success;
	int		input_num;
	t_stack	*new_elem;
	size_t	i;

	i = 1;
	while ((*argv)[i])
	{
		input_num = ft_atoi((*argv)[i], &is_atoi_success);
		if (!is_atoi_success)
			return (FAIL);
		new_elem = create_stack_elem(input_num);
		if (!new_elem)
		{
			ft_stack_clear(&info->stk_a);
			return (FAIL);
		}
		add_right(new_elem, &info->stk_a);
		i++;
	}
	return (PASS);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = NULL;
	if (argc == 1)
		free_and_exit_with_msg_fd(info, EXIT_FAILURE, "Error\n", STDERR_FILENO);
	info = init_params(argc);
	if (!info)
		return (2);
	if (get_input_nums(&argv, info) == FAIL)
		free_and_exit_with_msg_fd(info, EXIT_FAILURE, "Error\n", STDERR_FILENO);
	info->sorted_array_m = get_sorted_array(info);
	if (!info->sorted_array_m)
		free_and_exit_with_msg_fd(info, EXIT_FAILURE, "Error\n", STDERR_FILENO);
	if (info->is_sorted)
		free_and_exit_with_msg_fd(info, EXIT_SUCCESS, "", STDOUT_FILENO);
	if (check_arg_valid(info) == FAIL)
		free_and_exit_with_msg_fd(info, EXIT_FAILURE, "Error\n", STDERR_FILENO);
	compress_dimension(info);
	exec_sort(info);
	optimize_cmd(info);
	print_cmd_list(info->op_list, false);
	free_allocs(info);
	return (EXIT_SUCCESS);
}
