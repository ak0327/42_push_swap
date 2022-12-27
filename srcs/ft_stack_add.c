/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:28:00 by takira            #+#    #+#             */
/*   Updated: 2022/12/27 18:28:01 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

t_stack	*create_stack_elem(int num)
{
	t_stack	*new_elem;

	new_elem = (t_stack *)malloc(sizeof(t_stack));
	if (!new_elem)
		return (NULL);
	new_elem->raw_value = num;
	new_elem->val = num;
	new_elem->prev = NULL;
	new_elem->next = NULL;
	return (new_elem);
}

t_stack	*get_last_elem(t_stack *elem)
{
	if (!elem)
		return (NULL);
	while (elem->next)
		elem = elem->next;
	return (elem);
}

void	ft_stack_iter(t_stack *stk, void (*f)(void *))
{
	if (!stk)
		return ;
	while (stk)
	{
		(*f)(stk);
		stk = stk->next;
	}
}

void	ft_stack_clear(t_stack **stk)
{
	t_stack	*next;

	if (!stk)
		return ;
	while (*stk)
	{
		next = (*stk)->next;
		free(*stk);
		*stk = next;
	}
}
