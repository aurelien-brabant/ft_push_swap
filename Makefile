# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 15:53:06 by abrabant          #+#    #+#              #
#    Updated: 2021/03/28 16:41:44 by abrabant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT CONFIG

CC					= clang
CFLAGS				= -Wall -Wextra -Werror -Wpedantic -Iinclude -Ilibft/include
LD					= clang
LD_FLAGS			= -Llibft -lft

CHECKER_TARGET		= checker
PUSH_SWAP_TARGET	= push_swap
TEST_TARGET			= test

# SOURCES

HEADERS				= $(addprefix include/, pshswp_stack.h)

PSHSWP_STACK		= $(addprefix src/stack/, stack_new.c stack_push.c	\
						stack_pop.c stack_isempty.c stack_peek.c		\
						stack_rotate_up.c stack_rotate_down.c)

CMD					= $(addprefix src/cmd/, cmd_getlist.c cmd.c cmd2.c	\
					  cmd_exec.c)

SRCS				= $(PSHSWP_STACK) $(CMD)

OBJS				= $(SRCS:%.c=%.o)

# RULES

all: $(TEST_TARGET)

$(TEST_TARGET): libft/libft.a $(HEADERS) $(OBJS) src/main.o
	@$(LD) -o $(TEST_TARGET) $(OBJS) src/main.o $(LD_FLAGS)
	@echo -e "[\033[1;36mPUSH-SWAP\033[0;m] Generated \033[1;32m$(TEST_TARGET)\033[0m"

norm:
	@norminette src
	@norminette include

clean:
	@$(RM) $(OBJS) src/main.o

fclean: clean
	@$(RM) $(TEST_TARGET) $(PSHSWP_TARGET) $(CHECKER_TARGET)

re: fclean all

# Compile libft

libft/libft.a:
	make -C libft

.PHONY: clean fclean re

%.o:%.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo -e "[\033[1;36mPUSH-SWAP\033[0;m] \033[1;37mCC \033[0;32m$<\033[0m\r"
