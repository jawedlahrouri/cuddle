##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## gcc lookalike
##

NAME		=	libcuddle.a
EXECUTABLE	=	cuddle

SRC		=	./src/df_read_csv.c \
			./src/df_write_csv.c \
			./src/df_info.c \
			./src/df_head.c \
			./src/df_tail.c \
			./src/df_free.c \
			./lib/my/my_str_to_word_array.c \
			./src/read_bis.c \
			./src/df_shape.c \
			./src/df_get_value.c \
			./lib/my/my_copy_word_in_array.c \
			./src/df_filter.c \
			./main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -I include

AR		=	ar rcs
CC		=	gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

debug:
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(EXECUTABLE)

re: fclean all
