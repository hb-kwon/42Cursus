/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:50:59 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/01 05:04:55 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		algo_check_big(t_link *link, long pivot)
{
	while (link)
	{
		if (link->val <= pivot)
			return (0);
		link = link->next;
	}
	return (1);
}

void	algo_init_flag_a(t_link **a, t_info *info, int flag[7], int cnt)
{
	algo_pivot(*a, info, cnt);
	ft_memset(flag, 0, sizeof(int) * 6);
	if (cnt == info->a_size)
		flag[F_FL] = 1;
	flag[F_RA] = 0;
	flag[F_PB] = 0;
}

void	algo_rotate_a(t_link **a, t_link **b, t_info *info, int flag[7])
{
	flag[F_I] = flag[F_RA];
	while (flag[F_I] && !flag[F_FL])
	{
		exec_op(a, b, info, RRA);
		flag[F_I]--;
	}
}

void	algo_a_to_b(t_link **a, t_link **b, t_info *info, int cnt)
{
	int		flag[7];

	if (escape_a(a, b, info, cnt))
		return ;
	algo_init_flag_a(a, info, flag, cnt);
	while (cnt > 0)
	{
		if ((*a)->val > info->pivot)
		{
			if (algo_check_big(*a, info->pivot))
				break ;
			exec_op(a, b, info, RA);
			flag[F_RA]++;
		}
		else
		{
			exec_op(a, b, info, PB);
			flag[F_PB]++;
		}
		cnt--;
	}
	algo_rotate_a(a, b, info, flag);
	algo_a_to_b(a, b, info, flag[F_RA] + cnt);
	algo_b_to_a(a, b, info, flag[F_PB]);
}
