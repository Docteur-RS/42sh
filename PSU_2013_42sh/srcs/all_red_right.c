/*
** all_red_right.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:16:47 2014 lancel_e
** Last update Sun Jun  1 17:04:38 2014 lancel_e
*/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "list.h"
#include "all.h"

int	d_red_right(t_manage *man, t_list *list, int *p)
{
  int	n;
  int	ret;

  if (list->next->cmd == NULL || list->cmd == NULL)
    return (-1);
  list->next->next->cmd = my_epur(list->next->next->cmd);
  ini_all_red_right(&ret, &n);
  if (close(p[1]) == -1)
    return (-1);
  if ((n = open(list->next->next->cmd,
		O_CREAT | O_APPEND | O_WRONLY, 0644)) < 0)
    return (-1);
  if ((ret = fork()) == 0)
    {
      if (dup2(n, 1) == -1)
	return (-1);
      if (dup2(p[0], 0) == -1)
	return(-1);
      if (exe(man, list->next->cmd) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  return (ret_then_wait(ret));
}

int	ret_and_wait(int ret, int status)
{
  if (ret == -1)
    return (-1);
  if (wait(&status) == -1)
    return (-1);
  return (0);
}

int	d_red_right_for_unique(t_manage *man, t_list *list, int *p)
{
  int	newfd;
  int	status;
  int	ret;

  status  = 0;
  ini_all_red_right(&ret, &newfd);
  if (list->next->cmd == NULL || list->cmd == NULL)
    return (-1);
  list->next->cmd = my_epur(list->next->cmd);
  if (close(p[1]) == -1)
    return (-1);
  if ((newfd = open(list->next->cmd, O_CREAT | O_APPEND | O_WRONLY, 0644)) < 0)
    return (-1);
  if ((ret = fork()) == 0)
    {
      if (dup2(newfd, 1) == -1)
	return (-1);
      if (dup2(p[0], 0) == -1)
	return (-1);
      if (exe(man, list->cmd) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  if (ret_and_wait(ret, status) == -1)
    return (-1);
  return (0);
}

int	red_right(t_manage *man, t_list *list, int *p)
{
  int	n;
  int	status;
  int	ret;

  ini_all_red_right(&ret, &n);
  ini_and_epur_red_right(list);
  list->next->next->cmd = my_epur(list->next->next->cmd);
  if (close(p[1]) == -1)
    return (-1);
  if ((n = open(list->next->next->cmd, O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
    return (-1);
  if ((ret = fork()) == 0)
    {
      if (dup2(n, 1) == -1)
	return (MASTER_ERROR);
      if (dup2(p[0], 0) == -1)
	return (-1);
      if (exe(man, list->next->cmd) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  if (ret == -1)
    return (-1);
  if (wait(&status) == -1)
    return (-1);
  return (0);
}

int	red_right_for_unique(t_manage *man, t_list *list, int *p)
{
  int	newfd;
  int	status;
  int	ret;

  status = 0;
  ini_all_red_right(&ret, &newfd);
  ini_and_epur_red_right_for_unique(list);
  if (close(p[1]) == -1)
    return (-1);
  if ((newfd = open(list->next->cmd, O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
    return (-1);
  if (close(p[0]) == -1)
    return (-1);
  if ((ret = fork()) == 0)
    {
      if (dup2(newfd, 1) == -1)
	return (-1);
      if (exe(man, list->cmd) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  if (ret == -1)
    return (-1);
  if (wait_and_close(status, newfd) == -1)
    return (-1);
  return (0);
}
