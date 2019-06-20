/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:52:06 by ozhyhadl          #+#    #+#             */
/*   Updated: 2018/12/26 02:56:56 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"
# include <stdio.h>
# define BUFF_SIZE 2048
# define CPYCLR(x, y, z) x = y; y = z; ft_strdel(&x);

typedef struct		s_lgnl
{
	int				fd;
	char			*buf;
	struct s_lgnl	*next;
}					t_lgnl;

int					get_next_line(const int fd, char **line);

#endif
