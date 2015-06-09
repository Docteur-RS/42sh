/*
** dollar_utils.c for 42sh in /home/lancel_e/Documents/PROJET/new 42sh/NEW WORKSPACE/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 14:17:22 2014 lancel_e
** Last update Sun Jun  1 14:23:33 2014 lancel_e
*/

#include "dollar.h"

int	nb_dollars_exist(char *str)
{
  int	dollar;
  int	i;

  i = 0;
  dollar = 0;
  while (str[i])
    {
      if (str[i] == '$' && str[i + 1] != '\0')
        dollar = dollar + 1;
      i = i + 1;
    }
  return (dollar);
}
