##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## gcc lookalike
##

NAME 	= 	cuddle

SRC 	= 	df_read_csv.c \
			df_write_csv.c \
			my_str_to_word_array.c \

OBJ = $(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I include

all: $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
