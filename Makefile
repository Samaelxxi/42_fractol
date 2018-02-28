#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/04 13:41:34 by nkolosov          #+#    #+#              #
#    Updated: 2018/01/05 20:20:52 by vpaladii         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = -Llibft/ -lft -lmlx -framework OpenGL -framework AppKit

FILES = src/main.c src/render/thread_pool.c src/render/complex.c \
src/fractals/mandelbrot.c src/events/keyboards_events.c \
src/render/render.c src/initialization.c src/fractals/fractal_funcs.c \
src/helpers.c src/events/mouse_events.c \
src/render/colors.c src/fractals/julia.c src/fractals/burning_ship.c \
src/fractals/tricorn.c src/events/events.c src/fractals/phoenix.c \
src/fractals/mandelquad.c

HEADERS = includes/fractol.h includes/structs.h includes/thread_pool.h \
		includes/constants.h includes/complex.h includes/events.h \
		includes/render.h

OBJDIR = ./obj/
INCLUDES = -I libft/includes/ -I includes/

MAIN_OBJ = $(addprefix obj/,$(notdir $(FILES:.c=.o)))

all: $(NAME)

$(NAME): $(OBJDIR) $(MAIN_OBJ) $(HEADERS) libft/libft.a
	@$(CC) $(CFLAGS) $(MAIN_OBJ) $(INCLUDES) -o $(NAME) $(LIB)
	@echo "\033[32m[$(NAME) is done]\033[00m"

libft/libft.a:
	@make -C libft/

obj/%.o: src/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

obj/%.o: src/*/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@make clean -C libft
	@rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME) $(VIS) $(ME)

re: fclean all
