/*
** pv_utils_basic.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:24:27 2014 lancel_e
** Last update Sun May 25 23:24:27 2014 lancel_e
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "all.h"

char	**cut_for_pv_pars(t_manage *man)
{
  char	**pv;

  pv = my_str_to_wordtab(man->all_cmd->nospbuff, ';');
  return (pv);
}

void	cut_for_pv_check_del_space_pars_ini(int *i, int *j)
{
  *i = 0;
  *j = 0;
}

void	cut_for_pv_check_del_space_pars_pv_at_end(char *buff)
{
  if (buff[my_strlen(buff) - 1] == ';')
    buff[my_strlen(buff) - 1] = '\0';
}

void	nb_of_sp(char *str, int i, int *sp)
{
  if (i != 0)
    if (str[i - 1] == ' ')
      *sp = *sp + 1;
  if (i != my_strlen(str))
    if (str[i + 1] == ' ')
      *sp = *sp + 1;
}

int	last_pv(t_manage *man)
{
  int	i;

  i = 0;
  while (man->all_cmd->nospbuff[i])
    {
      if (man->all_cmd->nospbuff[i] == ';')
	return (1);
      i = i + 1;
    }
  man->all_red->pv = 0;
  free(man->all_cmd->nospbuff);
  return (0);
}
