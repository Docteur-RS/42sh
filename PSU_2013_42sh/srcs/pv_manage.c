/*
** pv_manage.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:24:21 2014 lancel_e
** Last update Sun Jun  1 15:19:43 2014 lancel_e
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "dollar.h"
#include "parser_42sh.h"
#include "all.h"

int	loop_pv2(t_manage *man, char **final, char **pv, int *i)
{
  int	ret;

  ret = 0;
  if (my_strtab(final) != 2)
    {
      if (create_list(man, final) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  else
    {
      if ((ret = exec_built_ins(man, pv[*i])) == 1)
	exec_cmd(man, pv[*i]);
      if (ret == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  return (0);
}

int	loop_pv(t_manage *man, char **pv)
{
  char	**final;
  int	i;

  i = 0;
  while (pv[i])
    {
      if ((pv[i] = dispatch(pv[i], man->all_env->my_env)) == NULL)
        return (-1);
      if ((final = parser_start(string_copy(pv[i]))) == NULL)
	{
	  i = i + 1;
	  break ;
	}
      if (loop_pv2(man, final, pv, &i) == MASTER_ERROR)
	return (MASTER_ERROR);
      i = i + 1;
    }
  return (0);
}

int	loop_without_pv2(t_manage *man)
{
  int	ret;

  ret = 0;
  if ((ret = exec_built_ins(man, man->all_cmd->newcmd)) == 1)
    {
      if (ret == MASTER_ERROR)
	return (MASTER_ERROR);
      if (exec_cmd(man, man->all_cmd->newcmd) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  else if (ret == MASTER_ERROR)
    return (MASTER_ERROR);
  return (0);
}

int	loop_without_pv(t_manage *man)
{
  char	**final;

  if ((man->all_cmd->newcmd = dispatch(man->all_cmd->newcmd,
				       man->all_env->my_env)) == NULL)
    return (-1);
  if ((final = parser_start(string_copy(man->all_cmd->newcmd))) == NULL)
    return (0);
  if (my_strtab(final) != 2)
    {
      if (create_list(man, final) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  else
    if (loop_without_pv2(man) == MASTER_ERROR)
      return (MASTER_ERROR);
  return (0);
}

int		global_parsing(t_manage *man)
{
  char		**pv;
  int		ret;
  static int	once = 0;

  ret = 0;
  if (once == 0)
    if (first_env_activate(man) == MASTER_ERROR)
      return (MASTER_ERROR);
  once = 1;
  if ((ret = cut_for_pv_check(man)) == 1)
    if ((pv = cut_for_pv_pars(man)) == NULL)
      return (MASTER_ERROR);
  if (ret == MASTER_ERROR)
    return (MASTER_ERROR);
  if (man->all_red->pv == 1)
    {
      if (pre_loop_pv(man, pv, ret) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  else
    if (pre_loop_without_pv(man, ret) == MASTER_ERROR)
      return (MASTER_ERROR);
  man->all_red->pv = 0;
  return (0);
}
