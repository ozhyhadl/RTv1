/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:10:15 by ozhyhadl          #+#    #+#             */
/*   Updated: 2018/11/22 19:18:12 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*ctmp;
	unsigned int	ntmp;
	int				i;

	i = 0;
	if (n < 0)
	{
		i++;
		ntmp = -n;
	}
	else
		ntmp = n;
	i = i + ft_declen(ntmp);
	if ((ctmp = malloc(i + 1)) == NULL)
		return (NULL);
	ctmp[i] = '\0';
	while (i-- != 0)
	{
		ctmp[i] = (ntmp % 10) + '0';
		ntmp /= 10;
	}
	if (n < 0)
		ctmp[0] = '-';
	return (ctmp);
}
