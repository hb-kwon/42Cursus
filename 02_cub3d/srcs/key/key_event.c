/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 01:58:33 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/15 01:51:32 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		event_key_press(int keycode, t_cub *c)
{
	if (keycode == KEY_W)
		c->key.key_w = 1;
	if (keycode == KEY_A)
		c->key.key_a = 1;
	if (keycode == KEY_S)
		c->key.key_s = 1;
	if (keycode == KEY_D)
		c->key.key_d = 1;
	if (keycode == KEY_LEFT)
		c->key.key_left = 1;
	if (keycode == KEY_RIGHT)
		c->key.key_right = 1;
	// if (keycode == KEY_UP)
	// 	c->key.key_up = 1;
	// if (keycode == KEY_DOWN)
	// 	c->key.key_down = 1;
	if (keycode == KEY_ESC)
		c_exit(c, SUCESS);
	return (0);
}

int		event_key_release(int keycode, t_cub *c)
{
	if (keycode == KEY_W)
		c->key.key_w = 0;
	if (keycode == KEY_A)
		c->key.key_a = 0;
	if (keycode == KEY_S)
		c->key.key_s = 0;
	if (keycode == KEY_D)
		c->key.key_d = 0;
	if (keycode == KEY_LEFT)
		c->key.key_left = 0;
	if (keycode == KEY_RIGHT)
		c->key.key_right = 0;
	// if (keycode == KEY_UP)
	// 	c->key.key_up = 0;
	// if (keycode == KEY_DOWN)
	// 	c->key.key_down = 0;
	return (0);
}

int		event_exit(int keycode, t_cub *c)
{
	exit_cub(c, SUCESS);
	return (0);
}
