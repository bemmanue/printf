
NAME		=	libft.a

SRCS		=	ft_itoa.c			\
				ft_high_x_itoa.c	\
				ft_low_x_itoa.c		\
				ft_unsigned_itoa.c	\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_atoi.c			\
				ft_strlen.c			\
				ft_count.c

OBJS		=	$(SRCS:.c=.o)
HEAD		=	libft.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -c
RM			=	rm -f
AR			=	ar -rcs

all: 			$(NAME)

.c.o: 			$(HEAD)
				$(CC) $(CFLAGS) $< -o $@

$(NAME): 		$(OBJS) $(HEAD)
				$(AR) $(NAME) $?

clean:
				$(RM) $(OBJS)

fclean: 		clean
				$(RM) $(NAME)

re:				fclean all
.PHONY:			all clean fclean re