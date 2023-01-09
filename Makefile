SRCS         = main.cpp
                    

OBJS         =     ${SRCS:.cpp=.o}

CC             =     c++
CFLAGS        =     -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g3
RM            =     rm -f
NAME        =     container

all:             ${NAME}

.cpp.o:
				${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}
                
$(NAME):         $(OBJS)
				${CC} $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS):     vector.hpp Vector_iterator.hpp Iterator_traits.hpp reverse_iterator.hpp map.hpp r
clean:
				${RM} ${OBJS}

fclean:         clean
				${RM} ${NAME}

re:             fclean all

.PHONY:            all clean fclean re%  