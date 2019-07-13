/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:30:02 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/13 03:27:43 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		ft_calc_specular(double *n, t_rtv *r, double *v, double *vec)
{
	double i;
	double dot_v;
	double vec_r[3];
	double tmp_vec[3];

	i = 0;
	MUL13(tmp_vec, 2 * ft_dot_p(n, vec), n);
	SUB3(vec_r, tmp_vec, vec);
	if ((dot_v = ft_dot_p(vec_r, v)) > 0)
	i += pow(dot_v / (sqrt(ft_dot_p(vec_r, vec_r)) * sqrt(ft_dot_p(v, v))), r->spher_choose->specular);
	return (i);
}

double		ft_calc_light_2(double *p, double *n, t_rtv *r, double *vec)
{
	double i;
	double		dot;
	double		len_n;
	t_light		*l;
	double		max;

	l = r->light_choose;
	i = 0;
	SUB3(vec, l->pos, p);
	max = 1;
	if (ft_quadratic(r, vec, max, p) >= max && all_plane(r, vec, p) >= max && all_cilindr(r, vec, p, r->cilindr) >= max && all_cone(r, vec, p, r->cone) >= max)
		if ((dot = ft_dot_p(n, vec)) > 0)
		{
			len_n = sqrt(ft_dot_p(n, n));
			i += l->intensity * dot / (len_n * sqrt(ft_dot_p(vec, vec)));
		}
	return (i);
}

double		ft_calc_light(double *p, double *n, t_rtv *r, double *v)
{
	double		i;
	t_light		*l;
	double		vec[3];

	l = r->light;
	i = 0;
	INCOR(vec, 0, 0, 0);
	while (l != NULL)
	{
		if (l->type == 'a')
			i += l->intensity;
		else
		{
			r->light_choose = l;
			if (r->spher_choose->specular > 0 && (i += ft_calc_light_2(p, n, r, vec)) > 0 )
					i += l->intensity * ft_calc_specular(n, r, v, vec);
		}
		l = l->next;
	}
	return(i);
}