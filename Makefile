# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 11:30:39 by abrabant          #+#    #+#              #
#    Updated: 2021/05/18 17:24:34 by abrabant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT CONFIG

CC					= clang
# -Wall -Wextra -Werror -Wpedantic
CFLAGS				= -g  -Iinclude -Ilibft/include
LD					= clang
LD_FLAGS			= -g -Llibft -lft

CHECKER_TARGET		= checker
PUSH_SWAP_TARGET	= push_swap

# SOURCES

HEADERS				= $(addprefix include/pushswap/, stack.h pscore.h checker.h errcode.h debug.h parsing.h)

STACK				= $(addprefix src/stack/, stack_new.c stack_push.c		\
						stack_push_from_to.c stack_isempty.c stack_peek.c	\
						stack_rotate_up.c stack_rotate_down.c				\
						stack_size.c stack_lookup.c stack_issorted.c		\
						stack_search.c stack_swap_top.c stack_destroy.c	\
						stack_min_max.c stack_to_array.c)

CORE				= $(addprefix src/core/, generate.c \
						outcmd.c gsv.c sort3.c exit_program.c \
						sort_utils.c sort_utils2.c sort100.c sort500.c bounds.c)

CHECKER				= $(addprefix src/checker/, execute_instruction_set.c)
 
CMD					= $(addprefix src/cmd/, cmd_getlist.c cmd.c cmd2.c	\
					  cmd3.c cmd_exec.c)

PARSING				= $(addprefix src/parsing/, parse_cli.c)

DEBUG				= $(addprefix src/debug/, print_stacks.c)

SRCS				= $(STACK) $(CMD) $(CHECKER) $(DEBUG) $(CORE) $(PARSING)

OBJS				= $(SRCS:%.c=%.o)

# RULES

all: $(CHECKER_TARGET) $(PUSH_SWAP_TARGET)

$(CHECKER_TARGET): libft/libft.a $(HEADERS) $(OBJS) src/checker/main.o
	@$(LD) -o $(CHECKER_TARGET) $(OBJS) src/checker/main.o $(LD_FLAGS)
	@printf "[\033[1;36mPUSH-SWAP\033[0;m] Generated \033[1;32m$(CHECKER_TARGET)\033[0m\n"

$(PUSH_SWAP_TARGET): libft/libft.a $(HEADERS) $(OBJS) src/core/main.o
	@$(LD) -o $(PUSH_SWAP_TARGET) $(OBJS) src/core/main.o $(LD_FLAGS)
	@printf "[\033[1;36mPUSH-SWAP\033[0;m] Generated \033[1;32m$(PUSH_SWAP_TARGET)\033[0m\n"

norm:
	@norminette src
	@norminette include

clean:
	@$(RM) $(OBJS) src/core/main.o src/checker/main.o

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
