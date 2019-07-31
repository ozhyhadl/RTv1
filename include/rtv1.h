/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:22:10 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/18 20:13:01 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "./libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

# define HEIGHT 720
# define WIDTH 720
# define INF 999999
# define INCOR(mas, x, y, z) mas[0] = x; mas[1] = y; mas[2] = z;
# define ADD3(res, x1, x2) res[0] = x1[0] + x2[0]; ADD3_2(res, x1, x2);
# define ADD3_2(res, x1, x2) res[1] = x1[1] + x2[1]; res[2] = x1[2] + x2[2];
# define SUB3(res, x1, x2) res[0] = x1[0] - x2[0]; SUB3_2(res, x1, x2);
# define SUB3_2(res, x1, x2) res[1] = x1[1] - x2[1]; res[2] = x1[2] - x2[2];
# define MUL3(res, x1, x2) res[0] = x1[0] * x2[0]; MUL3_2(res, x1, x2);
# define MUL3_2(res, x1, x2) res[1] = x1[1] * x2[1]; res[2] = x1[2] * x2[2];
# define MUL13(res, x1, x2) res[0] = x1 * x2[0]; MUL13_2(res, x1, x2);
# define MUL13_2(res, x1, x2) res[1] = x1 * x2[1]; res[2] = x1 * x2[2];
# define GETC(i, color) i = color[0] * 65536 + color[1] * 256 + color[2];
# define WHITE_COLOR 16119285
# define BLACK 0
# define ANGLE 0.0349066
# define KEY_E 14
# define KEY_Q 12
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

typedef struct			s_wspace
{
	void				*ptr;
	void				*win;
	void				*img;
	char				*addr;
	int					bit;
	int					line_s;
	int					endia;
}						t_wspace;

typedef struct			s_cam
{
	double				o[3];
}						t_cam;

typedef struct			s_spher
{
	double				center[3];
	int					color[3];
	double				specular;
	int					radius;
	struct s_spher		*next;
}						t_spher;

typedef struct			s_plane
{
	double				center[3];
	int					color[3];
	double				specular;
	double				vec[3];
	struct s_plane		*next;
}						t_plane;

typedef struct			s_cilindr
{
	double				start[3];
	int					color[3];
	double				specular;
	double				vec[3];
	int					radius;
	struct s_cilindr	*next;
}						t_cilindr;

typedef struct			s_cone
{
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
	t_cone				*cone_choose;
	t_plane				*plane;
	t_cilindr			*cilindr;
	t_cone				*cone;
	t_spher				*figure_choose;
	double				x_angle;
	double				y_angle;
}						t_rtv;

void					ft_main_alg(t_rtv *r);
double					ft_dot_p(double *first, double *second);
double					all_spher(t_rtv *r, double *d, double max, double *p);
void					ft_calc_spher(double *c, double *d, double *t, \
	t_spher *spher);
void					ft_normalization(double *n);
double					all_plane(t_rtv *r, double *d, double *p);
int						ft_plane_light(t_rtv *r, t_plane *figure, \
	double lim, double *d);
double					ft_calc_cilindr(double *d, double *p, t_cilindr *c);
int						ft_spher_light(t_rtv *r, void *figure, \
	double lim, double *d);
double					all_cilindr(t_rtv *r, double *d, double *p, \
	t_cilindr *c);
int						ft_cilind_light(t_rtv *r, t_cilindr *cilindr, \
	double lim, double *d);
double					all_cone(t_rtv *r, double *d, double *p, t_cone *c);
double					ft_calc_cone(double *d, double *p, t_cone *c);
int						ft_cone_light(t_rtv *r, t_cone *cone, \
	double lim, double *d);
int						check_spher(char **tmp, t_rtv *r);
int						check_plane(char **tmp, t_rtv *r);
int						check_cilindr(char **tmp, t_rtv *r);
int						check_cone(char **tmp, t_rtv *r);
int						check_light(char **tmp, t_rtv *r);
void					check_intensity(t_rtv *r);
void					ft_rotation_x(double rad, double *dir);
void					ft_rotation_y(double rad, double *dir);
int						check_cam(char **tmp, t_rtv *r);
void					ft_pixel_put(t_wspace *ws, int x, int y, int color);
int						ft_get_int_color(t_rtv *r, double *tmp_d, \
	double *normal, double *p);
int						cmx(char **tmp);
int						c_rgb(int r, int g, int b);
int						ft_start_parse(int argc, char **argv, t_rtv *rtv);
void					check_intensity(t_rtv *r);
int						ft_close(void *param);
int						ft_key_r(int key, t_rtv *rtv);

#endif
