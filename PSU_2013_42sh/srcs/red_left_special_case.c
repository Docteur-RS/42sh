/*
** red_left_special_case.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:25:00 2014 lancel_e
** Last update Sun Jun  1 16:44:56 2014 lancel_e
*/

#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "list.h"
#include "all.h"

int	two_dup_and_close_spe(int *fd)
{
  if (dup2(fd[0], 0) == -1)
      return (-1);
  if (dup2(fd[1], 1) == -1)
       return (-1);
  return (0);
}

int	redirec_pars_left_angular_fork_spe(t_manage *man, t_list *list, int *fd)
{
  int	pid;
  int	status;

  status = 0;
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      if (two_dup_and_close_spe(fd) == -1)
	return (-1);
      if (exe(man, list->cmd) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  else
    {
      if (wait(&status) == -1)
	return (-1);
      if (close(fd[0]) == -1)
	return (-1);
      if (close(fd[1]) == -1)
	return (-1);
      return (0);
    }
  return (0);
}

int	redirec_left_spe(t_manage *man, t_list *list)
{
  int	fd[2];
  int	ret;

  if (list->next->cmd == NULL)
    return (-1);
  if ((fd[0] = open(list->next->cmd, O_RDONLY)) < 0)
    return (1);
  if (list->next->num == 2)
    if ((fd[1] = open(list->next->next->cmd,
		      O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
      return (1);
  if (list->next->num == 4)
    if ((fd[1] = open(list->next->next->cmd,
		      O_CREAT | O_APPEND | O_WRONLY, 0644)) < 0)
      return (1);
  if ((ret = redirec_pars_left_angular_fork_spe(man, list, fd)) == MASTER_ERROR)
    return (MASTER_ERROR);
  return (0);
}
