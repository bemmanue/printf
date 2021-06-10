
NAME			=	libftprintf.a

SRCS			=	./base/ft_printf.c	\
					./base/ft_parser.c	\
					./base/ft_output.c
SRCS_PATH		=	base/

LIBFT			=	libft.a
LIBFT_PATH		=	libft/

OBJS			=	$(SRCS:.c=.o)
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
AR				=	ar crs

LIBFT_OBJS		=	$(LIBFT_PATH)*.o

LIBFTMAKE		=	$(MAKE) -C $(LIBFT_PATH)

all:				$(NAME)

$(NAME):			$(OBJS) pmake
					$(AR) $(NAME) $(OBJS) $(LIBFT_OBJS)

pmake:
					${LIBFTMAKE}

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJS)

fclean: 			clean
					$(RM) $(NAME) $(LIBFT_PATH)$(LIBFT)

re:         		fclean all
.PHONY:				all clean fclean re