/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_messages_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:04:14 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/19 09:43:12 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_err_str(int err_code)
{
	if (err_code == 1)
		return ("Invalid arguments");
	if (err_code == 2)
		return ("Read / lst creation failed");
	if (err_code == 3)
		return ("Invalid line format");
	if (err_code == 4)
		return ("Invalid number of items");
	if (err_code == 5)
		return ("Map is not rectangular");
	if (err_code == 6)
		return ("Map creation failed");
	if (err_code == 7)
		return ("Invalid path");
	if (err_code == 8)
		return ("Map too big");
	if (err_code == 10)
		return ("Failed init texture / images");
	return ("Unknow error");
}

void	err_print(t_state *game, int err_code)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(get_err_str(err_code), 2); // ------------- to fd 2 ???
	free_all(game); // mlx terminate and close window ??? --- needed ????
	exit(err_code);
}

void	display_end(t_state *game)
{
	int	mid_y;
	int	mid_x;

	mid_y = (game->mlx->height / 2) - 10;
	mid_x = (game->mlx->width / 2) - ((ft_strlen("Game Over [press Esc]") * 10) / 2);
	game->img->end_img = mlx_put_string(game->mlx, "Game Over [press Esc]", mid_x, mid_y);
}

void	display_steps(t_state *game)
{
	char	*temp_1;
	char	*temp_2;

	game->steps += 1;
	if (game->steps_str)
		free(game->steps_str);
	temp_1 = ft_strdup("Steps: ");
	temp_2 = ft_itoa(game->steps);
	game->steps_str = ft_strjoin(temp_1, temp_2);
	free(temp_1);
	free(temp_2);
	redraw_items(game, 'S');
}
