##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## gcc lookalike
##

# Couleurs
RESET   = \033[0m
BOLD    = \033[1m
GREEN   = \033[32m
BLUE    = \033[34m
YELLOW  = \033[33m
RED     = \033[31m

NAME		=	libcuddle.a
EXECUTABLE	=	cuddle

SRC        =    ./src/df_read_csv.c \
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
				./src/read_bis_type.c \
				./src/read_return.c \
				./src/df_describe.c \
                ./src/df_sort.c \
				./src/read_set_dataframe.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -I ./include
DEBUGFLAGS	=	-g

AR		=	ar rcs
CC		=	gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

debug:
	gcc main.c libcuddle.a -I ./include -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(EXECUTABLE)

re: fclean all
