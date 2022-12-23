# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 09:55:41 by nlesage           #+#    #+#              #
#    Updated: 2022/12/23 14:28:08 by nlesage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_SERV	= serveur_main.c 

SRCS_CLIENT	= client_main.c

SRCS_BONUS	= ${SRCS_SERV}

NAME_SE		= serveur

NAME_CL		= client

NAME_B		= bo

LIBFT_DIR	= Libft/

LIBFT		= libft.a

HEADERS		= Includes/

FLAGS		= -Wall -Wextra -Werror

OBJS_SERV	= ${SRCS_SERV:.c=.o}

OBJS_CLIENT	= ${SRCS_CLIENT:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

CC			= cc

.c.o:
			${CC} ${FLAGS} -I${HEADERS} -c $< -o ${<:.c=.o}

${NAME_SE}:	${OBJS_SERV}
			make -C ${LIBFT_DIR}
			${CC} ${FLAGS} -I${HEADERS} -o ${NAME_SE} ${OBJS_SERV} ${LIBFT_DIR}${LIBFT}

${NAME_CL}:	${OBJS_CLIENT}
			make -C ${LIBFT_DIR}
			${CC} ${FLAGS} -I${HEADERS} -o ${NAME_CL} ${OBJS_CLIENT} ${LIBFT_DIR}${LIBFT}

${NAME_B}:	${OBJS_BONUS}
			${CC} ${FLAGS} -I${HEADERS} -o ${NAME_B} ${OBJS_BONUS} ${LIBFT_DIR}${LIBFT}

all:		${NAME_SE}

bonus:		${NAME_B}

client:		${NAME_CL}

clean_lib:	
			make clean -C ${LIBFT_DIR}

fclean_lib:	
			make fclean -C ${LIBFT_DIR}

clean:		clean_lib
			rm -f ${OBJS_SERV} ${OBJS_CLIENT} ${OBJS_BONUS}

fclean:		clean fclean_lib
			rm -f ${NAME_SE} ${NAME_CL} ${NAME_B}

re:			fclean all

.PHONY:		clean, fclean, re, bonus, add, clean_lib, fclean_lib
