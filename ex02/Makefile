SRCS	= 	main.cpp \
			Bureaucrat.cpp \
			Form.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp
CFLAGS	= -Werror -Wextra -Wall -std=c++98 -pedantic
CC		= g++-12
NAME	= bureaucrat
OBJS	= ${SRCS:.cpp=.o}
RM		= rm -f

all:	${NAME}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

run:
	./${NAME}

mrun: all run

.PHONY: all clean fclean re run mrun