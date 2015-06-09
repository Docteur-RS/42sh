/*
** main.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:21:28 2014 lancel_e
** Last update Wed May 28 21:13:27 2014 lancel_e
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "dollar.h"
#include "all.h"

int	verified_read(t_manage *man)
{
  if ((man->all_cmd->cmd = get_next_line(0)) == NULL)
    {
      my_putstr("exit\n");
      return (MASTER_ERROR);
    }
  if (man->all_cmd->cmd[0] == '\0')
    return (1);
  replace_all_tab(man->all_cmd->cmd);
  if ((man->all_cmd->newcmd = my_epur(man->all_cmd->cmd)) == NULL)
    return (-1);
  return (0);
}

int	sub_main(t_manage *man)
{
  int	ret;

  while (44)
    {
      my_putstr("\e[0;35m");
      my_putstr("B~W> ");
      my_putstr("\e[0m");
      if ((ret = verified_read(man)) == MASTER_ERROR)
	return (MASTER_ERROR);
      if (ret == 1)
	continue ;
      if (ret != -1)
	if (global_parsing(man) == MASTER_ERROR)
	  return (man->all_ret->has_exit);
    }
  return (0);
}

void	 struc_ini(t_manage *man, char **argv, char **envp, int argc)
{
  man->all_env->oldpwd = NULL;
  man->all_base->argc = argc;
  man->all_base->argv = argv;
  man->all_base->envp = envp;
  man->all_red->pv = 0;
  man->all_red->my_pipe = 0;
  man->all_red->red_l = 0;
  man->all_red->red_r = 0;
  man->all_red->d_red_l = 0;
  man->all_red->d_red_r = 0;
  man->all_red->my_or = 0;
  man->all_red->my_and = 0;
  man->all_ret->has_exit = 0;
}

int			main(int argc, char **argv, char **envp)
{
  int			ret;
  t_manage		man;
  t_cmd			all_cmd;
  t_env			all_env;
  t_error_flag		all_ret;
  t_base		all_base;
  t_redirec_found	all_red;

  man.all_cmd = &all_cmd;
  man.all_env = &all_env;
  man.all_ret = &all_ret;
  man.all_base = &all_base;
  man.all_red = &all_red;
  signal_catch();
  struc_ini(&man, argv, envp, argc);
  ret = sub_main(&man);
  return (ret);
}
