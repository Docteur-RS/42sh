/*
** change_dir.c for mysh in /home/lancel_e/rendu/PSU_2013_minishell2
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sat Mar  8 17:55:45 2014 lancel_e
** Last update Sun May 25 22:53:02 2014 grelli_t
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "all.h"

void	all_free_cd(char *epure, char *last)
{
  my_free(epure);
  my_free(last);
}

int	is_cmd_cd_ok(char *buff)
{
  int	i;
  int	ct;

  i = 0;
  ct = 0;
  while (buff[i])
    {
      if (buff[i] == ' ')
	ct = ct + 1;
      i = i + 1;
    }
  if (ct > 1)
    return (err_report(7, "NULL"));
  return (0);
}

char	*go_from_home(t_manage *man, char *buff)
{
  char	*home;
  char	*final;

  if ((home = my_getenv_line(man->all_env->my_env, "HOME")) == NULL)
    {
      printf("$HOME is not defined\n");
      return (NULL);
    }
  buff = buff + 1;
  if ((final = my_strcopy(home, buff, 0)) == NULL)
    return (NULL);
  return (final);
}

char	*go_home(t_manage *man)
{
  char	*home;

  if ((home = my_getenv_line(man->all_env->my_env, "HOME")) == NULL)
    {
      printf("$HOME is not defined\n");
      return (NULL);
    }
  return (home);
}

int		my_cd(t_manage *man, char *buffer)
{
  struct stat	s;
  int	ret;

  ret = 0;
  if ((ret = cd_less(man, buffer)) == MASTER_ERROR)
    return (MASTER_ERROR);
  if (ret != ERROR)
    return (0);
  if (is_cmd_cd_ok(buffer) == -1)
    return (-1);
  if (my_strlen(buffer) == 2)
    buffer = go_home(man);
  else if (cd_options(man, &buffer) == ERROR)
    return (ERROR);
  if (access(buffer, F_OK) == -1)
    return (err_report(4, buffer));
  if (stat(buffer, &s) == -1)
    return (ERROR);
  if (cd_error(buffer, &s) == ERROR)
    return (ERROR);
  if (call_pwd(man, man->all_env->my_env) == NULL)
    return (MASTER_ERROR);
  return (0);
}
