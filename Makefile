NAME = wolf3d

CC = cc

INC = -I includes/ -I libft/includes/

CFLAGS = -Wall -Werror -Wextra

DFLAGS = -pedantic -g -ggdb

LFLAGS = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

FILES =	lets_get_wolfy.c\
		wolf3d.c\
		draw.c\
		controls.c\
		assimilate.c\
		barginbin.c\

SRCDIR = src
OBJDIR = obj

SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : libft $(OBJDIR) $(OBJ)
		@make -C libft/ all
		@$(CC) $(CFLAGS) $(INC) -o $@ $(OBJ) $(LFLAGS)
		@echo "\033[4;32m$@\033[0m created !"

$(OBJDIR) :
		@/bin/mkdir $(OBJDIR);			\
		for DIR in $(SRCDIR);			\
		do								\
			/bin/mkdir $(OBJDIR)/$$DIR;	\
		done							\

$(addprefix $(OBJDIR)/, %.o) : %.c 
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@/bin/echo -n "Creating objects in $(addprefix $(OBJDIR)/, $(SRCDIR)) : "
	@echo "\033[1;33m$(subst $(SRCDIR)/, , $(<:.c=.o))\033[0m"

run : removed
		@/usr/bin/clear
		@./$(NAME)

clean :
		@/bin/rm -rf $(OBJDIR) a.out.dSYM
		@/bin/rm -f a.out
		@echo "\033[1;30m$(OBJDIR)\033[0m removed !"

fclean : clean
		@/bin/rm -f $(NAME)
		@echo "\033[1;30m$(NAME)\033[0m removed !"

libft :
		@make -C libft all

libfclean :
		@make -C libft fclean

norm:
	@clear
	@$(call colour colourecho2, "Norminette: ")
	@norminette $(FILES)



libre :
		@make -C libft re
		@make re

re : fclean all 

debug : CFLAGS += $(DFLAGS)
debug : re

.PHONY : all clean fclean re
