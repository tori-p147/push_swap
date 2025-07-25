NAME = libftprintf.a

SRC_DIR = src
INC_DIR = includes
LIBFT_DIR = ../libft

SRC = $(SRC_DIR)/ft_printf.c $(SRC_DIR)/printf_utils.c
OBJ = $(SRC:.c=.o)
LIBFT_A = $(LIBFT_DIR)/libft.a

CC = cc
COPY = cp
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(LIBFT_A) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#incude libft.a as libftprintf.a 
$(NAME): $(OBJ)
	$(COPY) $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(OBJ)

clean: 
	@$(RM) $(OBJ)

fclean:
	@$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re