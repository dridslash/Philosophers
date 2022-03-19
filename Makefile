CC = cc

CFLAGS = -Wall -Werror -Wextra 

SRCS =	ft_atoi.c \
	   ft_isdigit.c \
	   ft_itoa.c \
	   ft_strdup.c \
	   ft_strlen.c \
	   get_time.c \
	   philosophers.c \
	   imp_usleep.c \
	   creat_mutex.c \
	   destroy_mutex.c \
	   observe_manage_thread.c \
	   set_rules.c \
	   ft_check_input.c \
	   ft_is_empty.c \
	   ft_isalpha.c \
	   ft_isdigit_imp.c \
	   check_rules.c \
	   main_helper.c \
	   print_msg.c


OBJS = ${SRCS:.c=.o}

ARV = ar -rcs

NAME = philo

REM = rm -f

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean :
	${REM} ${OBJS}

fclean : clean
	${REM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
