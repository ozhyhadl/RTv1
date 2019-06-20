/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnexti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 08:00:31 by ozhyhadl          #+#    #+#             */
/*   Updated: 2018/11/29 10:06:16 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnexti(t_list *lst, size_t i)
{
	if (!lst)
		return (lst);
	while (i-- > 0 && lst != NULL)
		lst = lst->next;
	return (lst);
}
