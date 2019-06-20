/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:05:42 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/07 19:07:42 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_lgnl	*ft_seelst(t_lgnl **lst, int fd)
{
	t_lgnl	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp != NULL)
		{
			if (tmp->fd == fd)
				return (tmp);
			tmp = tmp->next;
		}
		tmp = (t_lgnl *)malloc(sizeof(t_lgnl));
		tmp->fd = fd;
		tmp->buf = NULL;
		tmp->next = *lst;
		*lst = tmp;
	}
	return (*lst);
}

static char		*ft_start(t_lgnl *lst, char *buf)
{
	char	*main;
	char	*cpy;
	char	*tmpn;
	char	*sub;

	main = ft_strnew(0);
	while ((tmpn = ft_strchr(buf, '\n')) == NULL)
	{
		CPYCLR(cpy, main, ft_strjoin(main, buf));
		ft_strclr(buf);
		if ((read(lst->fd, buf, BUFF_SIZE) == 0))
		{
			ft_strdel(&lst->buf);
			return (main);
		}
	}
	sub = ft_strsub(buf, 0, ft_strlen(buf) - ft_strlen(tmpn));
	CPYCLR(cpy, main, ft_strjoin(main, sub));
	ft_strdel(&sub);
	ft_strdel(&lst->buf);
	lst->buf = ft_strsub(buf, ft_strlen(buf) - ft_strlen(tmpn) + 1, \
	BUFF_SIZE - (ft_strlen(buf) - ft_strlen(tmpn)));
	return (main);
}

int				get_next_line(const int fd, char **line)
{
	static t_lgnl	*lst = NULL;
	t_lgnl			*ltmp;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || read(fd, buf, 0) < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!lst)
	{
		lst = (t_lgnl *)malloc(sizeof(t_lgnl));
		lst->fd = fd;
		lst->buf = NULL;
		lst->next = NULL;
	}
	ltmp = ft_seelst(&lst, fd);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (ltmp->buf && (ft_strlen(ltmp->buf)))
		ft_strcpy(buf, ltmp->buf);
	else if ((read(fd, buf, BUFF_SIZE)) == 0)
	{
		ft_strdel(&ltmp->buf);
		return (0);
	}
	*line = ft_start(ltmp, buf);
	return (1);
}
