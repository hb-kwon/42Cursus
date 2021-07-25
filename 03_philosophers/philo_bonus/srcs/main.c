/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:34:36 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/25 20:22:36 by kwonhyukbae      ###   ########.fr       */
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
	if (init_sem(&info))
		return (1);
	free_philo(&info);
	return (0);
}
