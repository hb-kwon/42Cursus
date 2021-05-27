/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:30:31 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/27 19:55:36 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sb(t_link **b, t_info *info)
{
	long	tmp;

	if (info->b_size < 2)
		return ;
	tmp = (*b)->val;
	(*b)->val = (*b)->prev->val;
	(*b)->prev->val = tmp;
	write(1, "sb\n", 3);
}
