# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 18:41:42 by fcosta-f          #+#    #+#              #
#    Updated: 2023/08/09 20:05:33 by fcosta-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= push_swap.c

OBJS	= $(SRCS:.c=.o)

DEPS	= $(OBJS:.o=.d)

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -g -MMD

NAME		= push_swap

all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C libft/
	@${MAKE} -C libft bonus
	$(CC) $(FLAGS) libft/libft.a $(OBJS) -o ${NAME}

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
		$(RM) $(NAME)
		@$(MAKE) -C libft

re: fclean all

.PHONY: clean all fclean re