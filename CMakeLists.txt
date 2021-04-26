cmake_minimum_required(VERSION 3.19)
project(untitled1 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled1 main.c mlx/draw.c parse/check_errors_with_file.c parse/map_utils.c parse/parser.c parse/utils.c parse/safe_exit.c parse/mass_utils.c mlx/raycast.c)
TARGET_LINK_LIBRARIES(untitled1 /Users/kgale/CLionProjects/untitled1/mlx_mac/libmlx.a)
TARGET_LINK_LIBRARIES(untitled1 /Users/kgale/CLionProjects/untitled1/libft/libft.a)
TARGET_LINK_LIBRARIES(untitled1 "-framework OpenGL" "-framework Appkit")