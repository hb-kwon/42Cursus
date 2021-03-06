/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:05:18 by hkwon             #+#    #+#             */
/*   Updated: 2021/03/03 23:39:53 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_apply_zero(char *n_str, int len, t_format *op)
{
	int		s_len;
	int		n_len;
	char	*res;

	s_len = ft_strlen(n_str);
	n_len = s_len - op->sign;
	if (len == 0)
		return (ft_strdup(""));
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memset(res, '0', len);
	ft_memcpy(res + len - n_len, n_str + op->sign, n_len);
	if (op->sign)
		res[0] = '-';
	res[len] = '\0';
	return (res);
}

static int	ft_calc_width(char *n_str, t_format *op)
{
	int		len;

	len = ft_strlen(n_str);
	if (*n_str == '-')
		op->sign = 1;
	if (op->prec < 0 && op->zero && op->width > len)
		len = op->width;
	if (op->prec == 0 && *n_str == '0' && len == 1)
		len = 0;
	if (op->prec > len - op->sign)
		len = op->prec + op->sign;
	return (len);
}

static int	ft_print_res(char *tmp, int len, t_format *op)
{
	char	*res;
	int		cnt;

	if (!(res = (char *)malloc(sizeof(char) * (op->width + 1))))
		return (-1);
	if (op->prec < 0 && op->zero && !op->left)
	{
		ft_memset(res, '0', op->width);
		ft_memcpy(res + op->width - len, tmp, len);
	}
	else if (!op->left)
	{
		ft_memset(res, ' ', op->width);
		ft_memcpy(res + op->width - len, tmp, len);
	}
	else
	{
		ft_memset(res, ' ', op->width);
		ft_memcpy(res, tmp, len);
	}
	res[op->width] = '\0';
	cnt = ft_putstr(res);
	free(res);
	return (cnt);
}

int			ft_print_int(va_list ap, t_format *op)
{
	char	*n_str;
	char	*tmp;
	int		len;
	int		cnt;

	n_str = ft_itoa(va_arg(ap, int));
	len = ft_calc_width(n_str, op);
	tmp = ft_apply_zero(n_str, len, op);
	len = ft_strlen(tmp);
	if (len > op->width)
		op->width = len;
	cnt = ft_print_res(tmp, len, op);
	free(n_str);
	free(tmp);
	return (cnt);
}
