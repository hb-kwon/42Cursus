/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:12:09 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/26 22:09:56 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_link **a, t_info *info)
{
	t_link	*link;
	long	tmp;

	if (info->a_size < 0)
		return ;
	tmp = (*a)->val;
	link = move_stat(*a);
	link->prev = new_lst_head(link, tmp);
	delete_lst(a);
}
