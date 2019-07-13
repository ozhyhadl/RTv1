/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:22:10 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/13 03:31:13 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "./libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

# define HEIGHT 720
# define WIDTH 720
# define INF 999999
# define INCOR(mas, x, y, z) mas[0] = x; mas[1] = y; mas[2] = z;
# define ADD3(res, x1, x2) res[0] = x1[0] + x2[0]; res[1] = x1[1] + x2[1]; res[2] = x1[2] + x2[2];
# define SUB3(res, x1, x2) res[0] = x1[0] - x2[0]; res[1] = x1[1] - x2[1]; res[2] = x1[2] - x2[2];
# define MUL3(res, x1, x2) res[0] = x1[0] * x2[0]; res[1] = x1[1] * x2[1]; res[2] = x1[2] * x2[2];
# define MUL13(res, x1, x2) res[0] = x1 * x2[0]; res[1] = x1 * x2[1]; res[2] = x1 * x2[2];
# define GETC(int_color, color) int_color = color[0] * 65536 + color[1] * 256 + color[2];
# define BACKGROUND_COLOR 0xbfbfbf
# define WHITE_COLOR 16119285
# define SKY 49151
# define BLACK 0
# define ANGLE 0.174533
# define KEY_E 14
# define KEY_Q 12
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2


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
	double				center[3];
	int					color[3];
	double				specular;
	int					radius;
	struct s_spher		*next;
}						t_spher;

typedef struct			s_plane
{
	char				*name;
	double				center[3];
	int					color[3];
	double				specular;
	double				vec[3];
	struct s_plane		*next;
}						t_plane;

typedef struct 			s_cilindr
{
	char				*name;
	double				start[3];
	int					color[3];
	double				specular;
	double				vec[3];
	int					radius;
	struct s_cilindr	*next;
}						t_cilindr;

typedef struct 			s_cone
{
	char				*name;
	double				start[3];
	int					color[3];
	double				specular;
	double				vec[3];
	double				tang;
	struct s_cone		*next;
}						t_cone;


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
	t_plane				*plane_choose;
	t_cilindr			*cilindr_choose;
	t_light				*light_choose;
	t_plane				*plane;
	t_cilindr			*cilindr;
	t_cone				*cone;
	t_cone				*cone_choose;
	double				x_angle;
	double				y_angle;
}						t_rtv;

void					ft_main_alg(t_rtv *r);
double					ft_dot_p(double *first, double *second);
double					ft_calc_light(double *p, double *n, t_rtv *r, double *v);
double					*ft_mul13(double x1, double *x2);
double					ft_quadratic(t_rtv *r, double *d, double max, double *p);
void					ft_trace_calc(double *c, double *d, double *t, t_spher *spher);
void					ft_normalization(double *n);
double					all_plane(t_rtv *r, double *d, double *p);
int						ft_plane_light(t_rtv *r, t_plane *figure, double lim, double *d);
double					ft_calc_cilindr(double *d, double *p, t_cilindr *c);
int						ft_trace_r2(t_rtv *r, void *figure, double lim, double *d);
double					all_cilindr(t_rtv *r, double *d, double *p, t_cilindr *c);
int						ft_cilind_light(t_rtv *r, t_cilindr *cilindr, double lim, double *d);
double					all_cone(t_rtv *r, double *d, double *p, t_cone *c);
double					ft_calc_cone( double *d, double *p, t_cone *c);
int						ft_cone_light(t_rtv *r, t_cone *cone, double lim, double *d);
int						check_spher(char **tmp, t_rtv *r);
int						main_parse(char *argv, t_rtv *r);
int						check_plane(char **tmp, t_rtv *r);
int						check_cilindr(char **tmp, t_rtv *r);
int						check_cone(char **tmp, t_rtv *r);
int						check_light(char **tmp, t_rtv *r);
void					check_intensity(t_rtv *r);
void					ft_rotation_x(double rad, double *dir);
void					ft_rotation_y(double rad, double *dir);
#endif