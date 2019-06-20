/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:47:53 by ozhyhadl          #+#    #+#             */
/*   Updated: 2018/11/22 19:18:12 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int					ln;
	unsigned int		st;

	st = 0;
	if (!s)
		return (NULL);
	while (s[st] == ' ' || s[st] == '\n' || s[st] == '\t')
		st++;
	if (s[st] == '\0')
		return (ft_strdup(s + st));
	ln = ft_strlen(s) - 1;
	while ((s[ln] == ' ' || s[ln] == '\n' || s[ln] == '\t') && ln > 0)
		ln--;
	return (ft_strsub(s, st, ln - st + 1));
}
