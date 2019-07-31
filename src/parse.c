/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 23:43:32 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/18 20:16:58 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"

int		ft_check_figur(char **tmp, t_rtv *r)
{
	if (ft_strequ(tmp[0], "spher"))
		return (check_spher(tmp, r));
	else if (ft_strequ(tmp[0], "plane"))
		return (check_plane(tmp, r));
	else if (ft_strequ(tmp[0], "cylindr"))
		return (check_cilindr(tmp, r));
	else if (ft_strequ(tmp[0], "cone"))
		return (check_cone(tmp, r));
	else if (ft_strequ(tmp[0], "light"))
		return (check_light(tmp, r));
	else if (ft_strequ(tmp[0], "cam"))
		return (check_cam(tmp, r));
	else if (ft_strequ(tmp[0], "\n"))
		return (0);
	return (-1);
}

int		main_parse(char *argv, t_rtv *r)
{
	char	*line;
	char	**tmp;
	int		fd;

	if ((fd = open(argv, O_RDONLY)) < 0 || read(fd, 0, 0) < 0)
	{
		close(fd);
		return (-1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		if (ft_check_figur(tmp, r))
		{
			ft_del_two_char(&tmp);
			ft_strdel(&line);
			return (1);
		}
		ft_strdel(&line);
		ft_del_two_char(&tmp);
	}
	check_intensity(r);
	return (0);
}

void	ft_read_man(void)
{
	int		fd;
	char	buf;

	if ((fd = open("man/man", O_RDONLY)) < 0)
	{
		close(fd);
		ft_putstr("*ERROR MAN* file man not found\n");
	}
	if (read(fd, 0, 0) < 0)
	{
		ft_putstr("*ERROR MAN* invalid file\n");
	}
	while (read(fd, &buf, 1) == 1)
	{
		ft_putchar(buf);
	}
}

int		ft_start_parse(int argc, char **argv, t_rtv *rtv)
{
	int		i;

	if (argc != 2)
	{
		ft_putstr("*ERROR ARGC* Wrong number of arguments (argc != 2)\n");
		return (1);
	}
	if (ft_strequ(argv[1], "man"))
	{
		ft_read_man();
		system("leaks -q a.out");
		exit(0);
	}
	if ((i = main_parse(argv[1], rtv)) != 0)
	{
		if (i == -1)
			ft_putstr(\
			"*ERROR FILE OR FILE NOT FOUND* Usage\"./RTv1 <name file>\" \n");
		else
			ft_putstr("*ERROR MAP* Read man \"./RTv1 man\" \n");
		return (1);
	}
	return (0);
}
