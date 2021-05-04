cmake_minimum_required(VERSION 3.17)
project(cub3d C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled1 main.c mlx/draw.c mlx/raycast.c parse/check_errors_with_file.c parse/parser.c parse/utils.c parse/map_utils.c parse/mass_utils.c parse/safe_exit.c)
ADD_COMPILE_OPTIONS(-03)
TARGET_LINK_LIBRARIES(untitled1 D:/фллеха/Учёба хочу домой/Школа 21/cub3d/mlx_linux/libmlx_x86_64.a)
TARGET_LINK_LIBRARIES(untitled1 D:/фллеха/Учёба хочу домой/Школа 21/cub3d/mlx_linux/libmlx.a)
TARGET_LINK_LIBRARIES(untitled1 D:/фллеха/Учёба хочу домой/Школа 21/cub3d/libft/libft.a)
TARGET_LINK_LIBRARIES(untitled1 -lXext -lX11 -lm -lbsd)