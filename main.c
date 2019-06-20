/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:21:54 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/06/20 20:58:14 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"



int				ft_key_r(int key, t_rtv *rtv)
{
	if (key == 53)
		exit (0);
	if (key == 126)
		{
			rtv->light->next->pos[0]--;
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
	mlx_clear_window(rtv->ws->ptr, rtv->ws->win);
	ft_main_alg(rtv);
	return (0);
}
t_spher		*add_spher(t_spher *sp)
{
	t_spher *tmp;

	if (sp == NULL)
	{
		sp = malloc(sizeof(t_spher));
		INCOR(sp->center, 0, 1, 3);
		sp->name = ft_strdup("spher");
		sp->radius = 1;
		sp->specular = 100;
		INCOR(sp->color, 255, 0, 0);
		sp->next = NULL;
	}
		tmp = malloc(sizeof(t_spher));
		INCOR(tmp->center, -2, 0, 4);
		tmp->name = ft_strdup("spher");
		tmp->radius = 1;
		tmp->specular = 100;
		INCOR(tmp->color, 0, 0, 255);
		tmp-> next = sp;
		sp = tmp;
		
		tmp = malloc(sizeof(t_spher));
		INCOR(tmp->center, 2, 0, 4);
		tmp->name = ft_strdup("spher");
		tmp->radius = 1;
		tmp->specular = 10;
		INCOR(tmp->color, 0, 255, 0);
		tmp->next = sp;
		sp = tmp;

		// tmp = malloc(sizeof(t_spher));
		// INCOR(tmp->center, 0, -1000, 0);
		// tmp->radius = 1000;
		// tmp->specular = 1000;
		// INCOR(tmp->color,255, 255, 0);
		// tmp->next = sp;
		// sp = tmp;

	return (sp);
}

t_light		*ft_init_light()
{
	t_light	*l;
	t_light	*tmp;
	
	l = malloc(sizeof(t_light));
	l->type = 'a';
	l->intensity = 0.1;
	l->next= NULL;

	tmp = malloc(sizeof(t_light));
	tmp->next = l;
	l = tmp;
	tmp->type = 'p';
	tmp->intensity = 0.6;
	INCOR(tmp->pos, 20, 10, 0);
	
	tmp = malloc(sizeof(t_light));
	tmp->next = l;
	l = tmp;
	tmp->type = 'd';
	tmp->intensity = 0.2;
	INCOR(tmp->pos, 10, 40, 40);

	return (l);
}
void	ft_init_start(t_cam *c)
{
	c->o[0] = 0;
	c->o[1] = 1;
	c->o[2] = 0;
}

t_plane			*add_plane(void)
{
	t_plane *plane;

	plane = malloc(sizeof(t_plane));
	INCOR(plane->center, 0, 0, 0);
	INCOR(plane->normal, 0, 1, 0);
	plane->name = ft_strdup("plane");
	plane->specular = 1;
	INCOR(plane->color, 192, 192, 192);
	return(plane);
}
static t_rtv	*ft_creat_wspace(void)
{
	t_rtv		*rtv;
	t_wspace	*s;
	t_cam		*cam;
	t_spher		*sp;
	t_light		*light;

	rtv = malloc(sizeof(t_rtv));
	s = malloc(sizeof(t_wspace));
	cam = malloc(sizeof(t_cam));

	light = ft_init_light();

	sp = add_spher(NULL);
	s->ptr = mlx_init();
	s->win = mlx_new_window(s->ptr, WIDTH, HEIGHT, "RTv1");
	ft_init_start(cam);
	rtv->ws = s;
	rtv->cam = cam;
	rtv->spher = sp;
	rtv->light = light;
	rtv->plane = add_plane();
	return (rtv);
}


int		main(void)
{
	t_rtv	*rtv;

	rtv = ft_creat_wspace();
	
	ft_main_alg(rtv);
	mlx_hook(rtv->ws->win, 2, 5, ft_key_r, rtv);
	mlx_loop(rtv->ws->ptr);
	return (0);
}