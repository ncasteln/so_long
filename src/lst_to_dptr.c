/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_dptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:15:17 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/13 15:38:20 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Convert a lst whose content is a char *s to a dptr who points to each str */
char	**lst_to_dptr(t_list *lst, int y)
{
	char	**map;
	int		i;

	map = ft_calloc ((y + 1), sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < y)
	{
		map[i] = ft_calloc (ft_strlen(lst->content), sizeof(char));
		if (!map[i])
			return (nc_dptr_free(map), NULL); // free(everything)
		ft_strlcpy(map[i], lst->content, ft_strlen(lst->content));
		lst = lst->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}
