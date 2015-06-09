/*
** my_exit.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:21:49 2014 lancel_e
** Last update Sun May 25 23:21:52 2014 lancel_e
*/

#include <stdio.h>
#include "all.h"

int	my_exit(t_manage *man, char *cmd)
{
  char	**d_cmd;

  if ((d_cmd = get_args(cmd)) == NULL)
    return (-1);
  if (my_strlen(d_cmd[0]) != 4)
    {
      err_report(0, d_cmd[0]);
      wordtab_end(d_cmd);
      return (-1);
    }
  if (wordtab_count(d_cmd) == 1)
    man->all_ret->has_exit = 0;
  else if (wordtab_count(d_cmd) == 2 && is_number(d_cmd[1]) == 0)
    man->all_ret->has_exit = my_getnbr(d_cmd[1]);
  else
    {
      err_report(1, "NULL");
      wordtab_end(d_cmd);
      return (-1);
    }
  wordtab_end(d_cmd);
  return (MASTER_ERROR);
}
