/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 00:06:35 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/17 19:13:02 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		c_count(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i] != NULL)
		i++;
	return (i);
}

int		cmx(char **tmp)
{
	int i;
	int j;

	i = 1;
	while (tmp[i] != NULL)
		{
			j = 0;
			while (tmp[i][j] != '\0')
			{
			if ((tmp[i][j] >= '0' && tmp[i][j] <= '9') || tmp[i][j] == '-')
				j++;
			else
				return (-1);
			if ((j > 5 && tmp[i][0] != '-') || (tmp[i][0] == '-' && j > 6)) 
				return (-2);
			}
			i++;
		}
	return (i);
}

int		c_rgb(int r, int g, int b)
{
	if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255))
		return(0);
	ft_putstr("RGB is not valid\n");
	return (1);
}

int		check_spher(char **tmp, t_rtv *r)
{
	t_spher *new;

	if (cmx (tmp) != 8 || c_rgb(ft_atoi(tmp[4]), ft_atoi(tmp[5]), ft_atoi(tmp[6])) ||\
		ft_atoi(tmp[7]) < 1)
		return (1);
	new = malloc(sizeof(t_spher));
	INCOR(new->center, ft_atoi(tmp[1]) / 20, ft_atoi(tmp[2]) / 20, ft_atoi(tmp[3]));
	INCOR(new->color, ft_atoi(tmp[4]), ft_atoi(tmp[5]), ft_atoi(tmp[6]));
	new->radius = ft_atoi(tmp[7]);
	new->specular = 15;
	if (r->spher == NULL)
	{
		r->spher = new;
		new->next = NULL;
		return (0);
	}
	new->next = r->spher;
	r->spher = new;
	return (0);
}

int		check_plane(char **tmp, t_rtv *r)
{
	t_plane *new;

	if (cmx (tmp) != 10 || c_rgb(ft_atoi(tmp[4]), ft_atoi(tmp[5]), ft_atoi(tmp[6])))
		return (1);
	new = malloc(sizeof(t_plane));
	INCOR(new->center, ft_atoi(tmp[1]) / 20, ft_atoi(tmp[2]) / 20, ft_atoi(tmp[3]));
	INCOR(new->color, ft_atoi(tmp[4]), ft_atoi(tmp[5]), ft_atoi(tmp[6]));
	INCOR(new->vec, ft_atoi(tmp[7]), ft_atoi(tmp[8]), ft_atoi(tmp[9]));
	new->specular = 100000000;
	if (r->plane == NULL)
	{
		r->plane = new;
		new->next = NULL;
		return (0);
	}
	new->next = r->plane;
	r->plane = new;
	return (0);
}

int		check_cilindr(char **tmp, t_rtv *r)
{
	t_cilindr *new;

	if (cmx (tmp) != 11 || c_rgb(ft_atoi(tmp[4]), ft_atoi(tmp[5]), ft_atoi(tmp[6]))\
		|| ft_atoi(tmp[10]) < 1)
		return (1);
	new = malloc(sizeof(t_cilindr));
	INCOR(new->start, ft_atoi(tmp[1]) / 20, ft_atoi(tmp[2]) / 20, ft_atoi(tmp[3]));
	INCOR(new->color, ft_atoi(tmp[4]), ft_atoi(tmp[5]), ft_atoi(tmp[6]));
	INCOR(new->vec, ft_atoi(tmp[7]), ft_atoi(tmp[8]), ft_atoi(tmp[9]));
	new->specular = 100;
	ft_normalization(new->vec);
	new->radius = ft_atoi(tmp[10]);

	if (r->cilindr == NULL)
	{
		r->cilindr = new;
		new->next = NULL;
		return (0);
	}
	new->next = r->cilindr;
	r->cilindr = new;
	return (0);
}

int		check_cone(char **tmp, t_rtv *r)
{
	t_cone *new;

	if (cmx (tmp) != 10 || c_rgb(ft_atoi(tmp[4]), ft_atoi(tmp[5]), ft_atoi(tmp[6])))
		return (1);
	new = malloc(sizeof(t_cone));
	INCOR(new->start, ft_atoi(tmp[1]) / 20, ft_atoi(tmp[2]) / 20, ft_atoi(tmp[3]));
	INCOR(new->color, ft_atoi(tmp[4]), ft_atoi(tmp[5]), ft_atoi(tmp[6]));
	INCOR(new->vec, ft_atoi(tmp[7]), ft_atoi(tmp[8]), ft_atoi(tmp[9]));
	new->specular = 1000;
	ft_normalization(new->vec);
	new->tang = tan(180 / (180 * 3.14));
	if (r->cone == NULL)
	{
		r->cone = new;
		new->next = NULL;
		return (0);
	}
	new->next = r->cone;
	r->cone = new;
	return (0);
}

void	check_intensity(t_rtv *r)
{
	t_light	*tmp_l;
	double	i;

	tmp_l = r->light;
	i = 0;
	while (tmp_l != NULL)
	{
		i += tmp_l->intensity;
		tmp_l = tmp_l->next;
	}
	while (i >= 1)
	{
		tmp_l = r->light;
		i = 0;
		while (tmp_l != NULL)
		{
			if (tmp_l->type == 'p')
				tmp_l->intensity *= 0.9;
			i += tmp_l->intensity;
			tmp_l = tmp_l->next;
		}
	}
}

int		check_light(char **tmp, t_rtv *r)
{
	t_light	*new;


	if (cmx(tmp) != 5 || ft_atoi(tmp[4]) < 0 || ft_atoi(tmp[4]) > 10)
		return (1);
	new = malloc(sizeof(t_light));
	INCOR(new->pos, ft_atoi(tmp[1]), ft_atoi(tmp[2]), ft_atoi(tmp[3]));
	new->intensity = ft_atoi(tmp[4]) * 0.1;
	new->type = 'p';
	if (r->light == NULL)
	{
		r->light = new;
		new->next = NULL;
		return (0);
	}
	new->next = r->light;
	r->light = new;
	return (0);
}

