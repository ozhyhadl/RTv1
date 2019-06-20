/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:02:18 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/06/20 20:58:33 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_plane_light(t_rtv *r, t_plane *figure, double lim, double *d)
{
	double		p[3];
	double		n[3];
	double		tm[3];
	double		len_n;
	double		i;
	int			color[3];
	int			int_color;
	double		tmp_d[3];

	MUL13(tm, lim, d);
	ADD3(p, r->cam->o, tm);
	INCOR(n, figure->normal[0], figure->normal[1], figure->normal[2])
	// SUB3(n, p, figure->center);
	len_n = sqrt(ft_dot_p(n, n));
	ft_normalization(n);
	i = ft_calc_light(p, n, r, tmp_d);
	if (i > 1.2)
		return (WHITE_COLOR);
	i = i > 1 ? 1 : i;
	MUL13(color, i, figure->color);
	GETC(int_color, color);

	return (int_color);
}

double	ft_plane_calc(t_rtv *r, double *d)
{
	double	oc[3];
	double	dv[3];
	double	k1;
	double	k2;
	double	n[3];
	
	SUB3(oc, r->cam->o, r->plane->center);
	MUL13(oc, -1, oc);
	INCOR(n, r->plane->normal[0], r->plane->normal[1], r->plane->normal[2]);
	ft_normalization(n);

	k1 = ft_dot_p(oc, n);
	k2 = ft_dot_p(d, n);
	if (k2 == 0)
		return (-1);
	return(k1 / k2);
}