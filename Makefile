##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## gcc lookalike
##

NAME 	= 	libcuddle.a

SRC 	= 	./src/df_read_csv.c \
			./src/df_write_csv.c \
			./src/df_info.c \
			./src/my_str_to_word_array.c \
			./src/read_bis.c \
			./src/df_shape.c

OBJ 	= 	$(SRC:.c=.o)

CFLAGS 	= 	-Wall -Wextra -I include

AR 		= 	ar rcs
CC 		= 	gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
