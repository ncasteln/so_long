/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:17:53 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 13:45:59 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	state_print(t_state *game)
{
	ft_printf("_________ GAME STATE _________\n");
	ft_printf("Player [%d][%d]\n", game->data->p.y, game->data->p.x);
	ft_printf("Exit: [%d]\n", game->data->c);
	ft_printf("Collectibles: [%d]\n", game->data->c);
	ft_printf("Enemy: [%d]\n", game->data->n);
	ft_printf("Last was exit: [%d]\n", game->data->is_exit);
	ft_printf("\nMap\n");
	if (game->data->map)
		nc_dptr_print(game->data->map);
	else
		ft_printf("*** No map to print ***");
}
