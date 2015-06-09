/*
** env_utils.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:19:35 2014 lancel_e
** Last update Sun Jun  1 14:57:31 2014 lancel_e
*/

#include <unistd.h>
#include <stdlib.h>
#include "all.h"

void	env_disp(char **envp)
{
  int	i;

  i = 0;
  while(envp[i] != NULL)
    {
      my_putstr(envp[i]);
      my_putchar('\n');
      i = i + 1;
    }
}

int	my_strtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}

void	d_tab_unset_doc_ini(t_unset *unset, int flag)
{
  if (flag == 0)
    {
      unset->i = 0;
      unset->j = 0;
      unset->k = 0;
    }
  else
    {
      unset->k = unset->k + 1;
      unset->i = unset->i + 1;
    }
}

int		first_env_activate(t_manage *man)
{
  static int	once = 0;
  char		*rescue;

  if (once == 0)
    if (man->all_base->envp[0] == NULL)
      {
	if ((rescue = str_mallocate("PATH=/usr/local/bin:/bin:/usr/bin:/sbin"))
	    == NULL)
	  return (MASTER_ERROR);
	if ((man->all_env->my_env = my_malloc(2)) == NULL)
	  return (MASTER_ERROR);
	man->all_env->my_env[1] = '\0';
	if ((man->all_env->my_env[0] = my_malloc(1)) == NULL)
	  return (MASTER_ERROR);
	man->all_env->my_env[0] = rescue;
	return (0);
      }
  if (once == 0)
    man->all_env->my_env = man->all_base->envp;
  once = 1;
  return (0);
}
