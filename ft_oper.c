/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:10:10 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/09 21:35:04 by ozhyhadl         ###   ########.fr       */
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

static int	ft_trace_ray(t_rtv *r, double *d, double min, double max)
{
	double		tmp_tt;
	double		min_tt;
	int			i;

	i = 0;
	min_tt	= INF;
	if ((tmp_tt = ft_quadratic(r, d, max, r->cam->o)) < max)
	{
			min_tt = tmp_tt;
			i = 1;
	}
	if ((tmp_tt = all_cilindr(r, d, r->cam->o, r->cilindr)) < min_tt && tmp_tt > min)
		{
			r->spher_choose = (t_spher *)r->cilindr_choose;
			min_tt = tmp_tt;
			i = 2;
		}
	if ((tmp_tt = all_cone(r, d, r->cam->o, r->cone)) < min_tt && tmp_tt > min)
		{
			r->spher_choose = (t_spher *)r->cone_choose;
			min_tt = tmp_tt;
			i = 4;
		}
	if (((tmp_tt = all_plane(r, d, r->cam->o)) < min_tt) && tmp_tt > min)
	{
		r->spher_choose = (t_spher *)r->plane_choose;
		min_tt = tmp_tt;
		i = 3;
	}
	if (i == 1)
		return(ft_trace_r2(r, r->spher_choose, min_tt, d));
	if (i == 2)
		return(ft_cilind_light(r, r->cilindr_choose, min_tt, d));
	if(i == 3)
		return(ft_plane_light(r, r->plane_choose, min_tt, d));
	if (i == 4)
		return(ft_cone_light(r, r->cone_choose, min_tt, d));
	return (BLACK);
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
			if (r->x_angle != 0)
				ft_rotation_x(r->x_angle, d);
			if (r->y_angle != 0)
				ft_rotation_y(r->y_angle, d);

			ft_pixel_put(r->ws, x, y, ft_trace_ray(r, d, 0.0001, INF));
			y++;
		}
		x++;
	}
}