# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lwray <lwray@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/28 21:01:17 by lwray         #+#    #+#                  #
#    Updated: 2021/07/13 14:44:32 by lwray         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CHECKER := checker
HEADERFILES := srcs/push_swap.h
PUSH_SWAP_SRCS := srcs/main.c \
				srcs/make_chunks.c \
				srcs/stack_sort.c \
				srcs/stack_sort_pt2.c \
				srcs/optimizer.c \
				srcs/small_stack_sort.c \
				srcs/optimize_and_print.c
CHECKER_SRCS := srcs/checker.c
SHARED_SRCS := 	srcs/create_stack.c \
				srcs/push.c \
				srcs/rotate.c \
				srcs/reverse_rotate.c \
				srcs/swap.c \
				srcs/operations_list.c \
				srcs/error_handler.c \
				srcs/clean.c \
				srcs/check_order.c \
				srcs/parsing.c

FLAGS := -Wall -Wextra -Werror
OBJFILES := $(PUSH_SWAP_SRCS:srcs/%.c=obj/%.o) $(SHARED_SRCS:srcs/%.c=obj/%.o)
CHECKER_OBJFILES := $(CHECKER_SRCS:srcs/%.c=obj/%.o) $(SHARED_SRCS:srcs/%.c=obj/%.o)
LIBFT := libft/

all: $(NAME) $(CHECKER)

$(NAME): $(OBJFILES) 
	@make -C $(LIBFT)
	gcc -o $@ $^ -L $(LIBFT) -lft

$(CHECKER): $(CHECKER_OBJFILES)
	@make -C $(LIBFT)
	gcc -o $@ $^ -L $(LIBFT) -lft

obj/%.o: srcs/%.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	gcc -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJFILES) $(CHECKER_OBJFILES)
	@make fclean -C $(LIBFT)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

norm:
	norminette $(PUSH_SWAP_SRCS) $(CHECKER_SRCS) $(SHARED_SRCS) $(HEADERFILES)
	make norm -C $(LIBFT)

.PHONY: all clean fclean re norm
