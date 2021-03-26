# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hguini <hguini@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 17:57:30 by hguini            #+#    #+#              #
#    Updated: 2021/03/25 00:54:40 by hguini           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	main.c \
		parse/ft_if_c.c \
		parse/ft_if_ea.c \
		parse/ft_if_f.c \
		parse/ft_if_map.c \
		parse/ft_if_no.c \
		parse/ft_if_r.c \
		parse/ft_if_s.c \
		parse/ft_if_so.c \
		parse/ft_if_we.c \
		parse/parse.c \
		parse/validate_map.c \
		parse/check_file.c \
		parse/side_player.c \
		parse/player_position.c \
		parse/check_valid.c \
		parse/filling_texture_img.c \
		sprites/draw_sprites.c \
		sprites/sort_sprites.c \
		movements/movements.c \
		movements/move_w.c \
		movements/move_s.c \
		movements/move_d.c \
		movements/move_a.c \
		movements/rotation_right.c \
		movements/rotation_left.c \
		raycast/draw_map.c \
		raycast/utils.c \
		raycast/my_pixel_put.c \
		raycast/my_pixel_take.c \
		screenshot/screenshot.c \
		
MLX = -lmlx -framework OpenGL -framework AppKit

OBJSRCS = $(SRCS:.c=.o)

DSRCS = $(SRCS:.c=.d)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

INCLUDE = cub3d.h

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I$(INCLUDE) -MMD -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJSRCS) $(INCLUDE)
	@echo "\033[0;36m[Deleting the previous cube...]"
	@rm -rf cub3D
	@echo "\033[0;36m[Libft compilation...]"
	@$(MAKE) -C ./libft
	@echo "\033[0;36m[mlx compilation...]"
	@$(MAKE) -C ./mlx
	@rm -rf $(DSRCS)
	@echo "\033[0;36m[Cub3D compilation...]"
	$(CC) $(CFLAGS) $(OBJSRCS) -I./include ./libft/libft.a libmlx.dylib -I./mlx $(MLX) -o $(NAME)
	@echo "\033[0;36m[Done!]"

test:
		gcc libft/libft.a parse/*.c libft/libft.a -Iinclude -Imlx -Lmlx -lmlx  -framework Appkit -framework OpenGL -o $(NAME) \
		-Wall -Wextra

clean :
	rm -rf $(OBJSRCS)
	rm -rf $(DSRCS)
	$(MAKE) clean -C ./libft

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	rm -rf cub3d.bmp

re : fclean all

bonus : $(NAME)

.PHONY: clean fclean re all
