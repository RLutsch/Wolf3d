
NAME = 	  wolf3d

SRC = 	  wolf3d.c			\
		  lets_get_wolfy.c	\
		  draw.c			\
		  controls.c		\
		  assimilate.c		\
		  barginbin.c		\
		  libft/libft.a		\



SRCO = 	  wolf3d.o			\
		  lets_get_wolfy.o	\
		  draw.o			\
		  controls.o		\
		  assimilate.o		\
		  barginbin.o		\

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make  -C libft/
	gcc $(CFLAGS) $(SRC) -o $(NAME) -L/usr/local/lib -lmlx -L/usr/lib/X11 -lXext -lX11 -L/usr/local/lib -lm
	clear
	@ echo Made All for Wolf3D

clean:
	make -C libft/ clean
	rm -f $(SRCO)
	clear
	@ echo Made Clean for Wolf3D

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)
	clear
	@ echo Made fclean for Wolf3D

re: fclean all
	@ echo Remade Wolf3D
