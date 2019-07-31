/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:02:18 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/18 20:08:29 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"

int		ft_plane_light(t_rtv *r, t_plane *figure, double lim, double *d)
{
	double		p[3];
	double		n[3];
	double		tm[3];
	double		tmp_d[3];

	MUL13(tm, lim, d);
	ADD3(p, r->cam->o, tm);
	INCOR(n, figure->vec[0], figure->vec[1], figure->vec[2]);
	ft_normalization(n);
	MUL13(tmp_d, -1, d);
	return (ft_get_int_color(r, tmp_d, n, p));
}

double	ft_plane_calc(t_plane *plane, double *d, double *p)
{
	double	oc[3];
	double	k1;
	double	k2;
	double	n[3];

	SUB3(oc, p, plane->center);
	MUL13(oc, -1, oc);
	INCOR(n, plane->vec[0], plane->vec[1], plane->vec[2]);
	ft_normalization(n);
	if (ft_dot_p(d, n) >= 0)
	{
		MUL13(plane->vec, -1, plane->vec);
	}
	k1 = ft_dot_p(oc, n);
	k2 = ft_dot_p(d, n);
	if (k2 == 0)
		return (-1);
	return (k1 / k2);
}

double	all_plane(t_rtv *r, double *d, double *p)
{
	t_plane		*tmp_plane;
	double		min;
	double		tmp;

	min = INF;
	tmp_plane = r->plane;
	while (tmp_plane != NULL)
	{
		if ((tmp = ft_plane_calc(tmp_plane, d, p)) <= min && \
			tmp > 0.0000000000001)
		{
			min = tmp;
			r->plane_choose = tmp_plane;
		}
		tmp_plane = tmp_plane->next;
	}
	return (min);
}
