/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:14:52 by ozhyhadl          #+#    #+#             */
/*   Updated: 2018/11/22 19:18:12 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmpsrc;
	unsigned char	*tmpdest;
	size_t			i;

	i = -1;
	tmpsrc = (unsigned char *)src;
	tmpdest = (unsigned char *)dst;
	if (tmpsrc < tmpdest)
		while ((int)(--len) >= 0)
			*(tmpdest + len) = *(tmpsrc + len);
	else
		while (++i < len)
			*(tmpdest + i) = *(tmpsrc + i);
	return (dst);
}
