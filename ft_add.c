/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 00:06:35 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/03 18:58:12 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		c_count(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i] != NULL)
		i++;
	return (i);
}

int		cmx(char **tmp)
{
	int i;
	int j;

	i = 1;
	while (tmp[i] != NULL)
		{
			j = 0;
			while (tmp[i][j] != '\0')
			{
			if ((tmp[i][j] >= '0' && tmp[i][j] <= '9') || tmp[i][j] == '-')
				j++;
			else
				return (-1);
			if ((j > 5 && tmp[i][0] != '-') || (tmp[i][0] == '-' && j > 6)) 
				return (-2);
			}
			i++;
		}
	return (i);
}
int		c_rgb(int r, int g, int b)
{
	if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255))
		return(0);
	ft_putstr("RGB is not valid\n");
	return (1);
}
int		check_spher(char **tmp, t_rtv *r)
{
	t_spher *new;

	new = malloc(sizeof(t_spher));
	if (cmx (tmp) != 9 || c_rgb(ft_atoi(tmp[4]), ft_atoi(tmp[5]), ft_atoi(tmp[6])))
		return (1);
	INCOR(new->center, ft_atoi(tmp[1]), ft_atoi(tmp[2]), ft_atoi(tmp[3]));
	INCOR(new->color, ft_atoi(tmp[4]), ft_atoi(tmp[5]), ft_atoi(tmp[6]));
	new->radius = ft_atoi(tmp[7]);
	new->specular = ft_atoi(tmp[8]);
	if (r->spher == NULL)
	{
		r->spher = new;
		new->next = NULL;
		return (0);
	}
	new->next = r->spher;
	r->spher = new;
	return (0);
}