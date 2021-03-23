SRC_NAME = main.c

OBJ_NAME = $(SRC_NAME:.c=.o)

NAME = ft_ping

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/

LIBFT = libft

LIB = $(LIBFT)/libft.a

cc = gcc
CFLAGS = -Wall -Werror -Wextra $(INCLUDES)

INCLUDES = -Iincludes -I$(LIBFT)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

$(NAME):$(OBJ)
#	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(cc) $(CFLAGS) $(INC)-o $@ -c $<

clean:
	rm -f $(OBJ)
	make clean -C libft/ 
ifneq ($(OBJ_PATH), ./)
	rm -rf $(OBJ_PATH)
endif

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
