/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:01:15 by takira            #+#    #+#             */
/*   Updated: 2022/12/29 15:01:17 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* prototype declaration*/
static t_op get_operation_cmd(char *line);
static void	exec_sort_by_cmd(t_info *info);
static int	check_sorted(t_stack *stk);

/* function */
int	main(int argc, char **argv)
{
	t_info	*info;
	if (argc == 1)
		return (EXIT_FAILURE);
	info = init_params(argc);
	if (get_input_nums(&argv, info) == FAIL)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		free_allocs(info);
		return (EXIT_FAILURE);
	}
	info->sorted_array_m = get_sorted_array(info);
	if (check_arg_valid(info) == FAIL)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		free_allocs(info);
		return (EXIT_FAILURE);
	}
	compress_dimension(info);
	exec_sort_by_cmd(info);
	if (get_stack_size(info->stk_b) == 0 && check_sorted(info->stk_a) == PASS)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	print_stacks(info, "print");
	free_allocs(info);
	return (EXIT_SUCCESS);
}

static void	exec_sort_by_cmd(t_info *info)
{
	t_op	cmd;
	char	*line;

	while (true)
	{
		line = get_next_line(STDIN_FILENO, true);
		if (!line)
			break ;
		cmd = get_operation_cmd(line);
		if (cmd == E_ERROR)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			free_allocs(info);
			exit (EXIT_FAILURE);
		}
		operation_controller(info, cmd);
		free(line);
	}
	free(line);
}

static t_op get_operation_cmd(char *line)
{
	const char	*op_str[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", NULL};
	int			i;

	if (ft_strlen_ns(line) == 0)
		return (E_ERROR);
	i = 0;
	while (op_str[i])
	{
		if (ft_strncmp_ns(line, op_str[i], ft_strlen_ns(line)) == 0)
			return (i);
		i++;
	}
	return (E_ERROR);
}

static int	check_sorted(t_stack *stk)
{
	int	i;

	i = 0;
	while (stk)
	{
		if (stk->val != i)
			return (FAIL);
		i++;
		stk = stk->next;
	}
	return (PASS);
}

#ifdef LESKS

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q checker");
}

#endif
