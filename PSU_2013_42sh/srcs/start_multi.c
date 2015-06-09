/*
** start_multi.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:25:31 2014 lancel_e
** Last update Sun Jun  1 15:18:42 2014 lancel_e
*/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "list.h"
#include "all.h"

int	first_pipe(t_manage *man, t_list *list, int *p, int status)
{
  if (fork() == 0)
    {
      if (dup2(p[1], 1) == -1)
	return (-1);
      if (close(p[0]) == -1)
	return (-1);
      if (exe(man, list->cmd) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  if (wait(&status) == -1)
    return (-1);
  return (0);
}

int	last_pipe(t_manage *man, t_list *list, int *p, int status)
{
  int	ret;

  if (close(p[1]) == -1)
    return (-1);
  if (is_built_ins(list->next->cmd) == 1)
    {
      get_status(0, 'e');
      if (exec_built_ins(man, list->next->cmd) == MASTER_ERROR)
	return (MASTER_ERROR);
      return (0);
    }
  if ((ret = fork()) == 0)
    {
      if (dup2(p[0], 0) == -1)
	return (-1);
      if (exe(man, list->next->cmd) == MASTER_ERROR)
	return (MASTER_ERROR);
      return (MASTER_ERROR);
    }
  if (ret == -1)
    return (-1);
  if (wait(&status) == -1)
    return (-1);
  return (0);
}

int	right_manage(t_manage *man, t_list *list, int *p)
{
  if (list->next->num == 2)
    {
      if (red_right(man, list, p) == -1)
	return (-1);
    }
  else if (list->next->num == 4)
    if (d_red_right(man, list, p) == -1)
      return (-1);
  return (0);
}

int     pre_part_master_pipe(t_manage *man, t_list **list, int *p)
{
  int   status;

  status = 0;
  if ((status = search_for_left(man, list, p)) == MASTER_ERROR)
    return (MASTER_ERROR);
  if (status == 1)
    {
      if (status == MASTER_ERROR)
        return (MASTER_ERROR);
    }
  else if (my_static(0, 'n') == 0)
    {
      if (first_pipe(man, *list, p, status) == MASTER_ERROR)
        return (MASTER_ERROR);
      my_static(1, 'o');
    }
  return (0);
}

int     master_pipe(t_manage *man, t_list *list, int *p)
{
  int   status;
  int   p2[2];

  status = 0;
  if (pre_part_master_pipe(man, &list, p) == MASTER_ERROR)
    return (MASTER_ERROR);
  if ((status = search_for_right_and_end(man, list, p, status)) != -5)
    return (status);
  else if (list->next->num == 1)
    {
      if (close_and_pipe(p, p2) == -1)
        return (-1);
      if (fork() == 0)
        two_dup_exe(man, list, p, p2);
      wait_and_list(&list, status);
      if (master_pipe(man, list, p2) == MASTER_ERROR)
	return (MASTER_ERROR);
      return (0);
    }
  return (0);
}
