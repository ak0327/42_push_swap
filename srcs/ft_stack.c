/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:19:29 by takira            #+#    #+#             */
/*   Updated: 2022/12/20 09:19:31 by takira           ###   ########.fr       */
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

void	add_left(t_stack *elem, t_stack **stk)
{
	if (!stk)
		return ;
	elem->prev = NULL;
	elem->next = *stk;
	if (*stk)
		(*stk)->prev = elem;
	*stk = elem;
}

void	add_right(t_stack *elem, t_stack **stk)
{
	t_stack	*last_elem;

	if (!stk)
		return ;
	if (!*stk)
	{
		*stk = elem;
		elem->next = NULL;
		elem->prev = NULL;
		return ;
	}
	last_elem = get_last_elem(*stk);
	last_elem->next = elem;
	elem->prev = last_elem;
	elem->next = NULL;
}

t_stack	*pop_left(t_stack **stk)
{
	t_stack	*first_elem;

	if (!stk || !*stk)
		return (NULL);
	first_elem = *stk;
	*stk = first_elem->next;
	if (first_elem->next)
		first_elem->next->prev = NULL;
	first_elem->prev = NULL;
	first_elem->next = NULL;
	return (first_elem);
}

t_stack	*pop_right(t_stack **stk)
{
	t_stack	*last_elem;

	if (!stk || !*stk)
		return (NULL);
	last_elem = get_last_elem(*stk);
	if (last_elem->prev)
		last_elem->prev->next = NULL;
	last_elem->prev = NULL;
	last_elem->next = NULL;
	return (last_elem);
}

size_t	get_stack_size(t_stack *stk)
{
	size_t	size;

	size = 0;
	while (stk)
	{
		stk = stk->next;
		size++;
	}
	return (size);
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

char	*get_cmd(t_op_cmd cmd)
{
	if (cmd == E_SA)
		return ("sa");
	if (cmd == E_SB)
		return ("sb");
	if (cmd == E_SS)
		return ("ss");
	if (cmd == E_PA)
		return ("pa");
	if (cmd == E_PB)
		return ("pb");
	if (cmd == E_RA)
		return ("ra");
	if (cmd == E_RB)
		return ("rb");
	if (cmd == E_RR)
		return ("rr");
	if (cmd == E_RRA)
		return ("rra");
	if (cmd == E_RRB)
		return ("rrb");
	if (cmd == E_RRR)
		return ("rrr");
	return ("Not Exist");
}
