/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:02:21 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/19 09:42:14 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_list	*lines_to_lst(const char *path)
{
	int		fd;
	char	*s;
	t_list	*lst;
	t_list	*new_node;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lst = NULL;
	s = get_next_line(fd);
	while (s)
	{
		new_node = ft_lstnew(s);
		if (!new_node)
			return (ft_lstclear(&lst, lst_delnode), NULL);
		ft_lstadd_back(&lst, new_node);
		s = get_next_line(fd);
	}
	close(fd);
	if (!lst)
		return (ft_lstclear(&lst, lst_delnode), NULL);
	return (lst);
}

int	validate(int argc, char **argv, t_state *game)
{
	t_list	*lst;

	if (!(argc == 2) || !(nc_is_valid_ext(argv[1], ".ber")))
		err_print(game, 1);
	lst = lines_to_lst(argv[1]);
	if (!lst)
		err_print(game, 2);
	is_valid_format(lst, game);
	game->map = lst_to_dptr(lst, ft_lstsize(lst));
	ft_lstclear(&lst, lst_delnode);
	if (!game->map)
		return (err_print(game, 6), 6);
	is_valid_path(game);
	return (1);
}
