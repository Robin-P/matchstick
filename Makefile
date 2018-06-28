##
## Makefile for  in /home/robin/delivery/CPE/CPE_2016_matchstick
## 
## Made by Robin Pronnier
## Login   <robin@epitech.net>
## 
## Started on  Fri Jun  9 18:20:18 2017 Robin Pronnier
## Last update Sat Jun 10 22:26:35 2017 Robin Pronnier
##

CC	= gcc

RM	= rm -f

NAME	= matchstick

CFLAGS	+= -I include -W -Wall -Wextra -Werror

SRCS	= src/main.c \
	  src/matchstick.c		\
	  src/useful_game_functions.c	\
	  src/bot.c			\
	  src/bot_attacks.c		\
	  src/change_base.c		\
	  src/my_map.c			\
	  src/functions.c		\
	  src/check_start.c		\
	  src/get_next_line.c		\
	  printf/my_revstr.c		\
          printf/my_putchar.c		\
          printf/my_put_nbr.c		\
          printf/my_short.c		\
          printf/my_long.c		\
          printf/my_put_nbrv2.c		\
          printf/my_putstr.c		\
          printf/my_putstrv2.c		\
          printf/my_strlen.c		\
          printf/my_base.c		\
          printf/my_type.c		\
          printf/my_printf.c		\

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIBS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
