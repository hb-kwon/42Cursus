/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:37:22 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/15 17:33:21 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static void	*ft_init_flist(t_format *op)
{
	op->left = 0;
	op->zero = 0;
	op->base = 0;
	op->space = 0;
	op->sign = 0;
	op->width = 0;
	op->prec = 0;
	op->type = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			cnt; //구조체에 넣어서 해결

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (!(ft_init_flist(ap, &format, cnt)))
				return (-1);
		}
		else
		{
			cnt += write(1, format, 1);
			format++;
		}
	}
	va_end(ap);
	return (cnt);
}

int main(void)
{
	ft_printf("%-0# +10d",123123123123);
}