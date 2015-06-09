##
## Makefile for Makefile in /home/lancel_e/Documents/DIVERS/script/base Makefile
## 
## Made by lancel_e
## Login   <lancel_e@epitech.net>
## 
## Started on  Tue Jan  7 14:24:41 2014 lancel_e
## Last update Sun Jun  1 17:47:25 2014 lancel_e
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall -Wextra
CFLAGS	+= -ansi
CFLAGS	+= -I headers/

NAME	= bwsh

SRCS	= srcs/wait_and_list.c			\
	  srcs/pre_loops.c			\
	  srcs/dollar_utils.c			\
	  srcs/small_utils.c			\
	  srcs/copy_var_name.c			\
	  srcs/parser_step1.c			\
	  srcs/wildcard_handling.c		\
	  srcs/epur_start_end.c			\
	  srcs/pos_in_args.c			\
	  srcs/d_red_left_err.c			\
	  srcs/multi_pipe_utils.c		\
	  srcs/exe.c				\
	  srcs/additional_func.c 		\
	  srcs/all_red_right.c 			\
	  srcs/dollar_replace.c			\
	  srcs/cd_less.c 			\
	  srcs/cd_option.c 			\
	  srcs/change_dir.c 			\
	  srcs/commands_analyse.c 		\
	  srcs/commands_basic.c			\
	  srcs/commands_extract.c 		\
	  srcs/commands_keywords_extract.c 	\
	  srcs/disp_tab.c 			\
	  srcs/d_red_left.c 			\
	  srcs/d_red_left_spe.c 		\
	  srcs/echo_tcsh_ref.c 			\
	  srcs/env_low_level.c 			\
	  srcs/env_manage.c 			\
	  srcs/env_utils.c 			\
	  srcs/epur_str.c 			\
	  srcs/error_disp1.c 			\
	  srcs/error_disp2.c 			\
	  srcs/error_manage.c 			\
	  srcs/exec_built_ins.c 		\
	  srcs/exec_cmd.c 			\
	  srcs/exec_cmd_utils.c 		\
	  srcs/exec_file.c 			\
	  srcs/fill_list.c 			\
	  srcs/get_next_line.c 			\
	  srcs/d_red_left_utils.c		\
	  srcs/ini_all.c			\
	  srcs/main.c 				\
	  srcs/maj_pwd.c 			\
	  srcs/my_exit.c 			\
	  srcs/my_getenv.c 			\
	  srcs/my_getenv_line.c 		\
	  srcs/my_getnbr.c 			\
	  srcs/my_malloc.c 			\
	  srcs/my_put_in_end_list.c 		\
	  srcs/my_put_in_list.c 		\
	  srcs/my_strcomp.c 			\
	  srcs/my_str_cpy.c 			\
	  srcs/my_strlen.c 			\
	  srcs/my_str_to_wordtab.c 		\
	  srcs/my_str_to_wordtab_end.c 		\
	  srcs/one_redirec_manage.c 		\
	  srcs/parallel_func.c 			\
	  srcs/parser_other.c			\
	  srcs/parser_reconstruct.c 		\
	  srcs/parser_spacestabulations.c 	\
	  srcs/parser_start.c 			\
	  srcs/pv_cut.c 			\
	  srcs/pv_manage.c 			\
	  srcs/pv_utils_basic.c 		\
	  srcs/red_left.c 			\
	  srcs/red_left_special_case.c 		\
	  srcs/separator.c 			\
	  srcs/signal_catching.c 		\
	  srcs/start_multi.c 			\
	  srcs/string_basic.c 			\
	  srcs/string_espacewords.c 		\
	  srcs/string_espacewordslength.c 	\
	  srcs/string_other.c			\
	  srcs/string_to_delete.c 		\
	  srcs/utils_basic2.c 			\
	  srcs/utils_basic.c 			\
	  srcs/wait_func.c

OBJS	= $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
clean:
	@$(RM) $(OBJS)

fclean: 	clean
	@$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
