/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:21:54 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/17 19:14:20 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


int				ft_mouse_p(int key, int x, int y, t_rtv *rtv)
{
	printf("x = %d, y = %d\n", (x - WIDTH / 2) * -1, (y - HEIGHT / 2) * -1);
	return (0);
}


int				ft_key_r(int key, t_rtv *rtv)
{
	if (key == 53)
		exit (0);
	if (key == 126)
		{
			rtv->light->pos[0]--;
		}
	else if (key == 88)
	{
		INCOR(rtv->cam->o, rtv->cam->o[0] + 1, rtv->cam->o[1],rtv->cam->o[2]);
	}
	else if (key == 86)
	{
		INCOR(rtv->cam->o, rtv->cam->o[0] - 1, rtv->cam->o[1],rtv->cam->o[2] );
	}
	else if (key == 91)
	{
		INCOR(rtv->cam->o, rtv->cam->o[0], rtv->cam->o[1],rtv->cam->o[2] + 1);
	}
	else if (key == 84)
	{
		INCOR(rtv->cam->o, rtv->cam->o[0], rtv->cam->o[1],rtv->cam->o[2] - 1);
	}
	else if (key == 67)
	{
		INCOR(rtv->cam->o, rtv->cam->o[0], rtv->cam->o[1] + 1,rtv->cam->o[2]);
	}
	else if (key == 78)
	{
		INCOR(rtv->cam->o, rtv->cam->o[0], rtv->cam->o[1] - 1,rtv->cam->o[2]);
	}
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

t_light		*ft_init_light()
{
	t_light	*l;
	
	l = malloc(sizeof(t_light));
	l->type = 'a';
	l->intensity = 0.1;
	l->next= NULL;
	return (l);
}

void	ft_init_start(t_cam *c)
{
	c->o[0] = 0;
	c->o[1] = 10;
	c->o[2] = -35;
}

static t_rtv	*ft_creat_wspace(void)
{
	t_rtv		*rtv;
	t_wspace	*s;
	t_cam		*cam;
	t_light		*light;

	rtv = malloc(sizeof(t_rtv));
	s = malloc(sizeof(t_wspace));
	cam = malloc(sizeof(t_cam));
	light = ft_init_light();
	s->ptr = mlx_init();
	s->win = mlx_new_window(s->ptr, WIDTH, HEIGHT, "RTv1");
	ft_init_start(cam);
	rtv->ws = s;
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


int		main(int argc, char **argv)
{
	t_rtv	*rtv;

	rtv = ft_creat_wspace();
	if ( argc == 2 && main_parse(argv[1], rtv))
		{
			ft_putstr("ERROR MAP\n");
			return (0);
		}
	ft_main_alg(rtv);
	mlx_hook(rtv->ws->win, 2, 5, ft_key_r, rtv);
	mlx_hook(rtv->ws->win, 4, 5, ft_mouse_p, rtv);
	mlx_loop(rtv->ws->ptr);
	return (0);
}