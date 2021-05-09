cmake_minimum_required(VERSION 3.17)
project(cub3d C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled1 main.c mlx/draw.c parse/check_errors_with_file.c parse/map_utils.c parse/parser.c parse/utils.c parse/safe_exit.c parse/mass_utils.c mlx/raycast.c mlx/raycast_utils.c mlx/textures.c)
TARGET_LINK_LIBRARIES(untitled1 /Users/kgale/Desktop/my_cub/mlx_mac/libmlx.a)
TARGET_LINK_LIBRARIES(untitled1 /Users/kgale/Desktop/my_cub/libft/libft.a)
TARGET_LINK_LIBRARIES(untitled1 "-framework OpenGL" "-framework Appkit")