/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:13:48 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/30 17:36:45 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_init(t_link **a, t_link **b, t_info *info)
{
	// if (info->a_size < 20)
	// 	algo_less(a, b, info);
	// else
	algo_a_to_b(a, b, info);
}
