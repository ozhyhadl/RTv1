/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:15:33 by ozhyhadl          #+#    #+#             */
/*   Updated: 2018/11/22 19:18:12 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_startlen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

static int	ft_counts(char const *s, char c)
{
	int i;
	int z;

	z = 0;
	i = ft_startlen(s, c);
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i - 1] != c) || (s[i] != c && s[i + 1] == '\0'))
			z++;
		i++;
	}
	return (z);
}

static char	**ft_replace(char const *s, char c, char **tmp)
{
	int i;
	int z;
	int x;

	i = ft_startlen(s, c);
	z = i;
	x = 0;
	while (s[z] != '\0')
	{
		if ((s[z] == c && s[z - 1] != c) || (s[z] != c && s[z + 1] == '\0'))
		{
			if (s[z] != c && s[z + 1] == '\0')
				tmp[x] = ft_strsub(s, i, z + 1 - i);
			else
				tmp[x] = ft_strsub(s, i, z - i);
			x++;
		}
		if (s[z] == c)
			i = z + 1;
		z++;
	}
	tmp[x] = NULL;
	return (tmp);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tmp;

	if (!s)
		return (NULL);
	if ((tmp = malloc(sizeof(char *) * ft_counts(s, c) + 1)) == NULL)
		return (NULL);
	tmp = ft_replace(s, c, tmp);
	return (tmp);
}
