

SOURCES = ft_place.c ft_list_size.c ft_check.c ft_convert_to_t_list.c ft_tri_pos.c ft_left.c ft_display.c ft_lst_tri_new.c \
		  ft_lst_tri_add.c ft_t_list_to_tri_list.c ft_display_tri_lst.c ft_display_tab.c ft_free_tab.c ##ft_rev_tri_lst.c
SRC_MYM	= 

SRC_SIM	= ft_check_diese_nb.c ft_check_and_convert.c ft_check_shape.c			\
		  ft_assign_letter.c



all :
	gcc mainSim.c -L. -lft $(SOURCES) $(SRC_MYM) $(SRC_SIM)
