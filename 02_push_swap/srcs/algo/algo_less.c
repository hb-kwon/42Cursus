/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:38:31 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/30 16:51:34 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_three_sort(t_link **a, t_link **b, t_info *info)
{
	if (sort_check(*a))
		return ;
	algo_pivot(*a, info);
	if ((*a)->val == info->min)
		exec_op(a, b, info, RRA);
	else if ((*a)->val == info->max)
		exec_op(a, b, info, RA);
	else
	{
		if ((*a)->next->val == info->min)
			exec_op(a, b, info, SA);
		else
			exec_op(a, b, info, RRA);
	}
	algo_three_sort(a, b, info);
}

void	algo_less(t_link **a, t_link **b, t_info *info)
{
	if (sort_check(*a))
		return ;
	while (info->a_size > 3)
	{
		algo_pivot(*a, info);
		algo_find_pos(*a, info);
		if (info->pos < info->a_size / 2)
		{
			while ((*a)->val != info->min)
				exec_op(a, b, info, RA);
		}
		else
		{
			while ((*a)->val != info->min)
				exec_op(a, b, info, RRA);
		}
		if (sort_check(*a))
			break ;
		else
			exec_op(a, b, info, PB);
	}
	algo_three_sort(a, b, info);
	while (info->b_size != 0)
		exec_op(a, b, info, PA);
}
