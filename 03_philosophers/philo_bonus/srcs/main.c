/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:34:36 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/16 16:45:34 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	free_philo(t_info *info)
{

}

int	main(int ac, char *av[])
{
	t_info	info;

	memset(&info, 0, sizeof(info));
	if (init_philo(&info, ac, av))
		return (1);
	if (init_thread(&info))
		return (1);
	free_philo(&info);
	return (0);
}
