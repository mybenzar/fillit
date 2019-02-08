

SOURCES = ft_place_bis.c ft_list_size.c ft_check.c ft_convert_to_t_list.c ft_tri_pos.c ft_left.c ft_display.c ft_lst_tri_new.c \
		  ft_lst_tri_add.c ft_t_list_to_tri_list.c ft_display_tri_lst.c ft_display_tab.c ft_free_tab.c 						\
		  ft_check_diese_nb.c ft_check_and_convert.c ft_check_shape.c ft_assign_letter.c

SRC_MYM	= ft_create_tab.c ft_del.c ft_optimal_size.c ft_find_letter.c ft_browse.c

SRC_SIM	= ft_lst_insert.c ft_lst_sort.c ft_next_valid_letter.c ft_shape.c




all :
	gcc -g main.c -L. -lft $(SOURCES) $(SRC_MYM) $(SRC_SIM) -o fillit
