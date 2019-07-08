/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:38:45 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/08 21:07:33 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_trace_r2(t_rtv *r, void *figure, double lim, double *d)
{
	double		p[3];
	double		n[3];
	double		tm[3];
	double		len_n;
	double		i;
	int			color[3];
	int			int_color;
	double		tmp_d[3];
	t_spher		*t;

	t = figure;
	MUL13(tm, lim, d);
	ADD3(p, r->cam->o, tm);
	SUB3(n, p, t->center);
	len_n = sqrt(ft_dot_p(n, n));
	MUL13(n, 1.0 / len_n, n);
	MUL13(tmp_d, -1, d);
	i = ft_calc_light(p, n, r, tmp_d);
	if (i > 1.4)
		return(WHITE_COLOR);
	i = i > 1 ? 1 : i;
	MUL13(color, i, t->color);
	GETC(int_color, color);
	return (int_color);
}

void	ft_trace_calc(double *c, double *d, double *t, t_spher *spher)
{
	double		oc[3];
	double		k1;
	double		k2;
	double		k3;
	int			radius;
	double		discrimi;

	radius = spher->radius;
	SUB3(oc, c, spher->center);
	k1 = ft_dot_p(d, d);
	k2 = 2 * ft_dot_p(oc, d);
	k3 = ft_dot_p(oc, oc) - radius * radius;
	if ((discrimi = k2 * k2 - 4 * k1 * k3) < 0)
		{
			t[0] = INF;
			t[1]= INF;
			return ;
		}
	t[0] = (-k2 + sqrt(discrimi)) / (2 * k1);
	t[1] = (-k2 - sqrt(discrimi)) / (2 * k1);

}

double		ft_quadratic(t_rtv *r, double *d, double max, double *p)
{
	
	t_spher		*tmp[2];
	double		tn[2];
	double		min;

	min = 0.0001;
	tmp[0] = r->spher;
	tmp[1] = NULL;
	while (tmp[0] != NULL)
	{
		ft_trace_calc(p, d, tn, tmp[0]);
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
		return(max);
	return(INF);
}