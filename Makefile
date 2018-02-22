# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/19 14:34:26 by pnardozi          #+#    #+#              #
#    Updated: 2018/02/22 10:30:47 by pnardozi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LEM_IN = lem-in

LIBFT_INCLUDES_PATH = ./libft/libft/includes/
PRINTF_INCLUDES_PATH = ./libft/printf/includes/

LEM_IN_SRCS_PATH = ./l_m/srcs/
LEM_IN_INCLUDES_PATH = ./l_m/includes/
LEM_IN_OBJ_PATH = ./l_m/obj/

LEM_IN_SRCS_NAME =	lem_in.c \
					algo.c \
					bfs.c \
					road.c \
					road2.c \
		   			list.c \
		   			list2.c \
					list3.c \
					list4.c \
					push_ants.c \
					push_ants2.c \
					display.c \
					display2.c \
					parse.c \
					parse2.c \
					parse_get_room.c \
					parse_get_tunnel.c \
					parse_get_ants.c \
					lm_ft.c

LEM_IN_OBJ_NAME =$(LEM_IN_SRCS_NAME:.c=.o)

LIBFT_INC = $(addprefix -I,$(LIBFT_INCLUDES_PATH))
PRINTF_INC = $(addprefix -I,$(PRINTF_INCLUDES_PATH))

LEM_IN_SRCS = $(addprefix $(LEM_IN_SRCS_PATH),$(LEM_IN_SRCS_NAME))
LEM_IN_OBJ = $(addprefix $(LEM_IN_OBJ_PATH),$(LEM_IN_OBJ_NAME))
LEM_IN_INC = $(addprefix -I,$(LEM_IN_INCLUDES_PATH))

LIB_PATH = ./libft/
LIB_NAME = libftprintf.a
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

RED = \033[31m
GREEN = \033[32m
END = \033[0m

all: $(LIB_NAME) $(LEM_IN)

$(LIB_NAME):
	make -C $(LIB_PATH)

$(LEM_IN): $(LEM_IN_OBJ)
	$(CC) $(CFLAGS) -o $(LEM_IN) $(LEM_IN_OBJ) $(LIB)
	@echo "$(GREEN)LEM_IN READY$(END)"

$(LEM_IN_OBJ_PATH)%.o: $(LEM_IN_SRCS_PATH)%.c
	@mkdir -p $(LEM_IN_OBJ_PATH)
	$(CC) -c $(CFLAGS) $(LEM_IN_INC) $(LIBFT_INC) $(PRINTF_INC) -o $@ -c $<

clean:
	make clean -C $(LIB_PATH)
	/bin/rm -rf $(LEM_IN_OBJ_PATH)
	@echo "$(RED)LEM_IN OBJECTS REMOVE$(END)"

fclean: clean
	make fclean -C $(LIB_PATH)
	/bin/rm -rf $(LEM_IN)
	@echo "$(RED)LEM_IN REMOVE$(END)"

re: fclean all

.PHONY: all clean fclean re
