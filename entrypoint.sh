#!/bin/bash

mkdir -p mandatory/srcs mandatory/includes bonus/srcs bonus/includes libft

for file in textures/*.png; do
  output_file="${file%.png}.xpm"
  convert "$file" "$output_file"
  echo "conversion done: $file -> $output_file"
done

sed -i 's/png/xpm/g' mandatory/srcs/graphics.c
sed -i 's/png/xpm/g' bonus/srcs/graphics_utils_bonus.c

sed -i 's/# define FINISH 53/# define FINISH 65307/' mandatory/includes/so_long.h
sed -i 's/# define FINISH 53/# define FINISH 65307/' bonus/includes/so_long_bonus.h
sed -i 's/# define UP 13/# define UP 119/' mandatory/includes/so_long.h
sed -i 's/# define UP 13/# define UP 119/' bonus/includes/so_long_bonus.h
sed -i 's/# define DOWN 1/# define DOWN 115/' mandatory/includes/so_long.h
sed -i 's/# define DOWN 1/# define DOWN 115/' bonus/includes/so_long_bonus.h
sed -i 's/# define LEFT 0/# define LEFT 97/' mandatory/includes/so_long.h
sed -i 's/# define LEFT 0/# define LEFT 97/' bonus/includes/so_long_bonus.h
sed -i 's/# define RIGHT 2/# define RIGHT 100/' mandatory/includes/so_long.h
sed -i 's/# define RIGHT 2/# define RIGHT 100/' bonus/includes/so_long_bonus.h

if [ -f Makefile ]; then
  sed -i "s/MLX = mlx\/libmlx.dylib/MLX = mlx\/libmlx.a/" Makefile
  sed -i "s/-Lmlx -lmlx -framework OpenGL -framework Appkit/-Lmlx -lmlx -lXext -lX11 -lm -lz/" Makefile
  sed -i "/cp \$(MLX) \./d" Makefile
  sed -i "/\$(RM) libmlx.dylib/d" Makefile
  echo "Makefile has been updated for Linux compatibility"
else
  echo "Makefile not found. Please mount your project directory."
  exit 1
fi
exec "$@"
