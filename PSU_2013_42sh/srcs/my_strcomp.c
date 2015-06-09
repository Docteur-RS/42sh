/*
** my_strcomp.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:22:54 2014 lancel_e
** Last update Sun Jun  1 11:58:27 2014 lancel_e
*/

#include "all.h"

int	my_strcomp(char *base, char *search)
{
  int	i;

  i = 0;
  while (base[i])
    {
      if (base[i] != search[i])
	return (0);
      i = i + 1;
    }
  return (1);
}

int	my_strcomp_restrict(char *base, char *search)
{
  int	i;

  i = 0;
  if (my_strlen(base) != my_strlen(search))
    return (0);
  while (base[i] && search[i])
    {
      if (base[i] != search[i])
	return (0);
      i = i + 1;
    }
  return (1);
}
