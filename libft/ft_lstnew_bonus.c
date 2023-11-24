/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:57:06 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:36:33 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*create new list. Allocates (malloc) and returns a new element. The variable
'content' is initialized with the value of the paremeter 'content'. The variable
'next' is initialized to NULL.*/

t_list	*ft_lstnew(void *data)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->data = data;
	list->next = NULL;
	return (list);
}
