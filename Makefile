# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 09:55:41 by nlesage           #+#    #+#              #
#    Updated: 2022/12/26 16:29:00 by nlesage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_SERV	= serveur_main.c 

SRCS_CLIENT	= client_main.c client_other.c

SRCS_SERV_B	= serveur_main_bonus.c 

SRCS_CLIE_B	= client_main_bonus.c client_other_bonus.c

NAME_SE		= serveur

NAME_CL		= client

NAME_CL_B	= client_bonus

NAME_S_B	= serveur_bonus

LIBFT_DIR	= Libft/

LIBFT		= libft.a

HEADERS		= Includes/

FLAGS		= -Wall -Wextra -Werror

OBJS_SERV	= ${SRCS_SERV:.c=.o}

OBJS_CLIENT	= ${SRCS_CLIENT:.c=.o}

OBJS_SER_B	= ${SRCS_SERV_B:.c=.o}

OBJS_CLI_B	= ${SRCS_CLIE_B:.c=.o}

CC			= cc

.c.o:
			${CC} ${FLAGS} -I${HEADERS} -c $< -o ${<:.c=.o}

${NAME_SE}:	${OBJS_SERV} ${OBJS_CLIENT}
			make -C ${LIBFT_DIR}
			${CC} ${FLAGS} -I${HEADERS} -o ${NAME_SE} ${OBJS_SERV} ${LIBFT_DIR}${LIBFT}
			${CC} ${FLAGS} -I${HEADERS} -o ${NAME_CL} ${OBJS_CLIENT} ${LIBFT_DIR}${LIBFT}

${NAME_S_B}: ${OBJS_SER_B} ${OBJS_CLI_B}
			make -C ${LIBFT_DIR}
			${CC} ${FLAGS} -I${HEADERS} -o ${NAME_S_B} ${OBJS_SER_B} ${LIBFT_DIR}${LIBFT}
			${CC} ${FLAGS} -I${HEADERS} -o ${NAME_CL_B} ${OBJS_CLI_B} ${LIBFT_DIR}${LIBFT}

all:		${NAME_SE}

bonus:		${NAME_S_B}

client:		${NAME_CL}

clean_lib:	
			make clean -C ${LIBFT_DIR}

fclean_lib:	
			make fclean -C ${LIBFT_DIR}

clean:		clean_lib
			rm -f ${OBJS_SERV} ${OBJS_CLIENT} ${OBJS_SER_B} ${OBJS_CLI_B}

fclean:		clean fclean_lib
			rm -f ${NAME_SE} ${NAME_CL} ${NAME_S_B} ${NAME_CL_B}

re:			fclean all

.PHONY:		clean, fclean, re, bonus, add, clean_lib, fclean_lib
