#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC_KEY 53
# define Q 0
# define Z 13
# define D 2
# define S 1

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include "../mlx.h"

typedef struct s_data
{
    void    *mlx;
    void    *mlx_win;
    int     bits_per_pixel;
    void    *img;
    char    *addr;
    char    **map;
    int     img_width;
    int     img_height;
    int     i;
	int     j;
	int		player_i;
	int		player_j;
    int     col_lenght;
    int     line_lenght;
    int     consummable;
    int     endian;
    int     move;
} t_data;


//check_map_border
int	    ft_check_both_border(char *first, char *last);
int     ft_check_mid_border(char	**map);
int	    check_len(char	**map);
int	    ft_check_border_map(char	**map);
<<<<<<< HEAD
int	ft_check_nl(char	*str);
=======
>>>>>>> e5039f02b7fb641a9c8f999ed8518ce1eef8a494
//check_map_contain
int	    ft_check_consumable(char	**map);
int		ft_check_exit(char   **map);
int		ft_check_player(char   **map);
int 	ft_check_ascii(char   **map);
int 	ft_check_map_contain(char   **map);
//init
void	init_struct(t_data	*data);
void	init_win(t_data	*data);
void	initialize_map(t_data	*data);
void	init_player(t_data	*data);
int		get_player_pos(t_data	*data);
//key_hook
void    ft_close_win(t_data    *data);
int     ft_close_it(t_data    *data);
int     ft_check_cons_for_exit(t_data    *data);
int    	key_hook(int keycode, t_data	*data);
<<<<<<< HEAD
//parsing
=======
//parsing 
>>>>>>> e5039f02b7fb641a9c8f999ed8518ce1eef8a494
char	*ft_read_file(int	fd);
size_t	ft_strlen_tab(char  **map);
char	**parse(char *filename);
//player_move
void    player_move_up(t_data   *data);
void    player_move_left(t_data   *data);
void    player_move_right(t_data   *data);
void    player_move_down(t_data   *data);
//player_move2
void    ft_move_left(t_data   *data);
void    ft_move_right(t_data   *data);
void    ft_move_down(t_data   *data);
void    ft_move_up(t_data   *data);
//so_long
void	put_double_xpm(t_data	*data, char	*path1, char    *path2);
void	put_xpm(t_data	*data, char	*path);
void 	start_it(t_data	*data);
void	make_content(t_data	*data);
//so_utils
int		ft_strncmp(char	*s1, char	*s2, size_t n);
size_t	ft_strlen(char	*str);
int		ft_check_ber(char	*filename);
char	*ft_strjoin(char	*s1, char	*s2);
void	*ft_calloc( size_t	count, size_t	size);
//so_utils2
char	**ft_split(char const  *str, char c);
void    ft_free_map(char    **map);
void	free_wd(int i, char	**ptr);
<<<<<<< HEAD
void    ft_free_map(char    **map);
=======
>>>>>>> e5039f02b7fb641a9c8f999ed8518ce1eef8a494
//so_utils3
void	print_split(char	**map);
int 	ft_strchr(char  *str, int c);
void	put_player_xpm(t_data	*data, char	*path);
void	put_double_player_xpm(t_data	*data, char	*path1, char	*path2);
<<<<<<< HEAD
void	ft_quit_with_msg(char *str);

=======
>>>>>>> e5039f02b7fb641a9c8f999ed8518ce1eef8a494
#endif
