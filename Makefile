NAME		= cub3D

SRCS	=	cub3d.c \
			ft_drawing.c \
			ft_raycast.c \
			ft_screenshot.c \
			ft_sprites.c \
			map_checker.c \
			parse_tools.c \
			parser_params.c \
			parse1.c \
			parser_colors.c \
			key.c \
			parse_check.c \
			parser_map.c \
			txt_init.c \
			drawing_helper.c \
			rgb.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c \
			libft/ft_lstadd_back.c \
			libft/ft_strchr.c \
			libft/ft_strtrim.c \
			libft/ft_atoi.c \
			libft/ft_strdup.c \
			libft/ft_substr.c \
			libft/ft_bzero.c \
			libft/ft_calloc.c \
			libft/ft_strlen.c \
			libft/ft_lstnew.c \
			libft/ft_strncmp.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBS			= -lmlx -framework OpenGL -framework AppKit
MLX				= libmlx.a

NAME			= cub3D

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

$(MLX):
				@$(MAKE) -C minilibx_opengl
				@mv minilibx_opengl/$(MLX) .

clean:
				@$(MAKE) -C minilibx_opengl clean
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
