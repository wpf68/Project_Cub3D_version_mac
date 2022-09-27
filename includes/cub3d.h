/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:00:33 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/09/27 09:30:43 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifdef __APPLE__
#  define TOUCH_A 0
#  define TOUCH_W 13
#  define TOUCH_S 1
#  define TOUCH_D 2
#  define TOUCH_RIGHT 124
#  define TOUCH_LEFT 123
#  define TOUCH_UP 126
#  define TOUCH_DOWN 125
#  define TOUCH_ESC 53
# else   // LINUX
#  define TOUCH_A 113  // Q
#  define TOUCH_W 122  // Z
#  define TOUCH_S 115  // S
#  define TOUCH_D 100  // D
#  define TOUCH_RIGHT 65363 
#  define TOUCH_LEFT 65361 
#  define TOUCH_UP 65362
#  define TOUCH_DOWN 65364
#  define TOUCH_ESC 65307
# endif






//LIBRAIRIES

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
//# include <X11/keysym.h>   // 
# include <stdio.h> // test
//# include "../mlx_linux/mlx.h"
# include <time.h>


//SIZE 

# define WIDTH 800
# define HEIGTH 600
# define BORDER_X  150 	//  image right
# define BORDER_Y  10	//  image tight
# define HEIGHT_MINI 300  // image right



//COLORS 

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"

//MACROS 

# define WALL '1' 
# define FLOOR '0'
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'

# define WALL_COLOR 0x006C767C
# define FLOOR_COLOR 0x008FB5D1
# define PLAYER_COLOR 0x001093D9
# define NORTH_COLOR 0x00FF0000
# define SOUTH_COLOR 0x0000FF00
# define EAST_COLOR 0x000000FF
# define WEST_COLOR 0x00FFFF00

# define SPEED_MOVIE 2000


//STRUCTURES 

// pour mlx_new_image
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;
//------------------------


typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	double 		speed; 
	double 		apos;
	double 		rotspeed;
	t_vector	pos;	
} t_player;

typedef struct s_map
{
	char	**tab;
	int		lines;
	int		columns;
	int		nb_player;
	int		move;
	t_player p;	
} t_map;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	map_x;
	double	map_y;
	double	delta_x;
	double	delta_y;
	int		stepx;
	int		stepy;
	double	sdist_x;
	double	sdist_y;
	int		hit;
	int		p;
	int		ratio;
	int		side;
	double	p_walldist;
} t_ray;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	t_ray	r;
	t_img	img;  // pour mlx_new_image
	double	*apos_game; // pour radar
} t_game;

// FUNCTIONS

void	init_game(t_game *game);
void	init_map(t_game *game, char *argv);
int		print_map(t_game *game); 
int		main(int argc, char **argv);
void	error_msg(char *msg);
int		ft_close(void);
int		find_player(char p, char *characters);
void	draw_square(t_game *game, int posx, int posy, int side, int color);
void	update(t_game *game, int key);
void	move_player(t_game *game, double nb);
int		count_char(char *str, char c);
void	check_nb_player(t_game *game);
void	init_player_position(t_game *game, char *line, int y);
void	check_files_map(int argc, char **argv);
void	init_var_player(t_game *game);
void    draw_player(t_game *game, int posx, int posy, int side, int color);
int		ft_input(int key, void *param);
void	reprint_pos(t_game *game);
void	print_background(t_game *game);
void	draw_player_p(t_game *game, int x, int y);

// pour mlx_new_image / mlx_get_data_addr
void	img_pix_put(t_game *game, int x, int y, int color);
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
void    init_legend(t_game *game, t_game *legend);
int		anim_legend(t_game *legend);
void    draw_circle(t_game *image, int x, int y, int r, int color);


#endif
