/*
** my_getnbr.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:22:21 2014 lancel_e
** Last update Sun May 25 23:22:21 2014 lancel_e
*/

#include "all.h"

int	is_neg(char *str)
{
  int	i;
  int	cpt;

  i = 0;
  cpt = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
        ++cpt;
      ++i;
    }
  if (cpt % 2 != 0)
    return (1);
  else
    return (0);
}

int	is_num(int nb)
{
  if (nb >= '0' && nb <= '9')
    return (1);
  else
    return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	result;

  result = 0;
  i = 0;
  while (is_num(str[i]) == 0)
    ++i;
  while (is_num(str[i]) == 1)
    {
      result = ((result * 10) + (str[i] - 48));
      ++i;
    }
  if (is_neg(str) == 1)
    result = -result;
  return (result);
}
