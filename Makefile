SRCS	= push_swap.c push_swap_utils.c

OBJS	= $(SRCS:.c=.o)

DEPS	= $(OBJS:.o=.d)

CC		= cc
RM		= 
