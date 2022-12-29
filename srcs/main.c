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


static int	exec_push_swap(t_info *info, char ***argv, t_init_push pattern)
{
	if (!info)
		return (FAIL);
	if (get_input_nums(argv, info) == FAIL)
		return (FAIL);
	info->sorted_array_m = get_sorted_array(info);
	if (!info->sorted_array_m)
		return (FAIL);
	if (info->is_already_sorted)
		return (ALREADY_SORTED);
	if (check_arg_valid(info) == FAIL)
		return (FAIL);
	compress_dimension(info);
	exec_sort(info, pattern);
	optimize_cmd(info);
	return (PASS);
}

int	main(int argc, char **argv)
{
	t_info	*info1;
	t_info	*info2;
	int		ret1;
	int 	ret2;
	int		exit_no;

	if (argc == 1)
		free_and_exit_with_msg_fd(NULL, EXIT_FAILURE, "Error\n", STDERR_FILENO);
	info1 = init_params(argc);
	info2 = init_params(argc);
	exit_no = EXIT_FAILURE;
	ret1 = exec_push_swap(info1, &argv, E_TOP);
	ret2 = exec_push_swap(info2, &argv, E_MIDDLE);
	if (ret1 == FAIL || ret2 == FAIL)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else if (ret1 == ALREADY_SORTED || ret2 == ALREADY_SORTED)
		exit_no = EXIT_SUCCESS;
	else
	{
		if (get_cmd_list_size(info1->op_list) <= get_cmd_list_size(info2->op_list))
			print_cmd_list(info1->op_list, false);
		else
			print_cmd_list(info2->op_list, false);
		exit_no = EXIT_SUCCESS;
	}
	free_allocs(info1);
	free_allocs(info2);
	return (exit_no);
}

#ifdef LESKS

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q push_swap");
}

#endif
