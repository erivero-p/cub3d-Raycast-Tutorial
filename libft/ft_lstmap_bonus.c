/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:41:32 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:36:29 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Iterates the list 'lst' and applies the funtion 'f' to the content of each
element. Creates a new list resulting of the successive applications of the 
funtion 'f'. The 'del' funtion is used to delete the content of element if
needed.*/

t_list	*ft_lmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	while (l)
	{
		tmp = ft_lstnew(f(l->data));
		if (!tmp)
		{
			ft_lstclear(&new, d);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		l = l->next;
	}
	return (new);
}
