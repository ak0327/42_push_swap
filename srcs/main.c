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

void	test_operate(t_info *info)
{
	print_stacks_val_and_ptr(info, "00. initial");

	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "1 E_PA");
	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "1 E_PA");
//	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "1 E_PA");
//	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "2 E_PA");
//	operation_controller(info, E_PB);
//	print_stacks_val_and_ptr(info, "3 E_PB");


	operation_controller(info, E_SA);
//	print_stacks_val_and_ptr(info, "4 E_SA");
	operation_controller(info, E_SB);
//	print_stacks_val_and_ptr(info, "5 E_SB");
	operation_controller(info, E_SS);
//	print_stacks_val_and_ptr(info, "6 E_SS");

//	operation_controller(info, E_RA);
//	print_stacks_val_and_ptr(info, "7 E_RA");
//	operation_controller(info, E_RB);
//	print_stacks_val_and_ptr(info, "8 E_RB");
//	operation_controller(info, E_RR);
//	print_stacks_val_and_ptr(info, "9 E_RR");

//	operation_controller(info, E_RRA);
//	print_stacks_val_and_ptr(info, "10 E_RRA");
//	operation_controller(info, E_RRB);
//	print_stacks_val_and_ptr(info, "11 E_RRB");
//	operation_controller(info, E_RRR);
//	print_stacks_val_and_ptr(info, "12 E_RRR");


//
//	operation_controller(info, E_SA);
//	print_stacks_val_and_ptr(info, "01. swap a");
//
//	operation_controller(info, E_SA);
//	print_stacks_val_and_ptr(info, "02. swap a");
//
//	operation_controller(info, E_SA);
//	print_stacks_val_and_ptr(info, "03. swap a");
//
//	operation_controller(info, E_SA);
//	print_stacks_val_and_ptr(info, "04. swap a");
//
//	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "05. push a->b");
//
//	operation_controller(info, E_PB);
//	print_stacks_val_and_ptr(info, "06. push a<-b");
//
//	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "07. push a->b");
//
//	operation_controller(info, E_PB);
//	print_stacks_val_and_ptr(info, "08. push a<-b");
//
//	operation_controller(info, E_SB);
//	print_stacks_val_and_ptr(info, "09. swap b");
//
//	operation_controller(info, E_SB);
//	print_stacks_val_and_ptr(info, "10. swap b");
//
//	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "11. push a->b");
//
//	operation_controller(info, E_SB);
//	print_stacks_val_and_ptr(info, "12. swap b");
//
//	operation_controller(info, E_PB);
//	print_stacks_val_and_ptr(info, "13. push a<-b");
//
//	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "14. push a->b");
//
//	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "14. push a->b");
//
//	operation_controller(info, E_SB);
//	print_stacks_val_and_ptr(info, "15. swap b");
//
//	operation_controller(info, E_SB);
//	print_stacks_val_and_ptr(info, "16. swap b");
//
//	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "17. push a->b");
//
//	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "18. push a->b");
//
//	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "19. push a->b");
//
//	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "20. push a->b");
//
//	operation_controller(info, E_RB);
//	print_stacks_val_and_ptr(info, "21. rot b");
//
//	operation_controller(info, E_RB);
//	print_stacks_val_and_ptr(info, "22. rot b");
//
//	operation_controller(info, E_RB);
//	print_stacks_val_and_ptr(info, "23. rot b");
//
//	operation_controller(info, E_RB);
//	print_stacks_val_and_ptr(info, "24. rot b");
//
//	operation_controller(info, E_RB);
//	print_stacks_val_and_ptr(info, "25. rot b");
//
//	operation_controller(info, E_RA);
//	print_stacks_val_and_ptr(info, "26. rot a");
//
//	operation_controller(info, E_RA);
//	print_stacks_val_and_ptr(info, "27. rot a");
//
//	operation_controller(info, E_RRB);
//	print_stacks_val_and_ptr(info, "28. rev rot b");
//
//	operation_controller(info, E_RRB);
//	print_stacks_val_and_ptr(info, "29. rev rot b");
//
//	operation_controller(info, E_RRA);
//	print_stacks_val_and_ptr(info, "29. rev rot a");
//
//	operation_controller(info, E_PB);
//	print_stacks_val_and_ptr(info, "30. push a<-b");
//
//	operation_controller(info, E_RR);
//	print_stacks_val_and_ptr(info, "31. rr");
//
//	operation_controller(info, E_RRR);
//	print_stacks_val_and_ptr(info, "32. rrr");
//
//	operation_controller(info, E_PB);
//	print_stacks_val_and_ptr(info, "33. push a<-b");
//
//	operation_controller(info, E_PB);
//	print_stacks_val_and_ptr(info, "34. push a<-b");
//
//	operation_controller(info, E_PB);
//	print_stacks_val_and_ptr(info, "35. push a<-b");
//
//	operation_controller(info, E_PB);
//	print_stacks_val_and_ptr(info, "36. push a<-b");
//
//	operation_controller(info, E_RR);
//	print_stacks_val_and_ptr(info, "37. rr");
//
//	operation_controller(info, E_RR);
//	print_stacks_val_and_ptr(info, "38. rr");
//
//	operation_controller(info, E_RRR);
//	print_stacks_val_and_ptr(info, "39. rrr");
//
//	operation_controller(info, E_RRR);
//	print_stacks_val_and_ptr(info, "40. rrr");
//
//	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "41. push a->b");
//
//	operation_controller(info, E_SS);
//	print_stacks_val_and_ptr(info, "42. ss");
//
//	operation_controller(info, E_SS);
//	print_stacks_val_and_ptr(info, "42. ss");
//
//	operation_controller(info, E_PA);
//	print_stacks_val_and_ptr(info, "43. push a->b");
//
//	operation_controller(info, E_SS);
//	print_stacks_val_and_ptr(info, "44. ss");
//
//	operation_controller(info, E_SS);
//	print_stacks_val_and_ptr(info, "45. ss");
}

/* stack a, b */
// add_elem_to_stack, add_left, add_elem_to_stack_left
// pop_elem_to_stack, pop_left, pop_elem_from_stack_left
// clear_stack
// print_stacks

/* operate func */
// sa, sb, ss		Swap the 2 elements at the top ot stack x
// pa, pb			Push to x
// ra, rb, rr		Shift up; rotate
// rra, rrb, rrr	Shift down; reverse rotate

void	init_calc_cost_params(t_info *info)
{
	info->cost->push_num = 0;
	info->cost->is_sort_a2z = 0;
	info->cost->shift_type = E_RX_RY;
	info->cost->out_idx = 0;
	info->cost->in_idx = 0;
	info->cost->out_from_bottom = 0;
	info->cost->in_from_bottom = 0;
	info->cost->size_x = 0;
	info->cost->size_y = 0;
	info->cost->cost_rx_ry = 0;
	info->cost->cost_rx_rry = 0;
	info->cost->cost_rrx_ry = 0;
	info->cost->cost_rrx_rry = 0;
}

t_info	*init_params(int argc)
{
	t_info		*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->stk_a = NULL;
	info->stk_b = NULL;
	info->op_list = NULL;
	info->num_cnt = (size_t)argc - 1;
	info->sorted_array = NULL;
	info->is_sorted = true;
	info->cost = (t_cost *)malloc(sizeof(t_cost));
	if (!info->cost)
	{
		free(info);
		return (NULL);
	}
	init_calc_cost_params(info);
	return (info);
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
		{
			ft_putendl_fd("[Error] Invalid argument.", STDERR_FILENO);
			return (FAIL);
		}
		new_elem = create_stack_elem(input_num);
		if (!new_elem)
		{
			ft_stack_clear(&info->stk_a);
			return (3);
		}
		add_right(new_elem, &info->stk_a);
		i++;
	}
	return (PASS);
}

int main(int argc, char **argv)
{
	setvbuf(stdout, (char *)NULL, _IONBF, 0);

	t_info	*info;

	// valid argc
	if (argc == 1)
	{
		ft_putendl_fd("[Error] Invalid argument.", STDERR_FILENO);
		return (1);
	}

	info = init_params(argc);
	if (!info)
		return (2);
	get_input_nums(&argv, info);

//	print_stacks(info, "test");

	// test each operation
//	test_operate(info);
//	print_cmd_list_with_msg(info->op_list, "test");
//	print_stacks(info, "test");


	// compress and check_args(); <- sort()
	info->sorted_array = get_sorted_array(info);
	if (!info->sorted_array)
		return (3);
	if (info->is_sorted)
	{
		ft_putendl_fd("[Error] Already sorted.", STDERR_FILENO);
		return (4);
	}
//	print_num_array(info->sorted_array, info->num_cnt, "sorted");

	// valid input;
	if (!check_arg_valid(info))
	{
		ft_putendl_fd("[Error] Same value exists.", STDERR_FILENO);
		return (5);
	}
	// compress dimension
	get_compressed_dimension(info);
//	print_stacks(info, "Compressed");

	// exec_sort()
//	print_stacks(info, "before exec sort");

	exec_sort(info);
//	print_stacks(info, "after exec sort");
//	print_cmd_list_with_msg(info->op_list, "after_sort");

//	printf("before opt\n");
//	print_cmd_list(info->op_list, false);

	optimize_cmd(info);

//	printf("\nafter opt\n");
	print_cmd_list(info->op_list, false);

	// free()
//	free(sorted_array);//TODO: cmd_list, stack
	return (0);
}
