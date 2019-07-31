/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:11:07 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/18 20:08:19 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"

int				ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int				ft_key_r(int key, t_rtv *rtv)
{
	if (key == 53)
		exit(0);
	else if (key == KEY_W)
		rtv->x_angle += ANGLE;
	else if (key == KEY_S)
		rtv->x_angle -= ANGLE;
	else if (key == KEY_D)
		rtv->y_angle += ANGLE;
	else if (key == KEY_A)
		rtv->y_angle -= ANGLE;
	mlx_clear_window(rtv->ws->ptr, rtv->ws->win);
	ft_main_alg(rtv);
	return (0);
}
