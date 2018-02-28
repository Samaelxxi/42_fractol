/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 03:33:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/01/06 03:33:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structs.h"

t_list		*ft_lst_copy(t_list *lst)
{
	t_list *new_lst;

	new_lst = NULL;
	if (lst)
		while (lst)
		{
			ft_lstappend(&new_lst, ft_lstnew(lst->content, lst->content_size));
			lst = lst->next;
		}
	return (new_lst);
}
