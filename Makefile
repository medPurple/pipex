NAME	= pipex
CC		= @cc
FLAGS	= -Wall -Werror -Wextra -g3
LIB		= libft/libft.a

OBJ		= $(SRC:.c=.o)

SRC		= srcs/mandatory/ft_access.c \

all :	$(LIB) $(NAME)

$(NAME) :		$(OBJ)
	@ar rc ${NAME} ${OBJS}$(LIB)
	@echo "\nCompilation pipex [OK]\n"

%.o:%.c
			$(CC) $(FLAGS)  -c $< -o ${<:.c = .o}
clean :
			@make -s $@ -C libft
			@rm -rf $(OBJ)

fclean :	clean
			@make -s $@ libft
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re