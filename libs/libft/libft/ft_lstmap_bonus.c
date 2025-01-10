/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:17:53 by mclaver-          #+#    #+#             */
/*   Updated: 2024/01/20 19:17:55 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*flst;
	t_list	*save;

	if (!lst || !(lst->content))
		return (NULL);
	flst = ft_lstnew(f(lst->content));
	if (!flst)
		return (NULL);
	save = flst;
	lst = lst->next;
	while (lst)
	{
		save->next = ft_lstnew(f(lst->content));
		if (!save->next)
		{
			ft_lstclear(&flst, del);
			return (NULL);
		}
		save = save->next;
		lst = lst->next;
	}
	return (flst);
}
