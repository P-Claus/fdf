#############################################
###		 			CONFIG		          ###
#############################################

NAME			= fdf

CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Werror -Wextra -g $(INCLUDES)


LIBFT_DIR		= ./libft
LIBFT			= ./libft/libft.a
LIBFT_SOURCES	= $(LIBFT_DIR)/*.c
LIBFT_OBJ		= $(LIBFT_DIR)/*.o

MINILIBX_DIR	= ./mlx_linux
MINILIBX		= ./mlx_linux/libmlx_Linux.a

MKDIR			= mkdir -p

SOURCES_DIR		= src
SOURCES			= $(wildcard $(SOURCES_DIR)/*.c)
OBJ				= $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.c=.o)))
OBJ_DIR			= obj

UTILS_DIR 		= utils
UTILS_FILES		= $(wildcard $(UTILS_DIR)/*.c)
UTILS_OBJ		= $(addprefix $(OBJ_DIR)/, $(notdir $(UTILS_FILES:.c=.o)))

ERROR_DIR 		= error_checks
ERROR_FILES		= validate_input.c
ERROR_OBJ		= $(OBJ_DIR)/validate_input.o



INCLUDES		= -I ./includes

TOTAL_FILES := $(words $(wildcard $(SOURCES_DIR)/*.c) $(wildcard $(UTILS_DIR)/*.c) $(wildcard $(UTILS_DIR)))

COMPILE_COUNT = 0

#############################################
###					COLORS			      ###
#############################################

RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN			= \033[0;36m
RESET_COLOR		= \033[0m
MOVEUP			= \033[F
RESET			= \e[2K\r

#############################################
###		 			RULES	      	      ###
#############################################

all: $(NAME)

$(LIBFT): 
	@make -s -C $(LIBFT_DIR) 

$(MINILIBX):
	@make -s -C $(MINILIBX_DIR)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ) $(UTILS_OBJ) $(ERROR_OBJ) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(UTILS_OBJ) $(ERROR_OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm
	@echo "$(RESET)$(GREEN)Compiled $(NAME)$(RESET_COLOR)"

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling fdf $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling fdf $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

$(OBJ_DIR)/%.o: $(ERROR_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling fdf $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

clean:
	@make clean -s -C $(LIBFT_DIR)
	@make clean -s -C $(MINILIBX_DIR)
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Removed the object files from fdf$(RESET_COLOR)"

fclean:
	@make fclean -s -C $(LIBFT_DIR)
	@make clean -s -C $(MINILIBX_DIR)
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(GREEN)Removed $(NAME) and the object files$(RESET_COLOR)"

re:
	@make -s fclean
	@make -s

.PHONY:			all clean fclean re 