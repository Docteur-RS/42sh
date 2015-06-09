/*
** edollar.h for 42sh in /home/jamme-_c/rendu/42sh_func/echo_dollar_de_ouf
** 
** Made by jamme-_c
** Login   <jamme-_c@epitech.net>
** 
** Started on  Sat May 31 19:01:40 2014 jamme-_c
** Last update Sun Jun  1 14:36:05 2014 lancel_e
*/

#ifndef DOLLAR_H_
# define DOLLAR_H_

char	*cpy_to_char(char *str, char end, int *i);
char	*search(char *str, char **envp);
char	*my_strcopy(char *str, char *str1, int s);
int	my_strlen(char *strr);
char	*copy_var_name(char *str, char end1, char end2,  int *i);
char	*my_getenv_line(char **envp, char *str);
char	*dispatch(char *cmd, char **envp);
int	nb_dollars_exist(char *str);

#endif /* !DOLLAR_H_ */
