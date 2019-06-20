/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:10:10 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/06/20 20:52:50 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_calc_d(double *d, double x, double y)
{
	d[0] = x * 1 / WIDTH;
	d[1] = y * 1 / HEIGHT;
	d[2] = 1;
}
double	ft_dot_p(double *first, double *second)
{
	return (first[0] * second[0] + first[1] * second[1] + first[2] * second[2]);
}
static void ft_sub(double *oc, int *center, int *camera)
{
	oc[0] = camera[0] - center[0];
	oc[1] = camera[1] - center[1];
	oc[2] = camera[2] - center[2];
}

static int	ft_trace_r2(t_rtv *r, void *figure, double lim, double *d)
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
	if (i > 1.2)
		return (WHITE_COLOR);
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
	int		radius;
	double	discrimi;

	radius = spher->radius;
	SUB3(oc,c, spher->center);
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

t_spher		*ft_quadratic(t_rtv *r, double *d, int min, double *lim)
{
	
	t_spher		*tmp[2];
	double		tn[2];

	*lim = INF;
	tmp[0] = r->spher;
	tmp[1] = NULL;
	while (tmp[0] != NULL)
	{
		ft_trace_calc(r->cam->o, d, tn, tmp[0]);
		if (tn[0] < *lim && min < tn[0] && tn[0] < INF)
		{
			*lim = tn[0];
			tmp[1] = tmp[0];
		}
		if (tn[1] < *lim && min < tn[1] && tn[1] < INF)
		{
			*lim = tn[1];
			tmp[1] = tmp[0];
		}
		tmp[0] = tmp[0]->next;
	}
	return(tmp[1]);
}



static int	ft_trace_ray(t_rtv *r, double *d, int min)
{
	double		lim;
	void		*tmp;
	double		t_tmp;
	
	tmp = ft_quadratic(r, d, min, &lim);
	if (((t_tmp = ft_plane_calc(r, d)) < lim) && t_tmp > min)
	{
		r->spher_choose = (t_spher *)r->plane;
		return(ft_plane_light(r, r->plane, t_tmp, d));
		return (12632256);
	}
	if (tmp == NULL)
		return (BACKGROUND_COLOR);
	r->spher_choose = tmp;
	return(ft_trace_r2(r, tmp, lim, d));
}

void	ft_pixel_put(t_wspace *ws, double x, double y, int color)
{
		mlx_pixel_put(ws->ptr, ws->win, WIDTH / 2 + x, HEIGHT / 2 - y - 1, color);
}

void	ft_main_alg(t_rtv *r)
{
	double	x;
	double	y;
	int		*color;
	double	d[3];

	x = -WIDTH / 2;
	while (x < WIDTH / 2)
	{
		y = -HEIGHT / 2;
		while(y < HEIGHT / 2)
		{
			ft_calc_d(d, x, y);
			ft_pixel_put(r->ws, x, y, ft_trace_ray(r, d, 1));
			y++;
		}
		x++;
	}
}