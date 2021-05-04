cmake_minimum_required(VERSION 3.17)
project(cub3d C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled1 main.c mlx/draw.c parse/check_errors_with_file.c parse/map_utils.c parse/parser.c parse/utils.c parse/safe_exit.c parse/mass_utils.c mlx/raycast.c)
TARGET_LINK_LIBRARIES(untitled1 "-Llibft/libft.a")
TARGET_LINK_LIBRARIES(untitled1 "-Lmlx_linux -Imlx_linux -lm -lz -Lminilibx-linux/libmlx_linux.a")