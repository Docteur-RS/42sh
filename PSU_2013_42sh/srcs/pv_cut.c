/*
** pv_cut.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:24:15 2014 lancel_e
** Last update Sun May 25 23:24:15 2014 lancel_e
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "all.h"

void	cut_for_pv_check_del_space_pars(t_manage *man, char *buff)
{
  int	i;
  int	j;

  cut_for_pv_check_del_space_pars_ini(&i, &j);
  while (man->all_cmd->newcmd[i])
    {
      if (man->all_cmd->newcmd[i] == ' ')
	{
	  if (is_need_cpy_char(man->all_cmd->newcmd, i) == 1)
	    {
	      buff[j] = man->all_cmd->newcmd[i];
	      i = i + 1;
	      continue ;
	    }
	  else
	    buff[j] = man->all_cmd->newcmd[i];
	}
      else
	buff[j] = man->all_cmd->newcmd[i];
      i = i + 1;
      j = j + 1;
    }
  buff[j] = '\0';
  cut_for_pv_check_del_space_pars_pv_at_end(buff);
  man->all_cmd->nospbuff = buff;
}

int	cut_for_pv_check_del_space_check(t_manage *man, int ret)
{
  int	sp;
  int	i;
  char	*buff;

  sp = 0;
  i = 0;
  while (man->all_cmd->newcmd[i])
    {
      if (man->all_cmd->newcmd[i] == ';')
	nb_of_sp(man->all_cmd->newcmd, i, &sp);
      i = i + 1;
    }
  buff = my_malloc(my_strlen(man->all_cmd->newcmd) - (ret + sp) + 100);
  if (buff == NULL)
    return (MASTER_ERROR);
  cut_for_pv_check_del_space_pars(man, buff);
  return (0);
}

int	cut_for_pv_check(t_manage *man)
{
  int	i;
  int	ret;

  i = 0;
  ret = 0;
  while (man->all_cmd->newcmd[i])
    {
      if (man->all_cmd->newcmd[i] == ';')
	ret = ret + 1;
      i = i + 1;
    }
  if (ret != 0)
    {
      man->all_red->pv = 1;
      if (cut_for_pv_check_del_space_check(man, ret) == MASTER_ERROR)
	return (MASTER_ERROR);
      if (last_pv(man) == 0)
	return (0);
      return (1);
    }
  return (0);
}

int	is_need_cpy_char(char *str, int i)
{
  int	ok;

  ok = 0;
  if (i != 0)
    {
      if (str[i - 1] == ';')
	return (1);
      else
	ok = 0;
    }
  if (i != my_strlen(str))
    {
      if (str[i + 1] == ';')
	return (1);
      else
	ok = 0;
    }
  if (ok == 0)
    return (0);
  return (0);
}
