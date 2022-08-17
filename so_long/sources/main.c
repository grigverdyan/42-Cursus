/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:44:34 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/17 18:30:44 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "utils.h"
#include "map_parser.h"
#include "game.h"
#include "map_utils.h"
#include "rendering.h"

int	main(int argc, char **argv)
{
	t_engine	game;

	init_game(argc, argv, &game);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		map_free(game.map.height, &game.map);
		error_message("[MLX ERROR]: can't do mlx_init!");
	}
	get_imgs(&game, &game.imgs);
	game.win = mlx_new_window(game.mlx, game.map.width * IMG_SIZE,
			game.map.height * IMG_SIZE + MOVES, "I LOVE MLX LEAKS");
	if (!game.win)
	{
		map_free(game.map.height, &game.map);
		error_message("[MLX ERROR]: can't open mlx window!");
	}
	mlx_key_hook(game.win, move_player, &game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_hook(game.win, 17, 0, on_destroy_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}

void	init_game(int argc, char **argv, t_engine *game)
{
	game->moves = 0;
	game->c_collect = 0;
	args_valid(argc, argv);
	game->map = parse_map(argv[1]);
	get_player_coords(game);
}
