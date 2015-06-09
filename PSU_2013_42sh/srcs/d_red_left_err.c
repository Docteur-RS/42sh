/*
** d_red_left_err.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:18:40 2014 lancel_e
** Last update Sun Jun  1 19:32:13 2014 lancel_e
*/

#include <stdlib.h>
#include "all.h"

char	*d_red_left_util_spe(char *buff, char *arg_list, int *n)
{
  buff[*n - 1] = '\n';
  buff[*n] = '\0';
  if ((arg_list = realloc(arg_list, 1024 * sizeof(char))) == NULL)
    return (NULL);
  put_buff_to_args(buff, arg_list);
  return (strdup(buff));
}

int	d_red_left_error_spe(int *fd, t_list *list, char *arg_list,
			     t_manage *man)
{
  int	i;
  int	n;

  arg_list[pos_in_arg(0, 0)] = '\0';
  pos_in_arg(0, 1);
  if ((*fd = get_fd_open_spe(list)) == -1)
    return (-1);
  if ((i = cmd_handling_spe(man, list, arg_list, *fd)) == MASTER_ERROR)
    return (MASTER_ERROR);
  if (waitpid(i, &n, 0) == -1)
    return (-1);
  return (0);
}
