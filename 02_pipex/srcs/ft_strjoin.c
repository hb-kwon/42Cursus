/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:56:31 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/05 19:52:54 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char		*dp;
	const unsigned char	*sp;
	size_t				i;

	if (!dest && !src)
		return (0);
	dp = (unsigned char *)dest;
	sp = (const unsigned char *)src;
	i = 0;
	while (i < size)
	{
		dp[i] = sp[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*res;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) + (len1 + len2 + 1));
	if (!res)
		return (0);
	ft_memcpy(res, s1, len1);
	ft_memcpy(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	return (res);
}
