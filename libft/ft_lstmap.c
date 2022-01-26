/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szicchie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:33:31 by szicchie          #+#    #+#             */
/*   Updated: 2022/01/25 01:25:28 by szicchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_link;

	new_list = NULL;
	while (lst)
	{
		new_link = ft_lstnew(f(lst->content));
		if (!new_link)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new_list, new_link);
	}
	return (new_list);
}
