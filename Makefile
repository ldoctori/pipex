CC = gcc

NAME = pipex

SOURCE = pipex.c ft_strchr.c ft_split.c ft_strdup.c \
			ft_strlen.c ft_strncmp.c ft_strstr.c ft_strjoin.c \
			find_paths.c helpers.c

OBJ = $(SOURCE:.c=.o)

%.o: %.c
	$(CC) -I -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	  $(CC) $(OBJ) -o $(NAME)

clean:
	rm -f *.o

fclean:
	rm -f *.o $(NAME)

re: fclean all
