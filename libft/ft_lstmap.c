/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:48:25 by bepifani          #+#    #+#             */
/*   Updated: 2021/10/11 21:07:52 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*b;

	b = 0;
	if (!lst)
		return (NULL);
	while (lst)
	{
		a = ft_lstnew(f(lst->content));
		if (!a)
		{
			ft_lstclear(&b, del);
			return (NULL);
		}
		ft_lstadd_back(&b, a);
		lst = lst->next;
	}
	return (b);
}
