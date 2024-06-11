SRC				=	ft_striteri.c \
					ft_memmove.c \
					ft_memcpy.c \
					ft_memchr.c \
					ft_memset.c \
					ft_calloc.c \
					ft_bzero.c \
					ft_memcmp.c \
					ft_strlen.c \
					ft_atoi.c \
					ft_tolower.c \
					ft_toupper.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_strnstr.c \
					ft_strmapi.c \
					ft_substr.c \
					ft_strtrim.c \
					ft_strjoin.c \
					ft_split.c \
					ft_strrchr.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_itoa.c	\
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_putchar_fd.c\
					ft_putstr_fd.c\
					ft_putendl_fd.c\
					ft_putnbr_fd.c\
					ft_strncmp.c\
					get_next_line_bonus.c\
					get_next_line_utils_bonus.c
BONUS			=	ft_lstnew.c\
					ft_lstsize.c\
					ft_lstlast.c\
					ft_lstadd_back.c\
					ft_lstdelone.c\
					ft_lstclear.c\
					ft_lstiter.c\
					ft_lstmap.c\
					ft_lstadd_front.c
BONUS_OBJS		= $(BONUS:.c=.o)
SRCS			= ${addprefix ${PRE}, ${SRC}} ${addprefix ${PRE}, ${BONUS_SRC}}
OBJS			= ${SRCS:.c=.o}
PRE				=	./
HEAD			=	libft.h get_next_line_bonus.h
NAME			=	libft.a
AR				=	ar rc
LIB				=	ranlib
CC				=	cc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror
all:			${NAME}
.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS} ${BONUS_OBJS}
				${AR} ${NAME} ${OBJS} ${BONUS_OBJS}
				${LIB} ${NAME}
re:				fclean all
bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
clean:
				${RM} ${OBJS} $(BONUS_OBJS)
fclean:			clean
				${RM} ${NAME}