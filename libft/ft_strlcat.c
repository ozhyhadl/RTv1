/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 21:40:06 by ozhyhadl          #+#    #+#             */
/*   Updated: 2018/11/29 03:01:02 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t z;
	size_t dstlength;
	size_t srclength;

	i = 0;
	z = 0;
	dstlength = ft_strlen(dst);
	srclength = ft_strlen(src);
	if (dstsize <= dstlength)
		return (srclength + dstsize);
	while (dst[i] != '\0' && i < (dstsize - 1))
		i++;
	while (src[z] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[z];
		i++;
		z++;
	}
	dst[i] = '\0';
	return (dstlength + srclength);
}
