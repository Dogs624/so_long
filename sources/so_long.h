/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:58:54 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/20 13:13:17 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BACKGROUND_IMG "./img/ground.png"
# define MAP "./error.ber"
# define MAP_SIZE 32
# define WALL_IMG "./img/wall.png"
# define PLAYER_IMG "./img/player.png"
# define EXIT_IMG "./img/exit.png"
# define COLLECT_IMG "./img/collect.png"
# define EXTENSION_FILE ".ber"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_img
{
	int		height;
	int		width;
	void	*img;
}				t_img;

typedef struct s_win
{
	int		height;
	int		width;
	int		raw_height;
	int		raw_width;
	void	*win;
}				t_win;

typedef struct s_vars
{
	void	*mlx;
	t_win	win;
	char	**map;
	int		nbr_mov;
	void	*background_img;
	void	*wall_img;
	void	*exit_img;
	void	*collect_img;
	void	*player_img;
}				t_vars;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

t_vars	create_window(char *file);
t_img	create_image(t_vars vars, char *path);
void	create_bckgrnd(t_vars vars);
void	create_visual_map(t_vars vars);
int		get_width_map(char *file);
int		get_height_map(char *file);
char	**create_map(char *file, t_vars vars);
t_pos	get_pos_player(t_vars vars);
void	go_up(t_vars *vars);
void	go_down(t_vars *vars);
void	go_left(t_vars *vars);
void	go_right(t_vars *vars);
int		nbr_collect_left(t_vars vars);
int		close_escape(t_vars *vars);
int		on_exit(t_vars *vars);
int		on_collectible(t_vars *vars, int pos_y, int pos_x, t_pos current_pos);
int		on_wall(void);
int		on_nothing(t_vars *vars, int pos_y, int pos_x, t_pos current_pos);
int		check_rectangle(t_vars vars);
int		surrounded_wall(t_vars vars);
int		check_contain(t_vars vars);
int		error_handling(t_vars vars);
int		check_size_window(t_vars vars);
void	keep_one_player(t_vars *vars);
int		check_args(int argc, char **argv);

#endif
