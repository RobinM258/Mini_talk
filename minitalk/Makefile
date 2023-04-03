# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romartin <romartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 11:58:08 by romartin          #+#    #+#              #
#    Updated: 2023/03/30 17:52:34 by romartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client 
NAME_SERVER = server 
SRC_CLIENT = client.c ft_atoi.c
SRC_SERVER = server.c
OBJS_CLIENT	=  ${SRC_CLIENT:.c=.o}
OBJS_SERVER	=  ${SRC_SERVER:.c=.o}
FLAG    = -Wall -Werror -Wextra

all : ${NAME_CLIENT} ${NAME_SERVER}


$(NAME_CLIENT) : $(OBJS_CLIENT) 
		@ar rc $(NAME_CLIENT) $(OBJS_CLIENT) 
		@gcc -o ./client $(FLAG) $(NAME_CLIENT)
$(NAME_SERVER) : $(OBJS_SERVER) 
		@ar rc $(NAME_SERVER) $(OBJS_SERVER) 
		@gcc -o ./server $(FLAG) $(NAME_SERVER)
.c.o	:
		@gcc  -c $^ $(FLAG)

clean :
		@rm -f ${OBJS_CLIENT}
		@rm -f ${OBJS_SERVER}

fclean : clean
		@rm -f ${NAME_CLIENT}
		@rm -f ${NAME_SERVER}

re : fclean all