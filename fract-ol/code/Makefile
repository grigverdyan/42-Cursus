NAME = fractol

LIBFT = libft

MLX = mlx

LIB = $(LIBFT)/libft.a $(MLX)/libmlx.a

CC = cc

MLXOBJS = $(wildcard $(MLX)/*.o)

CFLAGS = -Wall -Wextra -Werror  -I includes -Imlx

SRCS = main.c

OBJS = $(subst .c,.o,$(SRCS))

LINKS = -L libft \
    -L mlx \
    -l mlx -l ft -framework OpenGL -framework Appkit

RM = rm -rf

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

.DEFAULT_GOAL = all

$(LIB):
	@$(MAKE) -C $(LIBFT) bonus
	@$(MAKE) -C $(MLX) -s
	@echo " \033[0;34m" "Compiling libraries"

all: $(LIB) $(NAME)
	@echo " \033[38;2;255;127;80m" "Done"

$(NAME): $(OBJS)
	@$(CC) $(SRCS) -o $(NAME) $(CFLAGS) $(LINKS)


clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(RM) $(MLXOBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(MLX) clean -s
	@echo " \033[0;31m" "Clean up"

re: fclean all

.PHONY: all clean fclean re
