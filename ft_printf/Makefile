NAME = libftprintf.a

LIBFT = libft

CC = cc

INCLUDES = -Iincludes

LINKERS = -L$(LIBFT) -lft

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard srcs/*.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

AR = ar rcs

RM = rm -f

CP = cp

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

libft:
	$(MAKE) -C $(LIBFT)

$(NAME): $(OBJS)
	$(MAKE) libft
	$(CP) $(LIBFT)/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME) libft.a

re: fclean all

.PHONY: all libft clean fclean re
