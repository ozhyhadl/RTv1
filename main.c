/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:21:54 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/09 21:35:27 by ozhyhadl         ###   ########.fr       */
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
// t_spher		*add_spher(t_spher *sp)
// {
// 	t_spher *tmp;

// 	if (sp == NULL)
// 	{		
// 		sp = malloc(sizeof(t_spher));
// 		INCOR(sp->center, -2, 0, 4);
// 		sp->name = ft_strdup("spher");
// 		sp->radius = 1;
// 		sp->specular = 500;
// 		INCOR(sp->color, 0, 0, 255);
// 		sp->next = NULL;
// 	}		
// 		tmp = malloc(sizeof(t_spher));
// 		INCOR(tmp->center, 2, 0, 4);
// 		tmp->name = ft_strdup("spher");
// 		tmp->radius = 1;
// 		tmp->specular = 10;
// 		INCOR(tmp->color, 0, 255, 0);
// 		tmp->next = sp;
// 		sp = tmp;

// 		tmp = malloc(sizeof(t_spher));
// 		INCOR(tmp->center, 0, 0.4, 3);
// 		tmp->name = ft_strdup("spher");
// 		tmp->radius = 1;
// 		tmp->specular = 500;
// 		INCOR(tmp->color, 255, 0, 0);
// 		tmp->next = sp;
// 		sp = tmp;

// 	return (sp);
// }

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
	tmp->intensity = 0.2;
	INCOR(tmp->pos, 0, 10, -10);

	tmp = malloc(sizeof(t_light));
	tmp->next = l;
	l = tmp;
	tmp->type = 'p';
	tmp->intensity = 0.6;
	INCOR(tmp->pos, 5, 10, -10);

	return (l);
}
void	ft_init_start(t_cam *c)
{
	c->o[0] = 0;
	c->o[1] = 10;
	c->o[2] = -35;
}

// t_cilindr		*add_cilindr(void)
// {
// 	t_cilindr	*c;

// 	c = malloc(sizeof(t_cilindr));
// 	INCOR(c->start, -5, 10, 5);
// 	INCOR(c->vec, 0, 1, 0);
// 	c->name = ft_strdup("cilindr");
// 	c->radius = 1;
// 	ft_normalization(c->vec);
// 	INCOR(c->color, 180, 180, 180);
// 	c->specular = 100;
// 	c->next = NULL;
	

// 	return (c);
// }

// t_cone		*add_cone(void)
// {
// 	t_cone	*c;

// 	c = malloc(sizeof(t_cone));
// 	INCOR(c->start, 0 / 38, 300 / 38, 10);
// 	INCOR(c->vec, 0, 1, 0);
// 	c->tang = tan(180 / (180 * 3.14));
// 	c->name = ft_strdup("cone");
// 	ft_normalization(c->vec);
// 	INCOR(c->color, 255, 0, 0);
// 	c->specular = 1000;
// 	c->next = NULL;

// 	return (c);
// }

// t_plane			*add_plane(void)
// {
// 	t_plane *plane;
// 	t_plane *tmp;

// 	// plane = malloc(sizeof(t_plane));
// 	// INCOR(plane->center, 0, -10, 0);
// 	// INCOR(plane->vec, 0, 1, 0);
// 	// plane->name = ft_strdup("plane");
// 	// plane->specular = 1000;
// 	// INCOR(plane->color, 192, 192, 192);
// 	// plane->next = NULL;

// 	// tmp = malloc(sizeof(t_plane));
// 	// INCOR(tmp->center, 0, 0, 20);
// 	// INCOR(tmp->vec, 0, 0, 1);
// 	// tmp->name = ft_strdup("plane");
// 	// tmp->specular = 10000000 ;
// 	// INCOR(tmp->color, 191, 191, 255);
// 	// tmp->next = plane;
// 	// plane = tmp;

// 	return(plane);
// }
static t_rtv	*ft_creat_wspace(void)
{
	t_rtv		*rtv;
	t_wspace	*s;
	t_cam		*cam;
	// t_spher		*sp;
	t_light		*light;

	rtv = malloc(sizeof(t_rtv));
	s = malloc(sizeof(t_wspace));
	cam = malloc(sizeof(t_cam));

	light = ft_init_light();

	// sp = add_spher(NULL);
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
	if (main_parse("test1", rtv))
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