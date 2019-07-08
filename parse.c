/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 23:43:32 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/07/03 18:33:46 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <string.h>
int		ft_check_figur(char **tmp, t_rtv *r)
{
	if (ft_strequ(tmp[0], "spher"))
		return(check_spher(tmp, r));
	// else if (ft_strcmp(tmp[1], "plane"))
	// else if (ft_strcmp(tmp[1], "cilindr"))
	// else if (ft_strcmp(tmp[1], "cone"))
	// else
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
	
	}
	return(0);
}