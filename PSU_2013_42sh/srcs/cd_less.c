/*
** cd_less.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:17:05 2014 lancel_e
** Last update Sun May 25 23:17:05 2014 lancel_e
*/

#include <string.h>
#include <stdlib.h>
#include "all.h"

int	check_olpwd(t_manage * man)
{
  if (man->all_env->oldpwd == NULL)
    if ((man->all_env->oldpwd = my_getenv_line(man->all_env->my_env, "PWD")) ==
	NULL)
      return (ERROR);
  return (1);
}

int	cd_less_part_call(t_manage *man)
{
  if (check_olpwd(man) != 1)
    return (0);
  if (chdir(man->all_env->oldpwd) == ERROR)
    return (x_report(0));
  if (call_pwd(man, man->all_env->my_env) == NULL)
    return (MASTER_ERROR);
  return (0);
}

int	cd_less(t_manage *man, char *buffer)
{
  int	ret;

  ret = 0;
  if (strcmp(buffer, "cd -") == 0)
    {
      if (check_olpwd(man) == ERROR)
	return (ERROR);
      if ((ret = cd_less_part_call(man)) ==  ERROR)
	{
	  err_report(8, NULL);
	  return (ERROR);
	}
      else if (ret == MASTER_ERROR)
	return (MASTER_ERROR);
      return (0);
    }
  return (ERROR);
}
