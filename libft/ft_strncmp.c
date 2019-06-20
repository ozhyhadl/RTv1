/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:18:23 by ozhyhadl          #+#    #+#             */
/*   Updated: 2018/11/28 06:58:36 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i < (n - 1))
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
}
