/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 00:21:18 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/18 20:08:04 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"

int		check_spher(char **tmp, t_rtv *r)
{
	t_spher *new;

	if (cmx(tmp) != 8 || c_rgb(ft_atoi(tmp[4]), ft_atoi(tmp[5]), \
		ft_atoi(tmp[6])) || ft_atoi(tmp[7]) < 1)
		return (1);
	new = malloc(sizeof(t_spher));
	INCOR(new->center, ft_atoi(tmp[1]), ft_atoi(tmp[2]),\
		ft_atoi(tmp[3]));
	INCOR(new->color, ft_atoi(tmp[4]), ft_atoi(tmp[5]), ft_atoi(tmp[6]));
	new->radius = ft_atoi(tmp[7]);
	new->specular = 15;
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

int		check_plane(char **tmp, t_rtv *r)
{
	t_plane *new;

	if (cmx(tmp) != 10 || c_rgb(ft_atoi(tmp[4]), \
		ft_atoi(tmp[5]), ft_atoi(tmp[6])))
		return (1);
	new = malloc(sizeof(t_plane));
	INCOR(new->center, ft_atoi(tmp[1]), ft_atoi(tmp[2])\
		, ft_atoi(tmp[3]));
	INCOR(new->color, ft_atoi(tmp[4]), ft_atoi(tmp[5]), ft_atoi(tmp[6]));
	INCOR(new->vec, ft_atoi(tmp[7]), ft_atoi(tmp[8]), ft_atoi(tmp[9]));
	new->specular = 100000000;
	if (r->plane == NULL)
	{
		r->plane = new;
		new->next = NULL;
		return (0);
	}
	new->next = r->plane;
	r->plane = new;
	return (0);
}

int		check_cilindr(char **tmp, t_rtv *r)
{
	t_cilindr *new;

	if (cmx(tmp) != 11 || c_rgb(ft_atoi(tmp[4]), ft_atoi(tmp[5]),\
		ft_atoi(tmp[6])) || ft_atoi(tmp[10]) < 1)
		return (1);
	new = malloc(sizeof(t_cilindr));
	INCOR(new->start, ft_atoi(tmp[1]), ft_atoi(tmp[2]),\
		ft_atoi(tmp[3]));
	INCOR(new->color, ft_atoi(tmp[4]), ft_atoi(tmp[5]), ft_atoi(tmp[6]));
	INCOR(new->vec, ft_atoi(tmp[7]), ft_atoi(tmp[8]), ft_atoi(tmp[9]));
	new->specular = 100;
	ft_normalization(new->vec);
	new->radius = ft_atoi(tmp[10]);
	if (r->cilindr == NULL)
	{
		r->cilindr = new;
		new->next = NULL;
		return (0);
	}
	new->next = r->cilindr;
	r->cilindr = new;
	return (0);
}

int		check_cone(char **tmp, t_rtv *r)
{
	t_cone *new;

	if (cmx(tmp) != 10 || c_rgb(ft_atoi(tmp[4]), ft_atoi(tmp[5]),\
		ft_atoi(tmp[6])))
		return (1);
	new = malloc(sizeof(t_cone));
	INCOR(new->start, ft_atoi(tmp[1]), ft_atoi(tmp[2]),\
		ft_atoi(tmp[3]));
	INCOR(new->color, ft_atoi(tmp[4]), ft_atoi(tmp[5]), ft_atoi(tmp[6]));
	INCOR(new->vec, ft_atoi(tmp[7]), ft_atoi(tmp[8]), ft_atoi(tmp[9]));
	new->specular = 1000;
	ft_normalization(new->vec);
	new->tang = tan(320 / (180 * 3.14));
	if (r->cone == NULL)
	{
		r->cone = new;
		new->next = NULL;
		return (0);
	}
	new->next = r->cone;
	r->cone = new;
	return (0);
}

int		check_cam(char **tmp, t_rtv *r)
{
	if (cmx(tmp) != 6)
		return (1);
	INCOR(r->cam->o, ft_atoi(tmp[1]), ft_atoi(tmp[2]), \
		ft_atoi(tmp[3]));
	r->x_angle = ft_atoi(tmp[4]) * (3.14 / 180);
	r->y_angle = ft_atoi(tmp[5]) * (3.14 / 180);
	return (0);
}
