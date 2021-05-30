/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:22:31 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/30 15:48:13 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_find_pos(t_link *link, t_info *info)
{
	while (link)
	{
		if (link->val == info->min)
			break ;
		info->pos++;
		link = link->next;
	}
}

void	algo_find_min(t_link *link, t_info *info)
{
	info->min = link->val;
	while (link)
	{
		if (link->next)
		{
			if (info->min > link->next->val)
				info->min = link->next->val;
			else
				info->min = info->min;
		}
		link = link->next;
	}
}

void	algo_find_max(t_link *link, t_info *info)
{
	info->max = link->val;
	while (link)
	{
		if (link->next)
		{
			if (info->max < link->next->val)
				info->max = link->next->val;
			else
				info->max = info->max;
		}
		link = link->next;
	}
}

void	algo_pivot(t_link *link, t_info *info)
{
	algo_find_min(link, info);
	algo_find_max(link, info);
	info->pivot = ((info->min + info->max) / 2);
}
