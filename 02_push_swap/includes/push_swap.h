/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:15:14 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/28 17:23:52 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "push_swap_struct.h"
# include "push_swap_op.h"
# include "push_swap_utils.h"
# include "push_swap_algo.h"

int		main(int ac, char *av[]);

t_link	*ps_start(char *av[], t_info *info);

#endif
