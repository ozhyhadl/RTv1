/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:54:52 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/18 20:08:08 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"

int		check_light(char **tmp, t_rtv *r)
{
	t_light	*new;

	if (cmx(tmp) != 5 || ft_atoi(tmp[4]) < 0 || ft_atoi(tmp[4]) > 10)
		return (1);
	new = malloc(sizeof(t_light));
	INCOR(new->pos, ft_atoi(tmp[1]), ft_atoi(tmp[2]), ft_atoi(tmp[3]));
	new->intensity = ft_atoi(tmp[4]) * 0.1;
	new->type = 'p';
	new->next = r->light;
	r->light = new;
	return (0);
}
