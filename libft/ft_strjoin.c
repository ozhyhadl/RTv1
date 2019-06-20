/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:48:47 by ozhyhadl          #+#    #+#             */
/*   Updated: 2018/11/22 19:18:12 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if ((tmp = malloc(i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		tmp[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		tmp[i] = *s2;
		s2++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
