/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:37:17 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/18 03:43:46 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map_flag_check(int start, int tid, unsigned char *flag, char *line)
{
	if (((*flag) >> tid & 1) == 1)
		return (-1);
	while (line[start] == ' ')
		start++;
	(*flag) |= 1 << tid;
	return (start);
}

int		map_check_news(t_cub *c, char *line, unsigned char *flag, int i)
{
	if (ft_strncmp(line, "NO", 3))
	{
		if ((i = map_flag_check(3, NO, flag, line)) < 0)
			return (err_msg("north overlap"));
		c->tid.no_path = ft_strdup(line + i);
	}
	if (ft_strncmp(line, "SO", 3))
	{
		if ((i = map_flag_check(3, SO, flag, line)) < 0)
			return (err_msg("south overlap"));
		c->tid.so_path = ft_strdup(line + i);
	}
	if (ft_strncmp(line, "WE", 3))
	{
		if ((i = map_flag_check(3, WE, flag, line)) < 0)
			return (err_msg("west overlap"));
		c->tid.we_path = ft_strdup(line + i);
	}
	if (ft_strncmp(line, "EA", 3))
	{
		if ((i = map_flag_check(3, EA, flag, line)) < 0)
			return (err_msg("east overlap"));
		c->tid.ea_path = ft_strdup(line + i);
	}
	return (1);
}

int		map_check_sfc(t_cub *c, char *line, unsigned char *flag, int i)
{
	if (ft_strncmp(line, "S", 2))
	{
		if ((i = map_flag_check(2, SP, flag, line)) < 0)
			return (err_msg("sprite overlap"));
		c->tid.sp_path = ft_strdup(line + i);
	}
	if (ft_strncmp(line, "F", 2))
	{
		if ((i = map_flag_check(2, EA, flag, line)) < 0)
			return (err_msg("floor overlap"));
		if (!map_floor(c, line + i))
			return (0);
	}
	if (ft_strncmp(line, "C", 2))
	{
		if ((i = map_flag_check(2, CE, flag, line)) < 0)
			return (err_msg("ceiling overlap"));
		if (!map_ceiling(c, line + i))
			return (0);
	}
	return (1);
}

int		map_check_re(t_cub *c, char *line, unsigned char *flag, int i)
{
	if (ft_strncmp(line, "R", 2))
	{
		if ((i = map_flag_check(2, RE, flag, line)) < 0)
			return (err_msg("resolution overlap"));
		if ((c->tid.s_width = ft_atoi(line + i)) < 0)
			return (err_msg("resoltion width error"));
		i += ft_count(c->tid.s_width);
		if ((c->tid.s_height = ft_atoi(line + i)) < 0)
			return (err_msg("resoltion height error"));
		map_resolution(c);
	}
	return (1);
}

int		map_check(t_cub *c, int fd, char **line)
{
	int				i;
	int				res;
	unsigned char	flag;

	flag = 0;
	i = 0;
	while (flag != 255 && (res = get_next_line(fd, line)) > 0)
	{
		if (!map_check_news(c, *line, &flag, i))
			return (0);
		else if (!map_check_sfc(c, *line, &flag, i))
			return (0);
		else if (!map_check_re(c, *line, &flag, i))
			return (0);
		if (*line)
			free(*line);
	}
	if (res <= 0)
		return (0);
	return (1);
}