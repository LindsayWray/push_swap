# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lwray <lwray@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/28 21:01:17 by lwray         #+#    #+#                  #
#    Updated: 2021/06/29 17:27:26 by lwray         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
HEADERFILES := srcs/push_swap.h
SRCS := srcs/main.c \
		srcs/create_stack.c \
		srcs/clean.c \
		srcs/push.c \
		srcs/rotate.c \
		srcs/reverse_rotate.c \
		srcs/swap.c \
		srcs/parsing.c \
		srcs/print_output.c \
		srcs/check_order.c \
		srcs/sort_array.c \
		srcs/sort_stack.c \
		srcs/operations_list.c \
		srcs/optimise.c

FLAGS := -Wall -Wextra -Werror
OBJFILES := $(SRCS:srcs/%.c=obj/%.o)
LIBFT := libft/

all: $(NAME)

$(NAME): $(OBJFILES)
	@make -C $(LIBFT)
	gcc -o $@ $^ -L $(LIBFT) -lft

obj/%.o: srcs/%.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	gcc -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJFILES)
	@make fclean -C $(LIBFT)

fclean: clean
	rm -f ${NAME}

re: fclean all

norm:
	norminette $(SRCS) $(HEADERFILES)
	make norm -C $(LIBFT)

.PHONY: all clean fclean re norm


