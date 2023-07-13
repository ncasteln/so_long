/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:41:56 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/13 15:46:29 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

/* General lst function iteration to fill with ft_printf() when needed,
depending on the content */
void	lst_print(t_list *lst)
{
	int i = 0;
	while (lst && lst->next)
	{
		lst = lst->next;
		i++;
	}
}
