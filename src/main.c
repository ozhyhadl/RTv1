/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:21:54 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/18 20:08:42 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"

t_light			*ft_init_light(void)
{
	t_light	*l;

	l = malloc(sizeof(t_light));
	l->type = 'a';
	l->intensity = 0.1;
	l->next = NULL;
	return (l);
}

void			ft_init_start(t_cam *c)
{
	c->o[0] = 0;
	c->o[1] = 10;
	c->o[2] = -35;
}

t_wspace		*ft_init_win(void)
{
	t_wspace	*tmp;

	if ((tmp = (t_wspace *)malloc(sizeof(t_wspace))) == NULL)
		return (NULL);
	tmp->ptr = mlx_init();
	tmp->win = mlx_new_window(tmp->ptr, WIDTH, HEIGHT, "RTv1");
	tmp->img = mlx_new_image(tmp->ptr, WIDTH, HEIGHT);
	tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bit, &tmp->line_s, \
									&tmp->endia);
	return (tmp);
}

static t_rtv	*ft_creat_wspace(void)
{
	t_rtv		*rtv;
	t_cam		*cam;
	t_light		*light;

	rtv = malloc(sizeof(t_rtv));
	cam = malloc(sizeof(t_cam));
	light = ft_init_light();
	ft_init_start(cam);
	rtv->ws = ft_init_win();
	rtv->cam = cam;
	rtv->spher = NULL;
	rtv->light = light;
	rtv->plane = NULL;
	rtv->cilindr = NULL;
	rtv->cone = NULL;
	rtv->x_angle = 0;
	rtv->y_angle = 0;
	return (rtv);
}

int				main(int argc, char **argv)
{
	t_rtv	*rtv;

	rtv = ft_creat_wspace();
	if (ft_start_parse(argc, argv, rtv))
		return (0);
	ft_main_alg(rtv);
	mlx_hook(rtv->ws->win, 2, 5, ft_key_r, rtv);
	mlx_hook(rtv->ws->win, 17, 5, ft_close, rtv);
	mlx_loop(rtv->ws->ptr);
	return (0);
}
