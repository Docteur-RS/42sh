/*
** exec_built_ins.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:20:27 2014 lancel_e
** Last update Sun Jun  1 14:12:57 2014 lalann_a
*/

#include <stdio.h>
#include "all.h"

int		get_status(int nb, char c)
{
  static int	ret = 0;

  if (c == 'e')
    ret = nb;
  else if (c == 'r')
    return (ret);
  return (1);
}

int	is_built_ins(char *cmd)
{
  if (my_strcomp("echo ", cmd) == 1)
    return (1);
  else if (my_strcomp("setenv", cmd) == 1)
    return (1);
  else if (my_strcomp("unsetenv", cmd) == 1)
    return (1);
  else if (my_strcomp("exit", cmd) == 1)
    return (1);
  else if (my_strcomp("cd", cmd) == 1)
    return (1);
  else if (my_strcomp_restrict("env", cmd) == 1)
    return (1);
  else if (my_strcomp(".", cmd) == 1 || my_strcomp("/", cmd) == 1)
    return (1);
  return (0);
}

int	exec_built_ins(t_manage *man, char *cmd)
{
  if (my_strcomp("echo ", cmd) == 1)
    echo_tcsh_ref(cmd);
  else if (my_strcomp("setenv", cmd) == 1)
    setenv_manager(man, cmd);
  else if (my_strcomp("unsetenv", cmd) == 1)
    unsetenv_manager(man, cmd);
  else if (my_strcomp("exit", cmd) == 1)
    return (my_exit(man, cmd));
  else if (my_strcomp("cd", cmd) == 1)
    my_cd(man, cmd);
  else if (my_strcomp_restrict("env", cmd) == 1)
    env_disp(man->all_env->my_env);
  else if (my_strcomp(".", cmd) == 1 || my_strcomp("/", cmd) == 1)
    {
      if (exec_file(man, cmd) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  else
    return (1);
  return (get_status(0, 'r'));
}
