/*
** exec_cmd.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:20:33 2014 lancel_e
** Last update Sun Jun  1 15:38:17 2014 lancel_e
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "globing.h"
#include "all.h"

char	*color_ls(char *cmd)
{
  int	i;
  char	*new_cmd;

  if ((new_cmd = malloc(sizeof(char) * (my_strlen(cmd) + 9))) == NULL)
    return (NULL);
  i = -1;
  while (cmd[++i] != '\0')
    new_cmd[i] = cmd[i];
  new_cmd[i] = ' ';
  new_cmd[i + 1] = '-';
  new_cmd[i + 2] = '-';
  new_cmd[i + 3] = 'c';
  new_cmd[i + 4] = 'o';
  new_cmd[i + 5] = 'l';
  new_cmd[i + 6] = 'o';
  new_cmd[i + 7] = 'r';
  new_cmd[i + 8] = '\0';
  return (new_cmd);
}

int	get_path_arg(char ***path, char ***d_arg, t_manage *man, char *cmd)
{
  if ((((my_strcomp("ls", get_cmd(cmd))) == 1) ||
      ((my_strcomp("grep", get_cmd(cmd))) == 1)) &&
      ((my_getenv_line(man->all_env->my_env, "PATH")) != NULL))
    if ((cmd = color_ls(cmd)) == NULL)
      return (-1);
  if ((*d_arg = get_args(cmd)) == NULL)
    return (-1);
  if ((*path = get_path(man->all_env->my_env)) == NULL)
    return (err_report(0, cmd));
  return (0);
}

int	exe_cmd(t_manage *man, char **d_arg, char *cmd, char **path)
{
  pid_t	pid;
  int	i;

  i = 0;
  is_exec_found(path, cmd, &i);
  if ((check_for_wildcards(d_arg)) == 1)
    return (glob_handling(man->all_env->my_env, d_arg,
			  finall_path_maker(path[i], get_cmd(cmd))));
  pid = fork();
  if (pid == 0)
    {
      execve(finall_path_maker(path[i], get_cmd(cmd)),
	     d_arg, man->all_env->my_env);
      return (MASTER_ERROR);
    }
  else
    wait_for_son();
  return (0);
}

int	exec_cmd(t_manage *man, char *cmd)
{
  char	**d_arg;
  char	**path;
  int	i;

  i = 0;
  if ((get_path_arg(&path, &d_arg, man, cmd)) == -1)
    return (-1);
  if (is_exec_found(path, cmd, &i) == 1)
    return (exe_cmd(man, d_arg, cmd, path));
  else
    err_report(0, cmd);
  free_path_arg(path, d_arg);
  return (0);
}

int	exec_cmd_for_multi(t_manage *man, char *cmd)
{
  char	**d_arg;
  char	**path;
  int	i;

  i = 0;
  if ((d_arg = get_args(cmd)) == NULL)
    return (-1);
  if ((path = get_path(man->all_env->my_env)) == NULL)
    {
      err_report(0, cmd);
      return (-1);
    }
  if (is_exec_found(path, cmd, &i) == 1)
    {
      if ((check_for_wildcards(d_arg)) == 1)
	return (glob_handling(man->all_env->my_env, d_arg,
			      finall_path_maker(path[i], get_cmd(cmd))));
      execve(finall_path_maker(path[i], get_cmd(cmd)),
	     d_arg, man->all_env->my_env);
      return (MASTER_ERROR);
    }
  else
    err_report(0, cmd);
  free_path_arg(path, d_arg);
  return (0);
}
