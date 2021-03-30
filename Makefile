# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 15:53:06 by abrabant          #+#    #+#              #
#    Updated: 2021/03/30 13:50:43 by abrabant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT CONFIG

CC					= clang
CFLAGS				= -g -Wall -Wextra -Werror -Wpedantic -Iinclude -Ilibft/include
LD					= clang
LD_FLAGS			= -g -Llibft -lft

CHECKER_TARGET		= checker
PUSH_SWAP_TARGET	= push_swap
TEST_TARGET			= test

# SOURCES

HEADERS				= $(addprefix include/, pshswp_stack.h push_swap.h checker.h)

PSHSWP_STACK		= $(addprefix src/stack/, stack_new.c stack_push.c	\
						stack_pop.c stack_isempty.c stack_peek.c		\
						stack_rotate_up.c stack_rotate_down.c			\
						stack_size.c stack_lookup.c stack_issorted.c	\
						stack_destroy.c)

PUSH_SWAP			= $(addprefix src/push_swap/, generate.c bsort.c)

CHECKER				= $(addprefix src/checker/, execute_instruction_set.c)

CMD					= $(addprefix src/cmd/, cmd_getlist.c cmd.c cmd2.c	\
					  cmd3.c cmd_exec.c)

DEBUG				= $(addprefix src/debug/, print_stacks.c)

SRCS				= $(PSHSWP_STACK) $(CMD) $(PUSH_SWAP) $(CHECKER) $(DEBUG)

OBJS				= $(SRCS:%.c=%.o)

# RULES

all: $(CHECKER_TARGET) $(PUSH_SWAP_TARGET)

$(CHECKER_TARGET): libft/libft.a $(HEADERS) $(OBJS) src/checker/main.o
	@$(LD) -o $(CHECKER_TARGET) $(OBJS) src/checker/main.o $(LD_FLAGS)
	@printf "[\033[1;36mPUSH-SWAP\033[0;m] Generated \033[1;32m$(CHECKER_TARGET)\033[0m\n"

$(PUSH_SWAP_TARGET): libft/libft.a $(HEADERS) $(OBJS) src/push_swap/main.o
	@$(LD) -o $(PUSH_SWAP_TARGET) $(OBJS) src/push_swap/main.o $(LD_FLAGS)
	@printf "[\033[1;36mPUSH-SWAP\033[0;m] Generated \033[1;32m$(PUSH_SWAP_TARGET)\033[0m\n"

$(TEST_TARGET): libft/libft.a $(HEADERS) $(OBJS) src/main.o
	@$(LD) -o $(TEST_TARGET) $(OBJS) src/main.o $(LD_FLAGS)
	@printf "[\033[1;36mPUSH-SWAP\033[0;m] Generated \033[1;32m$(TEST_TARGET)\033[0m\n"

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
	@printf "[\033[1;36mPUSH-SWAP\033[0;m] \033[1;37mCC \033[0;32m$<\033[0m\n"
