# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 12:46:54 by hkwon             #+#    #+#              #
#    Updated: 2022/03/21 14:01:53 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = inception
DOCKER_COMP = docker-compose
YML = srcs/docker-compose.yml
COMPOSE = $(DOCKER_COMP) -p $(NAME) -f $(YML)
DATA_PATH = /home/hkwon/data
DB_DATA = /home/hkwon/data/db
WP_DATA = /home/hkwon/data/wp
# DB_DATA = ./db
# WP_DATA = ./wp

all: up

up: makedir
	$(COMPOSE) up -d

down:
	$(COMPOSE) down

fdown:
	$(COMPOSE) down --rmi all --volumes

start:
	$(COMPOSE) start

stop:
	$(COMPOSE) stop

build:
	$(COMPOSE) build

fbuild:
	$(COMPOSE) build --no-cache

logs:
	$(COMPOSE) logs

clear:
	rm -rf $(DB_DATA) $(WP_DATA)

makedir:
	mkdir $(DB_DATA) $(WP_DATA)

fclean : fdown clear

re : fclean all

.PHONY: all up down fdown start stop build fbuild makedir clear fclean re
