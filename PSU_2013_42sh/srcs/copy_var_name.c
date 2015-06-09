/*
** copy_var_name.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:21:14 2014 lancel_e
** Last update Sun Jun  1 19:21:15 2014 lancel_e
*/

#include <stdlib.h>
#include <stdio.h>

char	*copy_var_name(char *str, char end1, char end2,  int *i)
{
  char	*cmd;
  int	save;
  int	ct;

  ct = 1;
  *i = *i + 1;
  save = *i;
  while (str && str[*i] && str[*i] != end1 && str[*i] != end2)
    {
      ct = ct + 1;
      *i = *i + 1;
    }
  if ((cmd = malloc(ct + 1)) == NULL)
    return (NULL);
  cmd[0] = '$';
  ct = 1;
  while (str[save] && str[save] != end1 && str[save] != end2)
    {
      cmd[ct] = str[save];
      save = save + 1;
      ct = ct + 1;
    }
  cmd[ct] = '\0';
  return (cmd);
}
