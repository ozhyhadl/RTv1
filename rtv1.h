/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:22:10 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/06/20 20:51:59 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "./libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# define HEIGHT 720
# define WIDTH 720
# define INF 10000
# define INCOR(mas, x, y, z) mas[0] = x; mas[1] = y; mas[2] = z;
# define ADD3(res, x1, x2) res[0] = x1[0] + x2[0]; res[1] = x1[1] + x2[1]; res[2] = x1[2] + x2[2];
# define SUB3(res, x1, x2) res[0] = x1[0] - x2[0]; res[1] = x1[1] - x2[1]; res[2] = x1[2] - x2[2];
# define MUL3(res, x1, x2) res[0] = x1[0] * x2[0]; res[1] = x1[1] * x2[1]; res[2] = x1[2] * x2[2];
# define MUL13(res, x1, x2) res[0] = x1 * x2[0]; res[1] = x1 * x2[1]; res[2] = x1 * x2[2];
# define GETC(int_color, color) int_color = color[0] * 65536 + color[1] * 256 + color[2];
# define BACKGROUND_COLOR 0xbfbfbf
# define WHITE_COLOR 16119285
typedef struct	s_wspace
{
	void		*ptr;
	void		*win;
}				t_wspace;

typedef struct			s_cam
{
	double				o[3];
}						t_cam;

typedef struct			s_spher
{
	char				*name;
	int					center[3];
	int					color[3];
	int					specular;
	double				t;
	int					radius;
	struct s_spher		*next;
}						t_spher;

typedef struct			s_plane
{
	char				*name;
	int					center[3];
	int					color[3];
	int					specular;
	double				t;
	int					normal[3];
}						t_plane;

typedef struct			s_light
{
	char				type;
	double				intensity;
	int					pos[3];
	struct s_light		*next;
}						t_light;

typedef struct			s_rtv
{
	t_wspace			*ws;
	t_cam				*cam;
	t_spher				*spher;
	t_light				*light;
	t_spher				*spher_choose;
	t_light				*light_choose;
	t_plane				*plane;
}						t_rtv;

void					ft_main_alg(t_rtv *r);
double					ft_dot_p(double *first, double *second);
double					ft_calc_light(double *p, double *n, t_rtv *r, double *v);
double					*ft_mul13(double x1, double *x2);
t_spher					*ft_quadratic(t_rtv *r, double *d, int min, double *lim);
void					ft_trace_calc(double *c, double *d, double *t, t_spher *spher);
void					ft_normalization(double *n);
double					ft_plane_calc(t_rtv *r, double *d);
int						ft_plane_light(t_rtv *r, t_plane *figure, double lim, double *d);

#endif