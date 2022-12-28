/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:41:36 by takira            #+#    #+#             */
/*   Updated: 2022/12/25 20:41:36 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int	max_int(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	min_int(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

size_t	get_min_in_four_nums(size_t x, size_t y, size_t z, size_t n)
{
	return (minsize(minsize(minsize(x, y), z), n));
}

void	free_allocs(t_info *info)
{
	if (info)
	{
		free(info->cost_m);
		free(info->sorted_array_m);
		ft_stack_clear(&info->stk_a);
		cmd_list_clear(&info->op_list);
		free(info);
	}
}

void	free_and_exit_with_msg_fd(t_info *info, int exit_no, char *msg, int fd)
{
	free_allocs(info);
	if (msg)
		ft_putstr_fd(msg, fd);
	exit(exit_no);
}
