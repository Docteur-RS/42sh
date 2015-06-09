/*
** multi_pipe_utils.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:21:42 2014 lancel_e
** Last update Sun Jun  1 11:14:36 2014 lancel_e
*/

#include <unistd.h>
#include "list.h"
#include "all.h"

int	close_and_pipe(int *p, int *p2)
{
  if (close(p[1]) == -1)
    return (-1);
  if (pipe(p2) == -1)
    return (-1);
  return (0);
}

int	two_dup_exe(t_manage *man, t_list *list, int *p, int *p2)
{
  if (dup2(p[0], 0) == -1)
    return (-1);
  if (dup2(p2[1], 1) == -1)
    return (-1);
  if (exe(man, list->next->cmd) == MASTER_ERROR)
    return (MASTER_ERROR);
  return (0);
}

int	search_for_right_and_end(t_manage *man, t_list *list, int *p,
				 int status)
{
  if (list->next->num == 2 || list->next->num == 4)
    return (right_manage(man, list, p));
  else if (list->next->num == -1)
    return (last_pipe(man, list, p, status));
  return (-5);
}

int	search_for_left(t_manage *man, t_list **list, int *p)
{
  if ((*list)->num == 3)
    {
      if (redirec_left(man, *list, p, 0) == MASTER_ERROR)
	return (MASTER_ERROR);
      (*list) = (*list)->next;
      my_static(1, 'o');
      return (1);
    }
  else if ((*list)->num == 5)
    {
      if (d_red_left(man, *list, p, 0) == MASTER_ERROR)
	return (MASTER_ERROR);
      (*list) = (*list)->next;
      my_static(1, 'o');
      return (1);
    }
  return (0);
}

int		my_static(int flag, char c)
{
  static int	one = 0;

  if (c == 'o')
    {
      if (flag == 0)
	one = 0;
      if (flag == 1)
	one = 1;
      return (one);
    }
  if (c == 'n')
    return (one);
  return (1);
}
