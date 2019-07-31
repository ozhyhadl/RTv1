/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:38:45 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/18 20:08:34 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"

int			ft_spher_light(t_rtv *r, void *figure, double lim, double *d)
{
	double		p[3];
	double		n[3];
	double		tm[3];
	double		tmp_d[3];
	t_spher		*t;

	t = figure;
	MUL13(tm, lim, d);
	ADD3(p, r->cam->o, tm);
	SUB3(n, p, t->center);
	ft_normalization(n);
	MUL13(tmp_d, -1, d);
	return (ft_get_int_color(r, tmp_d, n, p));
}

void		ft_calc_spher(double *c, double *d, double *t, t_spher *spher)
{
	double		oc[3];
	double		k[3];
	int			radius;
	double		discrimi;

	radius = spher->radius;
	SUB3(oc, c, spher->center);
	k[0] = ft_dot_p(d, d);
	k[1] = 2 * ft_dot_p(oc, d);
	k[2] = ft_dot_p(oc, oc) - radius * radius;
	if ((discrimi = k[1] * k[1] - 4 * k[0] * k[2]) < 0)
	{
		t[0] = INF;
		t[1] = INF;
		return ;
	}
	t[0] = (-k[1] + sqrt(discrimi)) / (2 * k[0]);
	t[1] = (-k[1] - sqrt(discrimi)) / (2 * k[0]);
}

double		all_spher(t_rtv *r, double *d, double max, double *p)
{
	t_spher		*tmp[2];
	double		tn[2];
	double		min;

	min = 0.000000000001;
	tmp[0] = r->spher;
	tmp[1] = NULL;
	while (tmp[0] != NULL)
	{
		ft_calc_spher(p, d, tn, tmp[0]);
		if (tn[0] < max && min < tn[0] && tn[0] < INF)
		{
			max = tn[0];
			r->spher_choose = tmp[0];
		}
		if (tn[1] < max && min < tn[1] && tn[1] < INF)
		{
			max = tn[1];
			r->spher_choose = tmp[0];
		}
		tmp[0] = tmp[0]->next;
	}
	if (max != INF)
		return (max);
	return (INF);
}
