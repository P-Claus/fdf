#######################################
###				CONFIG		   		###
#######################################

NAME			= libft.a

CFLAGS			= -Wall -Werror -Wextra
CC				= cc
RM				= rm -rf
MKDIR			= mkdir -p

SOURCES_DIR		= src
SOURCES			= $(wildcard $(SOURCES_DIR)/*.c)
OBJ				= $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.c=.o)))
OBJ_DIR			= obj

INCLUDES		= includes/*.h

PRINTF_SRC_DIR	= printf
PRINTF_SRC		= $(wildcard $(PRINTF_SRC_DIR)/*.c)
PRINTF_OBJ		= $(addprefix $(OBJ_DIR)/, $(notdir $(PRINTF_SRC:.c=.o))) 

GNL_SRC_DIR		= get_next_line
GNL_SRC			= $(wildcard $(GNL_SRC_DIR)/*.c)
GNL_OBJ			= $(addprefix $(OBJ_DIR)/, $(notdir $(GNL_SRC:.c=.o))) 
	

TOTAL_FILES := $(words $(wildcard $(SOURCES_DIR)/*.c) $(wildcard $(PRINTF_SRC_DIR)/*.c) $(wildcard $(GNL_SRC_DIR)/*.c))

COMPILE_COUNT = 0

#######################################
###				COLORS		   		###
#######################################

RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN			= \033[0;36m
RESET			= \033[0m
MOVEUP			= \033[F
RESET			= \e[2K\r

#######################################
###				RULES		   		###
#######################################

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF_OBJ) $(GNL_OBJ) $(INCLUDES)
	@ar rcs $(NAME) $(OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
	@echo "$(RESET)$(GREEN)Libft has been created!"

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling libft $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

$(OBJ_DIR)/%.o: $(PRINTF_SRC_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling libft $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"

$(OBJ_DIR)/%.o: $(GNL_SRC_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@echo -n "$(RESET)$(YELLOW)Compiling libft $$(($(COMPILE_COUNT)*100/$(TOTAL_FILES)))%"


clean:
	@$(RM) $(OBJ_DIR) > /dev/null 2>&1
	@echo "$(GREEN)The object files from libft have been removed!"

fclean: 
	@$(RM) $(OBJ_DIR) > /dev/null 2>&1
	@$(RM) $(NAME) > /dev/null 2>&1
	@echo "$(GREEN)The object files from libft and the library have been removed!"

re:
	@make -s fclean
	@make -s

.PHONY:			all clean fclean re 