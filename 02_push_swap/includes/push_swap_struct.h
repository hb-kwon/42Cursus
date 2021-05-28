/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 22:35:47 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/27 18:31:28 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STRUCT_H
# define PUSH_SWAP_STRUCT_H

typedef struct		s_link
{
	long			val;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_info
{
	int				max;
	int				min;
	int				a_size;
	int				b_size;
}					t_info;

#endif