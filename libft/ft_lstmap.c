/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:43:26 by mumutlu           #+#    #+#             */
/*   Updated: 2023/07/31 17:43:27 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*str;
	t_list	*tmp;
	void	*content;

	if (!lst || !f)
		return (NULL);
	str = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			ft_lstclear(&str, del);
		if (!content)
			return (NULL);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			free(content);
			ft_lstclear(&str, del);
			return (NULL);
		}
		ft_lstadd_back(&str, tmp);
		lst = lst->next;
	}
	return (str);
}
