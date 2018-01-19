# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 17:28:03 by pnardozi          #+#    #+#              #
#    Updated: 2017/12/19 19:08:20 by pnardozi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

LIBFT_SRCS_PATH = ./libft/srcs/
LIBFT_INCLUDES_PATH = ./libft/includes/
LIBFT_OBJ_PATH = ./libft/obj/

PRINTF_SRCS_PATH = ./printf/srcs/
PRINTF_INCLUDES_PATH = ./printf/includes/
PRINTF_OBJ_PATH = ./printf/obj/

LIBFT_SRCS_NAME = ft_atoi.c \
				  ft_is_sort.c \
				  get_next_line_one_file.c \
				  ft_eol.c \
				  ft_is_in_pos.c \
				  ft_is_in_at.c \
				  ft_itoc.c \
				  ft_count_var.c \
				  ft_wputchar.c \
				  ft_strdupw.c\
				  ft_wctoi.c \
				  ft_unsigned_itoa.c \
				  ft_strcap.c \
				  ft_puttab.c \
				  ft_putlong.c \
				  ft_long_atoi.c \
				  ft_long_itoa.c \
				  ft_decim.c \
				  ft_ctoi.c \
				  ft_count_unsigned_var.c \
				  get_next_line_multi.c \
				  ft_bzero.c \
				  ft_countsizeword.c \
				  ft_countword.c \
				  ft_isalnum.c \
				  ft_isalpha.c \
				  ft_isascii.c \
				  ft_isdigit.c \
				  ft_isprint.c \
				  ft_iswp.c \
				  ft_itoa.c \
				  ft_lstadd.c \
				  ft_lstdel.c \
				  ft_lstdelone.c \
				  ft_lstiter.c \
				  ft_lstmap.c \
				  ft_lstnew.c \
				  ft_memalloc.c \
				  ft_memccpy.c \
				  ft_memchr.c \
				  ft_memcmp.c \
				  ft_memcpy.c \
				  ft_memdel.c \
				  ft_memmove.c \
				  ft_memset.c \
				  ft_nbdigit.c \
				  ft_putchar.c \
				  ft_putchar_fd.c \
				  ft_putendl.c \
				  ft_putendl_fd.c \
				  ft_putnbr.c \
				  ft_putnbr_fd.c \
				  ft_putstr.c \
				  ft_putstr_fd.c \
				  ft_strcat.c \
				  ft_strcat_p.c \
				  ft_strchr.c \
				  ft_strclr.c \
				  ft_strcmp.c \
				  ft_strcpy.c \
				  ft_strcpy_p.c \
				  ft_strdel.c \
				  ft_strdup.c \
				  ft_strequ.c \
				  ft_striter.c \
				  ft_striteri.c \
				  ft_strjoin.c \
				  ft_strlcat.c \
				  ft_strlen.c \
				  ft_strlen_p.c \
				  ft_strlen_at_p.c \
				  ft_strmap.c \
				  ft_strmapi.c \
				  ft_strncat.c \
				  ft_strncmp.c \
				  ft_strncpy.c \
				  ft_strnequ.c \
				  ft_strnew.c \
				  ft_strnstr.c \
				  ft_strrchr.c \
				  ft_strsplit.c \
				  ft_strstr.c \
				  ft_strsub.c \
				  ft_strtrim.c \
				  ft_tolower.c \
				  ft_swap.c \
				  ft_push.c \
				  ft_toupper.c 

PRINTF_SRCS_NAME = 	ft_unicode.c \
					ft_convert_o.c \
					ft_convert_u.c \
					ft_convert_i.c \
					ft_convert_d.c \
					ft_convert_x.c \
					ft_convert_x_base.c \
					ft_convert_p.c \
					ft_convert_c.c \
					ft_convert_c_flags.c \
					ft_convert_s.c \
					ft_convert_smaj.c \
					ft_convert_smaj_flags.c \
					ft_convert_percent.c \
					ft_s_remp_right.c \
					ft_s_remp_left.c \
					ft_smaj_remp_right.c \
					ft_remp_right.c \
					ft_remp_left.c \
					ft_unsigned_remp.c \
					ft_unsigned_remp2.c \
					printf.c \
					printf2.c \
					ft_verif_before_print.c \
					select.c \
					select_widht.c \
					select_modifier.c \
					select_precision.c \
					read_params.c \
					ft_base_remp.c \
					ft_base_hex_remp_r.c \
					ft_base_hex_remp_l.c \
					ft_smaj_remp_left.c \
					ft_split_printf.c \
					ft_split_printf2.c \
					ft_split_printf3.c 

LIBFT_OBJ_NAME = $(LIBFT_SRCS_NAME:.c=.o)

PRINTF_OBJ_NAME = $(PRINTF_SRCS_NAME:.c=.o)

LIBFT_SRCS = $(addprefix $(LIBFT_SRCS_PATH),$(LIBFT_SRCS_NAME))
LIBFT_OBJ = $(addprefix $(LIBFT_OBJ_PATH),$(LIBFT_OBJ_NAME))
LIBFT_INC = $(addprefix -I,$(LIBFT_INCLUDES_PATH))

PRINTF_SRCS = $(addprefix $(PRINTF_SRCS_PATH,$(PRINTF_SRCS_NAME)))
PRINTF_OBJ = $(addprefix $(PRINTF_OBJ_PATH),$(PRINTF_OBJ_NAME))
PRINTF_INC = $(addprefix -I,$(PRINTF_INCLUDES_PATH))

LIB = libft.a

COMPILED = $(LIBFT_OBJ) $(PRINTF_OBJ)

RED = \033[31m
GREEN = \033[32m
END = \033[0m

all: $(NAME)

$(NAME): $(COMPILED)
	ar rc $(LIB) $(LIBFT_OBJ)
	ranlib $(LIB)
	@echo "$(GREEN)LIBFT READY$(END)"
	ar rc $(NAME) $(PRINTF_OBJ) $(LIBFT_OBJ)
	ranlib $(NAME)
	@echo "$(GREEN)PRINTF READY$(END)"

$(LIBFT_OBJ_PATH)%.o: $(LIBFT_SRCS_PATH)%.c
	@mkdir -p $(LIBFT_OBJ_PATH)
	$(CC) -c $(CFLAGS) $(LIBFT_INC) -o $@ -c $<

$(PRINTF_OBJ_PATH)%.o: $(PRINTF_SRCS_PATH)%.c
	@mkdir -p $(PRINTF_OBJ_PATH)
	$(CC) -c $(CFLAGS) $(PRINTF_INC) $(LIBFT_INC) -o $@ -c $<

clean:
	/bin/rm -rf $(LIBFT_OBJ_PATH) $(PRINTF_OBJ_PATH)
	@echo "$(RED)LIBFT AND PRINTF OBJECTS REMOVE$(END)"

fclean: clean
	/bin/rm -rf $(LIB) $(NAME)
	@echo "$(RED)LIBFT.A AND PRINTF.A REMOVE$(END)"

re: fclean all

.PHONY: all clean fclean re
