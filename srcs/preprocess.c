/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:37:05 by takira            #+#    #+#             */
/*   Updated: 2022/12/24 11:37:08 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

size_t	bubble_sort(int **array, size_t elem_cnt)
{
	size_t	i;
	size_t	j;
	int		tmp_num;
	size_t	swap_times;

	i = 0;
	swap_times = 0;
	while (i < elem_cnt)
	{
		j = i + 1;
		while (j < elem_cnt)
		{
			if ((*array)[i] > (*array)[j])
			{
				tmp_num = (*array)[i];
				(*array)[i] = (*array)[j];
				(*array)[j] = tmp_num;
				swap_times++;
			}
			j++;
		}
		i++;
	}
	return (swap_times);
}

int	*get_sorted_array(t_info *info)
{
	int		*array;
	size_t	idx;
	t_stack	*stk;
	size_t	swap_times;

	if (!info)
		return (NULL);
	array = (int *)ft_calloc(sizeof(int), info->num_cnt + 1);
	if (!array)
		return (NULL);
	stk = info->stk_a;
	idx = 0;
	while (stk)
	{
		array[idx] = stk->raw_value;
		stk = stk->next;
		idx++;
	}
//	print_num_array(array, info->num_cnt, "before");
	swap_times = bubble_sort(&array, info->num_cnt);
	if (swap_times > 0)
		info->is_sorted = false;
	return (array);
}

bool	check_arg_valid(t_info *info)
{
	size_t	i;

	i = 0;
	while (i + 1 < info->num_cnt)
	{
		if (info->sorted_array[i] == info->sorted_array[i + 1])
			return (false);
		i++;
	}
	return (true);
}

int	get_sorted_idx(const int *sorted_arr, int search_num)
{
	int	idx;

	idx = 0;
	while (sorted_arr[idx] != search_num)
		idx++;
	return (idx);
}

void	get_compressed_dimension(t_info *info)
{
	t_stack	*elem;

	if (!info)
		return ;
	elem = info->stk_a;
	while (elem)
	{
		elem->val = get_sorted_idx(info->sorted_array, elem->raw_value);
		elem = elem->next;
	}
}
