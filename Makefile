# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcosta-f <fcosta-f@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 18:41:42 by fcosta-f          #+#    #+#              #
#    Updated: 2023/08/07 18:42:39 by fcosta-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= push_swap.c push_swap_utils.c

OBJS	= $(SRCS:.c=.o)

DEPS	= $(OBJS:.o=.d)

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -MMD -I

NAME		= push_swap.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
		$(RM) $(NAME)
		@$(MAKE) -C include/libft

re: fclean all

.PHONY: clean all fclean re