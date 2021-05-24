/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:38:19 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/24 23:48:12 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_OP_H
# define PUSH_SWAP_OP_H

#include "push_sawp.h"

void	op_sa(t_lst *a);
void	op_sb(t_lst *b);
void	op_ss(t_lst *a, t_lst *b);

void	op_pa(t_lst **a, t_lst **b, t_info *info);
void	op_pb(t_lst **a, t_lst **b, t_info *info);

void	op_ra(t_lst **a, t_lst **b);
void	op_rb(t_lst **a, t_lst **b);
void	op_rr(t_lst **a, t_lst **b);

void	op_rra(t_lst **a, t_lst **b);
void	op_rrb(t_lst **a, t_lst **b);
void	op_rrr(t_lst **a, t_lst **b);

#endif
