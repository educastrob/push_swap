# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: educastro <educastro@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 15:49:20 by educastro         #+#    #+#              #
#    Updated: 2024/03/13 04:28:54 by educastro        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

AR = ar -rc

SRCS_DIR = ./srcs/operations \
		   ./srcs/utils \
		   ./srcs/algorithms \

OBJS_DIR = ./objs
INC_DIR = ./inc
LIBFT_DIR = ./libft
LIBFT = libft.a
BONUS_DIR = ./checker_bonus

# SRCS = ./srcs/algorithms/main.c \
# 	   ./srcs/operations/push_pop.c \
# 	   ./srcs/operations/reverse_rotate_stack.c \
# 	   ./srcs/operations/swap.c \
# 	   ./srcs/utils/check_utils.c \
# 	   ./srcs/utils/free.c \
# 	   ./srcs/utils/min_mid_max.c \
# 	   ./srcs/utils/my_atoi.c \
# 	   ./srcs/utils/stack_utils.c \
# 	   ./srcs/algorithms/a_to_b.c \
# 	   ./srcs/algorithms/b_to_a.c \
# 	   ./srcs/algorithms/fives.c \
# 	   ./srcs/algorithms/three_a.c \
# 	   ./srcs/algorithms/three_b.c \
# 	   ./srcs/algorithms/under_three.c

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

RM = rm -f

all : $(NAME)

bonus : re
	echo "Compiling bonus checker..."
	@$(MAKE) fclean -C $(BONUS_DIR)
	@$(MAKE) -C $(BONUS_DIR)
	@cp checker_bonus/checker ./checker
	echo "bonus checker has been compiled..."

$(NAME) : $(OBJS)
	echo "Compling libft..."
	@$(MAKE) -C $(LIBFT_DIR)
	echo "Libft has been compiled..."
	echo "Compiling push_swap"
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft
	echo "push_swap has been compiled..."

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I $(INC_DIR) -I$(LIBFT_DIR) -c $^

clean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C checker_bonus fclean
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)
	@if [ -f ./checker ]; then $(RM) ./checker; fi;

re : fclean all