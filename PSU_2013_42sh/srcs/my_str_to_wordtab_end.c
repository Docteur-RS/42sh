/*
** my_str_to_wordtab_end.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:33:49 2014 lancel_e
** Last update Mon Apr 21 19:06:48 2014 lancel_e
*/

#include <stdlib.h>
#include "all.h"

int	wordtab_count(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i]);
  return (i);
}

void	wordtab_end(char **wtab)
{
  int	i;

  i = 0;
  while (wtab[i] != '\0')
    {
      free(wtab[i]);
      i = i + 1;
    }
  my_free(wtab);
}
