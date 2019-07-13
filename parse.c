/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 23:43:32 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/13 03:01:23 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <string.h>
int		ft_check_figur(char **tmp, t_rtv *r)
{
	if (ft_strequ(tmp[0], "spher"))
		return (check_spher(tmp, r));
	else if (ft_strequ(tmp[0], "plane"))
		return (check_plane(tmp, r));
	else if (ft_strequ(tmp[0], "cilindr"))
		return (check_cilindr(tmp, r));
	else if (ft_strequ(tmp[0], "cone"))
		return (check_cone(tmp, r));
	else if (ft_strequ(tmp[0], "light"))
		return (check_light(tmp, r));
	else if (ft_strequ(tmp[0], "\n"))
		return (0);
	return (-1);
	
}

int		main_parse(char *argv, t_rtv *r)
{
	char *line;
	char **tmp;
	int fd;

	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0 )
	{
		tmp = ft_strsplit(line, ' ');
		if (ft_check_figur(tmp, r))
			return(1);
		ft_del_two_char(&tmp);
	}
	check_intensity(r);
	return(0);
}