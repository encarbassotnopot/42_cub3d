SOURCES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c) $(wildcard $(SRC_DIR)/*/*/*.c)
SRC_FILES = $(SOURCES) #$(addprefix $(SRC_DIR)/,$(SOURCES))
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
DEP_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.d,$(SRC_FILES))

HDR_FLAGS = -I $(LIBFT) -I $(LIBMLX)/include/MLX42 -I $(INCLUDE)
LIB_FLAGS = $(LIBFT_FLAGS) $(LIBMLX_FLAGS) -ldl -lglfw -pthread -lm
SRC_DIR = $(CURDIR)/src
BUILD_DIR = $(CURDIR)/build
BUILD_DIRS = $(sort $(dir $(OBJ_FILES)))

NAME = cub3d
CFLAGS = -Wall -Wextra -g -MMD $(HDR_FLAGS)

CC = gcc

INCLUDE = $(CURDIR)/include

LIBFT = $(CURDIR)/libft
LIBFT_TARGET = $(LIBFT)/libft.a
LIBFT_FLAGS = -L $(dir $(LIBFT_TARGET)) -l:libft.a

LIBMLX = $(CURDIR)/MLX42
LIBMLX_TARGET = $(LIBMLX)/build/libmlx42.a
LIBMLX_FLAGS = -L $(dir $(LIBMLX_TARGET)) -lmlx42

all: $(NAME)

$(LIBFT_TARGET): libft

libft:
	make -C $(LIBFT)

$(LIBMLX_TARGET): libmlx

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build
	cmake --build $(LIBMLX)/build -j4

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(BUILD_DIRS)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BUILD_DIRS):
	mkdir -p $@

$(NAME): $(LIBMLX_TARGET) $(LIBFT_TARGET) $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIB_FLAGS)

clean reclean:
	rm -rf $(BUILD_DIR)

deepclean: fclean
	make -C $(LIBFT) fclean
	make -C $(LIBMLX)/build clean

fclean: clean
	rm -rf $(NAME)

re: fclean all reclean

-include $(DEP_FILES)

.PHONY: all clean reclean fclean re libft libmlx deepclean
