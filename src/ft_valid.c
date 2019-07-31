/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 00:06:35 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/18 20:21:45 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"

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
			if (ft_isdigit(tmp[i][j]) || \
				((tmp[i][j] == '-' && ft_isdigit(tmp[i][j + 1]))))
				j++;
			else
				return (-1);
			if ((j > 6 && tmp[i][0] != '-') || (tmp[i][0] == '-' && j > 7))
				return (-2);
		}
		i++;
	}
	return (i);
}

int		c_rgb(int r, int g, int b)
{
	if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255))
		return (0);
	ft_putstr("RGB is not valid\n");
	return (1);
}

void	check_intensity(t_rtv *r)
{
	t_light	*tmp_l;
	double	i;

	tmp_l = r->light;
	i = 0;
	while (tmp_l != NULL)
	{
		i += tmp_l->intensity;
		tmp_l = tmp_l->next;
	}
	while (i >= 1)
	{
		tmp_l = r->light;
		i = 0;
		while (tmp_l != NULL)
		{
			if (tmp_l->type == 'p')
				tmp_l->intensity *= 0.9;
			i += tmp_l->intensity;
			tmp_l = tmp_l->next;
		}
	}
}
