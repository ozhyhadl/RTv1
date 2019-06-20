/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 06:44:14 by ozhyhadl          #+#    #+#             */
/*   Updated: 2018/11/29 06:56:02 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list *lst, t_list *newlst)
{
	if (!lst || !newlst)
		return ;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = newlst;
}
