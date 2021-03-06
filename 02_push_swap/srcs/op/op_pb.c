/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:31:38 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/30 16:30:44 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pb(t_link **a, t_link **b, t_info *info)
{
	if (!info->a_size)
		return ;
	if (!(*b))
		*b = new_link_head(0, (*a)->val);
	else
	{
		(*b)->prev = new_link_head(*b, (*a)->val);
		*b = (*b)->prev;
	}
	delete_link(a);
	info->a_size--;
	info->b_size++;
}
