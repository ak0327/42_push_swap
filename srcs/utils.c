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

int max_int(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int min_int(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

