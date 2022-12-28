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

static size_t	bubble_sort(int **array, size_t elem_cnt)
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
	int		*array_m;
	size_t	idx;
	t_stack	*stk;
	size_t	swap_times;

	if (!info)
		return (NULL);
	array_m = (int *)ft_calloc(sizeof(int), info->num_cnt + 1);
	if (!array_m)
		return (NULL);
	stk = info->stk_a;
	idx = 0;
	while (stk)
	{
		array_m[idx] = stk->raw_value;
		stk = stk->next;
		idx++;
	}
	swap_times = bubble_sort(&array_m, info->num_cnt);
	if (swap_times > 0)
		info->is_sorted = false;
	return (array_m);
}

int	check_arg_valid(t_info *info)
{
	size_t	i;

	i = 0;
	while (i + 1 < info->num_cnt)
	{
		if (info->sorted_array_m[i] == info->sorted_array_m[i + 1])
			return (FAIL);
		i++;
	}
	return (PASS);
}

static int	get_sorted_idx(const int *sorted_arr, int search_num)
{
	int	idx;

	idx = 0;
	while (sorted_arr[idx] != search_num)
		idx++;
	return (idx);
}

void	compress_dimension(t_info *info)
{
	t_stack	*elem;

	if (!info)
		return ;
	elem = info->stk_a;
	while (elem)
	{
		elem->val = get_sorted_idx(info->sorted_array_m, elem->raw_value);
		elem = elem->next;
	}
}
