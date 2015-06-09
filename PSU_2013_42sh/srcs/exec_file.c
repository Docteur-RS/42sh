/*
** exec_file.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:20:51 2014 lancel_e
** Last update Sun Jun  1 14:40:31 2014 lalann_a
*/

#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "globing.h"
#include "all.h"

int	exec_file(t_manage *man, char *cmd)
{
  char	**d_arg;
  int	pid;

  if ((d_arg = get_args(cmd)) == NULL)
    return (-1);
  if (access(d_arg[0], F_OK) == -1)
    return (err_report(0, cmd));
  if (access(d_arg[0], X_OK) == -1)
    return (err_report(5, cmd));
  if ((check_for_wildcards(d_arg)) > 0)
    return (glob_handling(man->all_env->my_env, d_arg, d_arg[0]));
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      if (setsid() == -1)
	return (-1);
      execve(d_arg[0], d_arg, man->all_env->my_env);
      return (MASTER_ERROR);
    }
  else if (pid > 0)
    return (wait_for_son());
  return (0);
}
