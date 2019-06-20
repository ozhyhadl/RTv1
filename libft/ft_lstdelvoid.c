/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelvoid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 07:45:13 by ozhyhadl          #+#    #+#             */
/*   Updated: 2018/11/29 09:58:18 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_if_first(t_list *lst, t_list *tmp)
{
	lst = lst->next;
	free(tmp);
	tmp = lst;
	tmp = NULL;
	return (lst);
}

static t_list	*ft_lstdelmy(t_list *lst, t_list *tmp, int i)
{
	t_list	*del;

	del = ft_lstnexti(tmp, i - 1);
	del->next = lst->next;
	del = lst;
	lst = lst->next;
	free(del);
	del = NULL;
	return (lst);
}

t_list			*ft_lstdelvoid(t_list *lst, void const *c)
{
	t_list	*tmp;
	int		i;

	if (!lst || !c)
		return (lst);
	tmp = lst;
	i = 0;
	while (lst != NULL)
	{
		if (ft_memcmp(lst->content, c, lst->content_size) == 0 && i != 0)
			lst = ft_lstdelmy(lst, tmp, i);
		else if (ft_memcmp(lst->content, c, lst->content_size) == 0)
		{
			lst = ft_if_first(lst, tmp);
			tmp = lst;
		}
		else
		{
			lst = lst->next;
			i++;
		}
	}
	return (tmp);
}
