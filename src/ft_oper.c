/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:10:10 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/18 20:08:26 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"

static void	ft_calc_d(double *d, double x, double y)
{
	d[0] = x * 1 / WIDTH;
	d[1] = y * 1 / HEIGHT;
	d[2] = 1;
}

static int	ft_min_figure(t_rtv *r, double *d, double min_tt, int i)
{
	if (i == 2)
		return (ft_cilind_light(r, r->cilindr_choose, min_tt, d));
	if (i == 3)
		return (ft_cone_light(r, r->cone_choose, min_tt, d));
	if (i == 1 && min_tt != INF)
	{
		r->figure_choose = r->spher_choose;
		return (ft_spher_light(r, r->spher_choose, min_tt, d));
	}
	return (BLACK);
}

static int	ft_trace_ray(t_rtv *r, double *d, double min_tt)
{
	double		tmp_tt;
	int			i;

	i = 1;
	if ((tmp_tt = all_spher(r, d, INF, r->cam->o)) < min_tt)
		min_tt = tmp_tt;
	if ((tmp_tt = all_cilindr(r, d, r->cam->o, r->cilindr)) < min_tt)
	{
		r->figure_choose = (t_spher *)r->cilindr_choose;
		min_tt = tmp_tt;
		i = 2;
	}
	if ((tmp_tt = all_cone(r, d, r->cam->o, r->cone)) < min_tt)
	{
		r->figure_choose = (t_spher *)r->cone_choose;
		min_tt = tmp_tt;
		i = 3;
	}
	if (((tmp_tt = all_plane(r, d, r->cam->o)) < min_tt))
	{
		r->figure_choose = (t_spher *)r->plane_choose;
		min_tt = tmp_tt;
		return (ft_plane_light(r, r->plane_choose, min_tt, d));
	}
	return (ft_min_figure(r, d, min_tt, i));
}

void		ft_main_alg(t_rtv *r)
{
	double	x;
	double	y;
	double	d[3];

	x = -WIDTH / 2;
	while (x < WIDTH / 2)
	{
		y = -HEIGHT / 2;
		while (y < HEIGHT / 2)
		{
			ft_calc_d(d, x, y);
			if (r->x_angle != 0)
				ft_rotation_x(r->x_angle, d);
			if (r->y_angle != 0)
				ft_rotation_y(r->y_angle, d);
			ft_pixel_put(r->ws, x, y, ft_trace_ray(r, d, INF));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(r->ws->ptr, r->ws->win, r->ws->img, 0, 0);
}
