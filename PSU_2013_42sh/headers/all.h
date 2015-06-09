/*
** all.h for mysh in /home/lancel_e/Documents/PROJET/mini-shell/parsing/makeur
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Tue Dec 31 18:21:10 2013 lancel_e
** Last update Sun Jun  1 17:22:54 2014 lalann_a
*/

#ifndef ALL_H_
# define ALL_H_

# define ERRWRITE "INVALID WRITE"
# define PROMPT "$>"
# define MASTER_ERROR -10
# define ERROR -1
# define SUCCESS 1
# define NB_TO_ARG 3
# define BUFF_SIZE 6000

# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "dollar.h"
# include "get_next_line.h"
# include "list.h"

typedef struct	s_pipe
{
  int		*p;
  int		*p2;
}		t_pipe;

typedef struct	s_unset
{
  int		i;
  int		j;
  int		k;
  char		**new;
}		t_unset;


typedef struct	s_base
{
  int		argc;
  char		**argv;
  char		**envp;
}		t_base;


typedef struct	s_cmd
{
  char		*cmd;
  char		*newcmd;
  char		*nospbuff;
  char		*pv;
}		t_cmd;

typedef struct	s_env
{
  char		**my_env;
  char		*oldpwd;
}		t_env;

typedef struct	s_error_flag
{
  int		f_ret;
  int		has_exit;
}		t_error_flag;

typedef struct  s_redirec_found
{
  int		pv;
  int		my_pipe;
  int		red_l;
  int		red_r;
  int		d_red_l;
  int		d_red_r;
  int		my_or;
  int		my_and;
}		t_redirec_found;


typedef struct		s_manage
{
  t_cmd			*all_cmd;
  t_env			*all_env;
  t_error_flag		*all_ret;
  t_base		*all_base;
  t_redirec_found	*all_red;
}			t_manage;

typedef struct	s_escape
{
  char		escape_char;
  char		to_print;
}		t_escape;

void	small_modif_to_buff(char *buff, int n);
int	ret_then_wait(int ret);
int	pre_part_master_pipe(t_manage *man, t_list **list, int *p);
int	or_and_redirec(t_manage *man, t_list **list, int ok);
int	or_and_redirec_next(t_manage *man ,t_list **list, int ok);
int	pre_wait_func(t_manage *man, t_list **list, int status);
void	bye_tab(char *str);
void	bye_space_init(char *str, int *i, int *count, int *j);
char	*bye_space(char *str);
char	**bye_space_in_double(char **av);
int	wait_and_close(int status, int newfd);
int	master_pipe(t_manage *man, t_list *list, int *p);
int	get_fd_open_spe(t_list *list);
int	get_it_on(t_manage *man, t_list *list);
int	d_red_left_error_spe(int *fd, t_list *list, char *arg_list,
			     t_manage *man);
char	*d_red_left_util_spe(char *buff, char *arg_list, int *n);
int	err_report(int i, char *str);
int	close_and_pipe(int *p, int *p2);
int	two_dup_exe(t_manage *man, t_list *list, int *p, int *p2);
int	search_for_left(t_manage *man, t_list **list, int *p);
int	search_for_right_and_end(t_manage *man, t_list *list, int *p,
				 int status);
int	pos_in_arg(int value, int flag);
int	chdir(const char *path);
int	wait_func(int status);
void	my_putstr(char *str);
void	my_put_nbr(int nb);
void	my_strcpy_free(char *first, char *second, int flag);
char	*my_strcopy(char *first, char *second, int flag);
char	*my_strcopy(char *first, char *second, int flag);
void	aff_prompt();
int	signal_catch();
int	two_dup_and_close_spe(int *fd);
int	redirec_pars_left_angular_fork_spe(t_manage *man,
					   t_list *list, int *fd);
int	redirec_left_spe(t_manage *man, t_list *list);
char	**cut_for_pv_pars(t_manage *man);
void	cut_for_pv_check_del_space_pars_ini(int *i, int *j);
void	cut_for_pv_check_del_space_pars_pv_at_end(char *buff);
void	nb_of_sp(char *str, int i, int *sp);
int	last_pv(t_manage *man);
void	cut_for_pv_check_del_space_pars(t_manage *man, char *buff);
int	cut_for_pv_check_del_space_check(t_manage *man, int ret);
int	cut_for_pv_check(t_manage *man);
int	is_need_cpy_char(char *str, int i);
int	exe_redirec_unique_two(t_manage *man, t_list *list, int *p);
int	exe_redirec_unique(t_manage *man, t_list *list);
int	special_all_left_case(t_manage *man, t_list *list);
int	only_one_redirec_manage(t_manage *man, t_list *list);
int	word_count(char *str, char sepa);
int	letter_count(int word_comp, char *str, char sepa);
char	**my_wordtab(char *words, char sepa);
char	**my_str_to_wordtab(char *words, char sepa);
int	disp_wordtab(char **wtab);
int	my_strlen_line(char *str, int line);
int	my_while_sep_isnt(char  *str, char sep);
char	*my_strcpy(char *final, char *start);
char	*my_strcpy_since_line(char *start, char *final, int line);
int	my_put_in_list(t_list **list, char *cmd, int num);
void	my_show_list(t_list *list);
void	free_list(t_list *list);
void	*my_malloc(int size);
void	my_free(void *var);
int	match_line(char *s1, char *s2);
char	*my_getenv_line_spe(char **envp, char *str);
char	*my_getenv_line(char **envp, char *str);
char	*line_envp_line(char **envp, char *str);
int	my_exit(t_manage *man, char *cmd);
int	verified_read(t_manage *man);
int	sub_main(t_manage *man);
void	struc_ini(t_manage *man, char **argv, char **envp, int argc);
char	*get_next_line(const int fd);
char	*my_append_for_malloc_doc(char *tab, char c);
int	wait_for_son();
int	exec_file(t_manage *man, char *cmd);
void	free_path_arg(char **path, char **d_arg);
char	*color_ls(char *cmd);
int	get_path_arg(char ***path, char ***d_arg, t_manage *man, char *cmd);
int	wait_son();
int	exec_cmd(t_manage *man, char *cmd);
int	exec_cmd_for_multi(t_manage *man, char *cmd);
int	x_report(int i);
void	setenv_err();
void	err_fnf(char *str);
void	err_syntax();
void	unsetenv_err();
void	cd_err(char *last);
void	env_disp(char **envp);
int	my_strtab(char **tab);
void	d_tab_unset_doc_ini(t_unset *unset, int flag);
int	first_env_activate(t_manage *man);
int	d_tab_recpy_doc(char **old, char **new, int *i, int *j);
char	**d_tab_cpy_doc(char **v_old, char *add);
char	**d_tab_unset_doc(char **v_old, int pos);
int	send_to_pipe_spe(int pipefd[2], char *arg_list);
int	exec_d_red_left_spe(t_manage *man, char *cmd, int pipefd[2], int fd);
int	cmd_handling_spe(t_manage *man, t_list *list, char *arg_list, int fd);
int	get_fd_open(t_list *list);
int	d_red_left_spe(t_manage *man, t_list *list, int fd);
void	disp_tab(char **tab);
char	*dispatch_cd_cmd(t_manage *man, char *buff);
int	cd_options(t_manage *man, char **buffer);
int	cd_error(char *buffer, struct stat *s);
char	*init_in_fork(int *fd, int *pid);
char	*pwd_sep(char *s1, char *s2, char c);
int	init_new_and_check_pos(char **new, char **v_old, int pos);
int	init_var_and_check_fd(t_var *to, const int fd);
int	d_red_right(t_manage *man, t_list *list, int *p);
int	ret_and_wait(int ret, int status);
int	d_red_right_for_unique(t_manage *man, t_list *list, int *p);
int	red_right(t_manage *man, t_list *list, int *p);
int	red_right_for_unique(t_manage *man, t_list *list, int *p);
int	check_olpwd(t_manage * man);
int	cd_less_part_call(t_manage *man);
int	cd_less(t_manage *man, char *buffer);
void	all_free_cd(char *epure, char *last);
int	is_cmd_cd_ok(char *buff);
char	*go_from_home(t_manage *man, char *buff);
char	*go_home(t_manage *man);
int	my_cd(t_manage *man, char *buffer);
int	send_to_pipe(int pipefd[2], char *arg_list);
int	exec_d_red_left(t_manage *man, char *cmd, int pipefd[2],
			int *p, int flag);
int	cmd_handling(t_manage *man, t_list *list, char *arg_list,
		     int *p, int flag);
void	put_buff_to_args(char buff[1024], char *args);
int	d_red_left(t_manage *man, t_list *list, int *p, int flag);
void	wait_and_free(char *arg_list, int i, int n);
int	turn_arg_list(t_list *list, char *buff, int n);
void	print_char(char c);
int	minus_n_option(char *cmd);
char	print_arg(char *cmd, char pattern);
int	echo_tcsh_ref(char *cmd);
int	setenv_void(t_manage *man, char **d_cmd);
int	setenv_arg_management(t_manage *man, char **d_cmd, int ret);
int	setenv_manager(t_manage *man, char *cmd);
int	unsetenv_for_setenv(t_manage *man, char *cmd, int pos);
int	unsetenv_manager(t_manage *man, char *cmd);
void	ini_var(int *i, int *k);
void	first_space(char *str, int *i);
char	*my_epur(char *str);
void	replace_all_tab(char *str);
void	file_err(char *cmd);
void	not_a_dir_err(char *last);
void	cd_arg_err();
int	        get_status(int nb, char c);
int	is_built_ins(char *cmd);
int	exec_built_ins(t_manage *man, char *cmd);
char	**get_path(char **envp);
char	**get_args(char *cmd);
char	**get_args(char *cmd);
char	*finall_path_maker(char *one, char *two);
char	*get_cmd(char *cmd);
int	is_exec_found(char **path, char *cmd, int *i);
int	linked_list(t_manage *man, t_list *list, char **av);
int	create_list(t_manage *man, char **av);
int	ini_and_epur_red_right(t_list *list);
int	ini_and_epur_red_right_for_unique(t_list *list);
void	ini_all_red_right(int *ret, int *newfd);
int	unsetenv_for_pwd(t_manage *man, char *cmd, int pos);
int	setenv_manager_pwd(t_manage *man, char *cmd, char *buff);
char	*init_pwd(int *fd, char **av, char **envp, char *buff);
char	*pwd_fork(char *buff, char **av, char **envp);
char	*call_pwd(t_manage *man, char **envp);
int	match(char *s1, char *s2);
int	my_getenv(char **envp, char *str);
int	line_envp(char **envp, char *str);
int	is_neg(char *str);
int	my_getnbr(char *str);
int	is_num(int nb);
int	my_put_in_end_list(t_list **list, char *cmd, int num);
int	my_strcomp(char *base, char *search);
int	my_strcomp_restrict(char *base, char *search);
int	my_strlen(char *tab);
int	wordtab_count(char **tab);
void	wordtab_end(char **wtab);
int	loop_pv2(t_manage *man, char **final, char **pv, int *i);
int	loop_pv(t_manage *man, char **pv);
int	loop_without_pv2(t_manage *man);
int	loop_without_pv(t_manage *man);
int	pre_loop_pv(t_manage *man, char **pv, int ret);
int	dprintf(int fd, const char *format, ...);
int	pre_loop_without_pv(t_manage *man, int ret);
int	global_parsing(t_manage *man);
int	two_dup_and_close(int *p, int fd, int flag);
int	redirec_pars_left_angular_fork(t_manage *man, t_list *list,
					 int *p, int fd, int flag);
char	*strdup(const char *s1);
int	redirec_left(t_manage *man, t_list *list, int *p, int flag);
void	disp_pwd(char *final);
char	*separator(char *s1, char *s2, char c);
int	exe(t_manage *man, char *cmd);
int	first_pipe(t_manage *man, t_list *list, int *p, int status);
int	last_pipe(t_manage *man, t_list *list, int *p, int status);
void	wait_and_list(t_list **list, int status);
int	right_manage(t_manage *man, t_list *list, int *p);
int	my_static(int flag, char c);
int	strlen_to_limit(char *str, char sepa);
int	strcomp_env(char *one, char *two, char sepa);
int	is_number(char *str);
char	*str_mallocate(char *str);

#endif /* !ALL_H_ */
