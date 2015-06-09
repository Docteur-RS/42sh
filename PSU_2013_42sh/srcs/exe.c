/*
** exe.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:20:20 2014 lancel_e
** Last update Sun Jun  1 18:28:12 2014 lancel_e
*/

#include <unistd.h>
#include "list.h"
#include "all.h"

int	exe(t_manage *man, char *cmd)
{
  int	ret;

  ret = 0;
  if ((ret = exec_built_ins(man, cmd)) == 1)
    {
      if (exec_cmd_for_multi(man, cmd) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  if (ret == MASTER_ERROR)
    return (MASTER_ERROR);
  return (0);
}

int	is_exec_found_for_multi(char **path, char *cmd, int *i)
{
  int	ok;

  ok = 0;
  while (path[*i] != NULL)
    {
      if (access(finall_path_maker(path[*i], get_cmd(cmd)), X_OK) != -1)
        {
	  ok = 1;
	  return (ok);
        }
      *i = *i + 1;
    }
  return (ok);
}

int	is_path_cmd(t_list *list, t_manage *man)
{
  char	**path;
  char	**d_arg;
  int	i;

  i = 0;
  if ((get_path_arg(&path, &d_arg, man, list->cmd)) == -1)
    return (0);
  if (is_exec_found_for_multi(path, list->cmd, &i) == 1)
    return (1);
  return (0);
}

int	check_cmd_in_list(t_list *list, t_manage *man)
{
  while (list->next != NULL && list->num != -1)
    {
      if ((is_built_ins(list->cmd) == 0) && is_path_cmd(list, man) == 0)
	{
	  err_report(0, list->cmd);
	  return (0);
	}
      if (list->next != NULL && (list->num == 3 || list->num == 5))
	list = list->next;
      if (list->next != NULL)
	list = list->next;
    }
  return (1);
}

int	get_it_on(t_manage *man, t_list *list)
{
  int	ret;
  int	p[2];

  if (check_cmd_in_list(list, man) == 0)
    return (0);
  pipe(p);
  get_status(MASTER_ERROR, 'e');
  if ((ret = only_one_redirec_manage(man, list)) == MASTER_ERROR)
    return (MASTER_ERROR);
  if (ret == 1)
    return (0);
  my_static(0, 'o');
  if ((ret = master_pipe(man, list, p)) == MASTER_ERROR)
    return (MASTER_ERROR);
  my_static(0, 'o');
  get_status(0, 'e');
  return (0);
}
