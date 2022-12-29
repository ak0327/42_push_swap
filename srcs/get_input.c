/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:09:31 by takira            #+#    #+#             */
/*   Updated: 2022/12/29 17:09:32 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

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
