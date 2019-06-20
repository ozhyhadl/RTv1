/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 20:17:36 by ozhyhadl          #+#    #+#             */
/*   Updated: 2018/11/22 19:18:12 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t n;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		n = 0;
		while (haystack[i + n] != '\0')
		{
			if (haystack[i + n] != needle[n] || (i + n) > len)
				break ;
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
