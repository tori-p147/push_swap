NAME = push_swap

SRC_DIR = src
VAL_DIR = validation_utils
SORT_DIR = sort_utils
INC_DIR = includes
LIBFT_DIR = libft
GNL_DIR = gnl
PRINTF_DIR = printf

SRC = main.c \
		$(SRC_DIR)/error.c \
		$(SRC_DIR)/parser.c \
		$(SRC_DIR)/free_utils.c \
		$(SRC_DIR)/sorter.c \
		$(SRC_DIR)/lincked_list.c \
		$(SRC_DIR)/$(VAL_DIR)/validation_main.c \
		$(SRC_DIR)/$(VAL_DIR)/validation_utils.c \
		$(SRC_DIR)/$(SORT_DIR)/sort_main.c \
		$(SRC_DIR)/$(SORT_DIR)/sort_small.c \
		$(SRC_DIR)/$(SORT_DIR)/push.c \
		$(SRC_DIR)/$(SORT_DIR)/rotate.c \
		$(SRC_DIR)/$(SORT_DIR)/swap.c \
		$(SRC_DIR)/$(SORT_DIR)/reverse_rotate.c

OBJ = $(SRC:.c=.o)
LIBFT_A = $(LIBFT_DIR)/libft.a
GNL_A = $(GNL_DIR)/gnl.a
PRINTF_A = $(PRINTF_DIR)/libftprintf.a

CC = cc
COPY = cp
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(PRINTF_DIR)/includes

all: $(LIBFT_A) $(GNL_A) $(PRINTF_A) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

#make libft.a
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

#make gnl.a
$(GNL_A):
	$(MAKE) -C $(GNL_DIR)

#make libftprintf.a
$(PRINTF_A):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(LIBFT_A) $(GNL_A) $(PRINTF_A)
	$(CC) $(OBJ) $(LIBFT_A) $(GNL_A) $(PRINTF_A) $(INCLUDES) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	@$(RM) $(OBJ)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	@$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
