/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc_move_calc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:20:43 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/17 12:34:11 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	find_move(t_state *game, t_char *next_npc)
{
	int	rn;

	rn = rand() % 4;
	if (rn == 0)
		next_npc->y = -1;
	if (rn == 1)
		next_npc->x = 1;
	if (rn == 2)
		next_npc->y = 1;
	if (rn == 3)
		next_npc->x = -1;
	while (!is_possible_move(game, next_npc->y, next_npc->x, 'N')) // assumes that NPC can move also diagonal
	{
		rn = rand() % 4;
		if (rn == 0)
			next_npc->y = -1;
		if (rn == 1)
			next_npc->x = 1;
		if (rn == 2)
			next_npc->y = 1;
		if (rn == 3)
			next_npc->x = -1;
	}
}

static void	swap_position(t_state *game, int next_y, int next_x)
{
	game->map[game->n.y][game->n.x] = '0';
	game->n.y = next_y;
	game->n.x = next_x;
	game->map[next_y][next_x] = 'N';
}

void	move_npc(t_state *game)
{
	t_char next_npc;

	next_npc.y = 0;
	next_npc.x = 0;
	find_move(game, &next_npc);
	swap_position(game, game->n.y + next_npc.y, game->n.x + next_npc.x);
	redraw_items(game, 'N');
}
