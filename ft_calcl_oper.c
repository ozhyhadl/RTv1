/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcl_oper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:18:16 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/16 15:57:43 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_normalization(double *n)
{
	double	len;

	len = sqrt(ft_dot_p(n, n));
	n[0] /= len;
	n[1] /= len;
	n[2] /= len;
}

void	ft_rotation_x(double rad, double *dir)
{
	double y;

	y = dir[1];
	dir[1] = y * cos(rad) + dir[2] * sin(rad);
	dir[2] = -y * sin(rad) + dir[2] * cos(rad);
}

void	ft_rotation_y(double rad, double *dir)
{
	double x;

	x = dir[0];
	dir[0] = x * cos(rad) + dir[2] * sin(rad);
	dir[2] = -x * sin(rad) + dir[2] * cos(rad);
}

