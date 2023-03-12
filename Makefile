NAME  =	cub3D

SRCS  =	srcs/mandatory/main_processes/cub3d.c \
		srcs/mandatory/main_processes/launch_game.c	\
		srcs/mandatory/main_processes/load_textures.c	\
		srcs/mandatory/draw_pixels/my_pixel_put.c	\
		srcs/mandatory/display_map/display_map.c	\
		srcs/mandatory/display_map/wall_hit.c	\
		srcs/mandatory/display_minimap/display_minimap.c	\
		srcs/mandatory/display_minimap/get_triangle_coordinates.c	\
		srcs/mandatory/parsing/check_valid_scene.c \
		srcs/mandatory/parsing/fill_matrix.c \
		srcs/mandatory/parsing/check_map_content.c \
		srcs/mandatory/parsing/init_struc.c \
		srcs/mandatory/parsing/parsing_utils.c \
		srcs/mandatory/parsing/init_textures_and_colors.c \
		srcs/mandatory/parsing/get_elements.c	\
		srcs/mandatory/parsing/parsing.c	\
		srcs/mandatory/game_management/move.c	\
		srcs/mandatory/game_management/movement_management.c	\
		srcs/mandatory/game_management/game_management.c	\
		srcs/mandatory/game_management/destroy.c	\
		srcs/mandatory/game_management/check_collision.c	\
		srcs/mandatory/raycasting/raycasting_render.c	\
		srcs/mandatory/raycasting/init_raycast_dir.c	\
		srcs/mandatory/raycasting/get_raycast_dist.c	\
		srcs/mandatory/raycasting/init_data.c	\
		srcs/mandatory/free/free_struc_elements.c	\

SRCS_BONUS  =	srcs/bonus/animation/put_animation_on_texture_bonus.c \
				srcs/bonus/main_processes/cub3d_bonus.c \
				srcs/bonus/main_processes/launch_game_bonus.c	\
				srcs/bonus/main_processes/load_textures_bonus.c	\
				srcs/bonus/draw_pixels/my_pixel_put_bonus.c	\
				srcs/bonus/display_map/display_map_bonus.c	\
				srcs/bonus/display_map/wall_hit_bonus.c	\
				srcs/bonus/display_minimap/display_minimap_bonus.c	\
				srcs/bonus/display_minimap/get_triangle_coordinates_bonus.c	\
				srcs/bonus/parsing/check_valid_scene_bonus.c \
				srcs/bonus/parsing/fill_matrix_bonus.c \
				srcs/bonus/parsing/check_map_content_bonus.c \
				srcs/bonus/parsing/init_struc_bonus.c \
				srcs/bonus/parsing/parsing_utils_bonus.c \
				srcs/bonus/parsing/init_textures_and_colors_bonus.c \
				srcs/bonus/free/free_struc_elements_bonus.c	\
				srcs/bonus/parsing/get_elements_bonus.c	\
				srcs/bonus/parsing/parsing_bonus.c	\
				srcs/bonus/game_management/game_management_bonus.c	\
				srcs/bonus/game_management/move_bonus.c	\
				srcs/bonus/game_management/movement_management_bonus.c	\
				srcs/bonus/game_management/check_collision_bonus.c	\
				srcs/bonus/game_management/door_management_bonus.c	\
				srcs/bonus/game_management/get_new_dir_and_plane_bonus.c	\
				srcs/bonus/game_management/destroy_bonus.c	\
				srcs/bonus/raycasting/raycasting_render_bonus.c	\
				srcs/bonus/raycasting/init_raycast_dir_bonus.c	\
				srcs/bonus/raycasting/get_raycast_dist_bonus.c	\
				srcs/bonus/raycasting/init_data_bonus.c	\

OBJS  =	${SRCS:.c=.o}

OBJS_BONUS  =	${SRCS_BONUS:.c=.o}

CC	  =	clang

CFLAGS =	-Wall -Wextra -Werror -g

LIB   =	-L mlx_linux -lmlx -lXext -lX11 -L libft -lft -lm

HEAD  =	-I mlx_linux -I libft -I includes

RM	  =	rm -f

ifdef	BONUS
				SRCS = 
				SRCS += $(SRCS_BONUS)
endif

.c.o:
			$(CC) $(CFLAGS) $(HEAD) -c  $< -o $(<:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	make -C libft
	make -C mlx_linux
	${CC} ${CFLAGS} ${OBJS} ${HEAD} ${LIB} -o ${NAME}

bonus: ${OBJS_BONUS}
	@make BONUS=1

clean:
	make clean -C libft
	make clean -C mlx_linux
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	make fclean -C libft
	${RM} ${NAME}

re: fclean all

.PHONY: all re clean fclean bonus
