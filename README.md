# cub3d
## PROJECT TREE

```
.
├── MLX42/
├── inc
│   ├── cub3D.h
│   └── cub_structs.h
├── libft/
├── maps/
├── textures/
├── objs/
├── src
│   ├── example.c
│   ├── main.c
│   ├── map
│   │   ├── map.c
│   │   ├── paint.c
│   │   └── player.c
│   ├── parser
│   │   ├── char_check.c 		{ft_char_check, ft_char_mapcheck}
│   │   ├── colour_handle.c		{ft_char_counter, ph_atoi, ft_rgb_to_hex, ft_get_colour, ft_color_check}
│   │   ├── get_map.c			{ft_space_fill, ft_get_spaced_map}
│   │   ├── parse.c		        {ft_init_scene, ft_parse, ft_arg_check}
│   │   ├── read_file.c			{ft_len_file, ft_read_file}
│   │   ├── read_scene.c		{ft_cpy_info, ft_save_info, ft_get_max_len, ft_get_map, ft_parse_file}
│   │   ├── scene_check.c		{ft_check_ext, ft_texture_check, ft_scene_check}
│   │   └── wall_check.c		{ft_is_wall, ft_wall_check}
│   ├── settings
│   │   ├── controls.c
│   │   └── window.c
│   └── utils
│       ├── clean_handling.c	{ft_clean_map}
│       ├── debug.c		{ft_print_matrix, ft_print_scene}
│       ├── error_handling.c	{ft_print_fileformat, ft_parse_errors, ft_mlx_errors, ft_error}
│       └── init.c
└── Makefile
```
