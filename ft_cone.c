/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:34:57 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/17 18:50:18 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_cone_light(t_rtv *r, t_cone *cone, double lim, double *d)
{
	double		p[3];
	double		tm[3];
	double		i;
	int			color[3];
	int			int_color;
	double		tmp_d[3];
	double		t;

	MUL13(tm, lim, d);
	ADD3(tm, r->cam->o, tm);
	SUB3(tm, tm, cone->start);
	t = ft_dot_p(tm, tm) / ft_dot_p(tm, cone->vec);
	MUL13(tmp_d, t, cone->vec);
	SUB3(tm, tm, tmp_d);
	ft_normalization(tm);
	MUL13(tmp_d, lim, d);
	ADD3(p, r->cam->o, tmp_d);
	MUL13(tmp_d, -1, d);
	i = ft_calc_light(p, tm, r, tmp_d);
	if (i > 1)
		return (WHITE_COLOR);
	i = i > 1 ? 1 : i;
	MUL13(color, i, cone->color);
	GETC(int_color, color);
	return (int_color);
}

double		ft_calc_cone(double *d, double *p, t_cone *c)
{
	double	discrim;
	double	k1;
	double	k2;
	double	k3;
	double	oc[3];
	double	t[2];

	SUB3(oc, p, c->start);
	k1 = ft_dot_p(d, d) - (1.0 + pow(c->tang, 2)) * pow(ft_dot_p(d, c->vec), 2);
	k2 = 2 * (ft_dot_p(d, oc) - (1.0 + pow(c->tang, 2)) * (ft_dot_p(d, c->vec) * ft_dot_p(oc, c->vec)));
	k3 = ft_dot_p(oc, oc) - (1.0 + pow(c->tang, 2)) * pow(ft_dot_p(oc, c->vec), 2);
	if ((discrim = k2 * k2 - 4 * k1 * k3) < 0)
		return (-1);
	t[0] = (-k2 + sqrt(discrim)) / (2 * k1);
	t[1] = (-k2 - sqrt(discrim)) / (2 * k1);
	if (t[0] < t[1] && t[0] >= 0)
		return(t[0]);
	return (t[1]);
}

double		all_cone(t_rtv *r, double *d, double *p, t_cone *c)
{
	t_cone		*tmp_cone;
	double		min;
	double		tmp;
	
	min = INF;
	tmp_cone = c;
	while (tmp_cone != NULL)
	{	
		if ((tmp = ft_calc_cone(d, p, tmp_cone)) < min && tmp > 0.000000000001)
		{
			min = tmp;
			r->cone_choose = tmp_cone;
		}
		tmp_cone = tmp_cone->next;
	}
	return (min);
}