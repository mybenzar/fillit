

SOURCES = ft_place.c ft_list_size.c ft_check.c ft_convert_to_t_list.c ft_tri_pos.c ft_left.c ft_lst_tri_new.c \
		  ft_lst_tri_add.c ft_t_list_to_tri_list.c ft_display_tab.c ft_free_tab.c 						\
		  ft_check_and_convert.c ft_check_shape.c ft_assign_letter.c

SRC_MYM	= ft_create_tab.c ft_del.c ft_optimal_size.c

SRC_SIM	= ft_shape.c

SRC_NEW = ft_scan.c ft_find_l.c ft_find_c.c ft_lst_free.c



all :
	gcc -Wall -Werror -Wextra -std=c11 -ggdb3 fillit.c -L. -lft $(SOURCES) $(SRC_MYM) $(SRC_SIM) $(SRC_NEW) -o fillit
