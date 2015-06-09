/*
** env_manage.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:19:21 2014 lancel_e
** Last update Sun Jun  1 17:37:34 2014 lancel_e
*/

#include <stdio.h>
#include "all.h"

int	setenv_void(t_manage *man, char **d_cmd)
{
  int	ret;

  ret = 0;
  if ((ret = my_getenv(man->all_env->my_env, d_cmd[1])) != -1)
    unsetenv_for_setenv(man, d_cmd[1], 1);
  man->all_env->my_env = d_tab_cpy_doc(man->all_env->my_env,
				       separator(d_cmd[1], " ", '='));
  wordtab_end(d_cmd);
  return (0);
}

int	setenv_arg_management(t_manage *man, char **d_cmd, int ret)
{
  if (ret == 1)
    {
      env_disp(man->all_env->my_env);
      return (1);
    }
  else if (ret == 2)
    {
      setenv_void(man, d_cmd);
      return (1);
    }
  else if (ret > 3)
    {
      dprintf(2, "setenv: Too many arguments.\n");
      return (1);
    }
  return (0);
}

int	setenv_manager(t_manage *man, char *cmd)
{
  char	**d_cmd;
  int	ret;

  ret = 100;
  d_cmd = get_args(cmd);
  ret = wordtab_count(d_cmd);
  if ((ret = setenv_arg_management(man, d_cmd, ret)) == 1)
    return (0);
  if (ret == MASTER_ERROR)
    return (MASTER_ERROR);
  if ((ret = my_getenv(man->all_env->my_env, d_cmd[1])) != -1)
    unsetenv_for_setenv(man, d_cmd[1], 1);
  man->all_env->my_env = d_tab_cpy_doc(man->all_env->my_env,
				       separator(d_cmd[1], d_cmd[2], '='));
  wordtab_end(d_cmd);
  return (0);
}

int	unsetenv_for_setenv(t_manage *man, char *cmd, int pos)
{
  pos = 0;
  if ((pos = my_getenv(man->all_env->my_env, cmd)) == -1)
    return (-1);
  man->all_env->my_env = d_tab_unset_doc(man->all_env->my_env, pos - 1);
  return (0);
}

int	unsetenv_manager(t_manage *man, char *cmd)
{
  int	pos;
  char	**d_cmd;
  char	**d_all;
  int	i;
  int	nb_of_args;
  int	j;

  i = -1;
  j = 1;
  d_all = my_str_to_wordtab(cmd, ' ');
  while (d_all[++i])
    {
      pos = 0;
      if ((nb_of_args = wordtab_count(d_all)) == 1)
	{
	  err_report(3, "NULL");
	  return (-1);
	}
      d_cmd = get_args(cmd);
      if ((pos = my_getenv(man->all_env->my_env, d_cmd[j])) == -1)
	return (-1);
      man->all_env->my_env = d_tab_unset_doc(man->all_env->my_env, pos - 1);
      j = j + 1;
    }
  return (0);
}
