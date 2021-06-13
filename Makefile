
NAME			=	libftprintf.a

SRCS			=	./base/ft_printf.c	\
					./base/ft_parsing.c	\
					./base/ft_output.c	\
					./base/ft_dash.c
SRCS_PATH		=	base/

LIBFT			=	libft.a
LIBFT_PATH		=	libft/

OBJS			=	$(SRCS:.c=.o)
HEAD			=	./includes/ft_printf.h
LIBFT_OBJS		=	$(LIBFT_PATH)*.o
LIBFTMAKE		=	$(MAKE) -C $(LIBFT_PATH)

CFLAGS			=	-Wall -Wextra -Werror -c
CC				=	gcc
RM				=	rm -f
AR				=	ar -rcs

all:				$(NAME)

.c.o: 				$(HEAD)
					$(CC) $(CFLAGS) $< -o $@

$(NAME):			$(OBJS) make
					$(AR) $(NAME) $(OBJS) $(LIBFT_OBJS)

make:
					$(LIBFTMAKE)

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJS)

fclean: 			clean
					$(RM) $(NAME) $(LIBFT_PATH)$(LIBFT)

re:         		fclean all
.PHONY:				all clean fclean re