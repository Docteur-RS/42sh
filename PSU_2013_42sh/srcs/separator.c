/*
** separator.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:19:56 2014 lancel_e
** Last update Sun Jun  1 19:19:57 2014 lancel_e
*/

#include <unistd.h>
#include <stdlib.h>
#include "all.h"

void	disp_pwd(char *final)
{
  my_putstr("\e[1;32m");
  final = final + 4;
  my_putstr(final);
  final = final - 4;
  my_putstr("\e[0m");
  my_putchar('\n');
}

char	*separator(char *s1, char *s2, char c)
{
  int	i;
  int	j;
  char	*final;

  final = NULL;
  i = -1;
  j = 0;
  if ((final = malloc(my_strlen(s1) + my_strlen(s2) + 2)) == NULL)
    return (NULL);
  final[my_strlen(s1) + my_strlen(s2) + 1] = '\0';
  while (s1[++i])
    {
      final[j] = s1[i];
      ++j;
    }
  i = -1;
  final[j] = c;
  ++j;
  while (s2[++i])
    {
      final[j] = s2[i];
      ++j;
    }
  return (final);
}
