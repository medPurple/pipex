################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := pipex
CC        := clang
FLAGS    := -Wall -Wextra -Werror 
LIB       := -I./libft
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS :=         srcs/mandatory/child.c \
                srcs/mandatory/free_pipe.c \
                srcs/mandatory/utils.c \

                          
OBJS        := $(SRCS_LIBFT:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

$(LFT):		
			@make -s -C libft
${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} srcs/pipex.c -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:      @ ${RM} *.o */*.o */*/*.o
			@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


