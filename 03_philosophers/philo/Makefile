# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 21:29:08 by hkwon             #+#    #+#              #
#    Updated: 2021/07/14 18:15:41 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -lbsd
# CFLAGS = -g3 -fsanitize=address

AR = ar rcs
RM = rm -f

INCLUDE_DIR = ./includes
OBJS_DIR = ./objs
SRCS_DIR = ./srcs

SRCS = $(addprefix $(SRCS_DIR)/, \
		main.c philo.c thread.c routine.c util.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c \
	$(SRCS_DIR)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ -lpthread

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I$(INCLUDE_DIR) -c $^

clean :
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
