/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_escape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:21:27 by hkwon             #+#    #+#       t_info,       */
/*   Updated: 2021/05/31 22:18:15 by hkwon            ###   ########.fr       */
/*                                                                            */
/* **********************************************************************t_info, **** */

#include "push_swap.h"

int		escape_a(t_link **a, t_link **b, t_info *info, int cnt)
{
	if (cnt == 1)
		;
	else if (cnt == 2)
	{
		if ((*a)->val > (*a)->next->val)
			exec_op(a, b, info, SA);
	}
	else if (cnt == 3)
		algo_handle_a(a, b, info);
	else if (sort_check_a(*a))
		;
	else
		return (0);
	return (1);
}

int		escape_b(t_link **a, t_link **b, t_info *info, int cnt)
{
	if (cnt == 1)
		exec_op(a, b, info, PA);
	else if (cnt == 2)
	{
		if ((*b)->val < (*b)->next->val)
			exec_op(a, b, info, SB);
		while (cnt--)
			exec_op(a, b, info, PA);
	}
	else if (cnt == 3)
	{
		algo_handle_b(a, b, info);
		while (cnt--)
			exec_op(a, b, info, PA);
	}
	else if (sort_check_b(*b))
	{
		while (cnt--)
			exec_op(a, b, info, PA);
	}
	else
		return (0);
	return (1);
}
