/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:12:09 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/25 00:13:57 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_lst **a)
{
	t_lst	*node;
	t_lst	*node_prev;
	t_lst	*new_node;
	long	tmp;

	node = *a;
	if (node)
	{
		if (node->prev)
		{
			tmp = node->val;
			node_prev =
		}
	}
	node = *a;


}

void	op_rb(t_lst **b)
{

}

void	op_rr(t_lst **a, t_lst **b)
{
	op_ra(*a);
	op_rb(*b);
}
