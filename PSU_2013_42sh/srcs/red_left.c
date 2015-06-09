/*
** red_left.c for  in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:24:35 2014 lancel_e
** Last update Sun Jun  1 11:09:55 2014 lancel_e
*/

#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "list.h"
#include "all.h"

int	two_dup_and_close(int *p, int fd, int flag)
{
  if (dup2(fd, 0) == -1)
    return (-1);
  if (flag == 0)
    if (dup2(p[1], 1) == -1)
      return (-1);
  if (close(p[0]) == -1)
    return (-1);
  return (0);
}

int	redirec_pars_left_angular_fork(t_manage *man, t_list *list,
				       int *p, int fd, int flag)
{
  int	pid;
  int	status;

  status = 0;
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      if (two_dup_and_close(p, fd, flag) == -1)
	return (-1);
      if (exe(man, list->cmd) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  else
    {
      if (wait(&status) == -1)
	return (-1);
      if (close(fd) == -1)
	return (-1);
      return (0);
    }
  return (0);
}

int	redirec_left(t_manage *man, t_list *list, int *p, int flag)
{
  int	fd;
  int	ret;

  if (list->next->cmd == NULL)
    return (-1);
  if ((fd = open(list->next->cmd, O_RDONLY)) == -1)
    {
      my_putstr("File not found.\n");
      return (1);
    }
  if ((ret = redirec_pars_left_angular_fork(man, list, p, fd, flag)) == -1)
    return (1);
  if (ret == MASTER_ERROR)
    return (MASTER_ERROR);
  return (0);
}
