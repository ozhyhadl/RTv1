/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cilindr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:45:55 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/18 20:08:10 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"

int			ft_cilind_light(t_rtv *r, t_cilindr *cilindr, double lim, double *d)
{
	double		p[3];
	double		tm[3];
	double		tmp_d[3];
	double		t;

	MUL13(tm, lim, d);
	ADD3(tm, r->cam->o, tm);
	SUB3(tm, tm, cilindr->start);
	t = ft_dot_p(tm, cilindr->vec);
	MUL13(tmp_d, t, cilindr->vec);
	SUB3(tm, tm, tmp_d);
	ft_normalization(tm);
	MUL13(tmp_d, lim, d);
	ADD3(p, r->cam->o, tmp_d);
	MUL13(tmp_d, -1, d);
	return (ft_get_int_color(r, tmp_d, tm, p));
}

double		ft_calc_cilindr(double *d, double *p, t_cilindr *c)
{
	double	discrim;
	double	k[3];
	double	oc[3];
	double	t[2];

	SUB3(oc, p, c->start);
	k[0] = ft_dot_p(d, d) - pow(ft_dot_p(d, c->vec), 2);
	k[1] = 2 * (ft_dot_p(d, oc) - (ft_dot_p(d, c->vec) * ft_dot_p(oc, c->vec)));
	k[2] = ft_dot_p(oc, oc) - pow(ft_dot_p(oc, c->vec), 2) - pow(c->radius, 2);
	if ((discrim = pow(k[1], 2) - 4 * k[0] * k[2]) < 0)
		return (-1);
	t[0] = (-k[1] + sqrt(discrim)) / (2 * k[0]);
	t[1] = (-k[1] - sqrt(discrim)) / (2 * k[0]);
	if (t[0] < t[1])
		return (t[0]);
	return (t[1]);
}

double		all_cilindr(t_rtv *r, double *d, double *p, t_cilindr *c)
{
	t_cilindr		*tmp_cilindr;
	double			min;
	double			tmp;

	min = INF;
	tmp_cilindr = c;
	while (tmp_cilindr != NULL)
	{
		if ((tmp = ft_calc_cilindr(d, p, tmp_cilindr)) < min \
			&& tmp > 0.000000000001)
		{
			min = tmp;
			r->cilindr_choose = tmp_cilindr;
		}
		tmp_cilindr = tmp_cilindr->next;
	}
	return (min);
}
