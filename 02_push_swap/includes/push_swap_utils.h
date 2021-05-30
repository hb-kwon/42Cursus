/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:08:19 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/30 21:14:29 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include "push_swap_struct.h"

# define SA		0
# define SB		1
# define SS		2
# define RA		3
# define RB		4
# define RR		5
# define RRA	6
# define RRB	7
# define RRR	8
# define PA		9
# define PB		10

t_link	*move_link_head(t_link *link);
t_link	*move_link_tail(t_link *link);
t_link	*new_link_head(t_link *link, long value);
t_link	*new_link_tail(t_link *link, long value);
void	delete_link(t_link **link);

int		ps_check_overlap(t_link *link);
int		sort_check(t_link *link);
void	algo_pivot(t_link *link, t_info *info);
void	algo_find_pos(t_link *link, t_info *info);

void	exec_op(t_link **a, t_link **b, t_info *info, int op);

int		free_array(char ***array);
void	free_link(t_link **link);
void	free_exit(t_link **link);

#endif
