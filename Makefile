# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 16:22:19 by tayeo             #+#    #+#              #
#    Updated: 2022/10/24 18:16:09 by tayeo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = so_long

SRC = src/main.c src/check_map.c src/check_map2.c src/check_file.c src/draw.c src/hook.c src/init_rsc.c
OBJ = ${SRC:.c=.o}

FLAG = -Werror -Wall -Wextra -D BUFFER_SIZE=1
MFLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB) so_long.h
	$(CC)  $(OBJ)  $(LIB) $(MFLAG) -o $(NAME)

$(LIB):
	make -C libft

%.o: %.c
	$(CC) $(FLAG) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C libft


fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

n: $(SRC)
	norminette -R CheckForbiddenSourceHeader src libft
	norminette -R CheckDefine so_long.h

.PHONY: all clean fclean re n
