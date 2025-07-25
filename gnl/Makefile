
NAME = gnl.a
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = get_next_line.c get_next_line_utils.c
INCLUDES = -I.

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean: 
	@$(RM) $(OBJS)

fclean:
	@$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re