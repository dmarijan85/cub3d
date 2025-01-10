/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:17:25 by mclaver-          #+#    #+#             */
/*   Updated: 2024/01/20 19:17:27 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst2;

	while (lst && *lst)
	{
		lst2 = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst2;
	}
}
