/*
** my_strcopy.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:20:37 2014 lancel_e
** Last update Sun Jun  1 19:20:38 2014 lancel_e
*/

#include <stdlib.h>
#include "edollar.h"

void	my_strcpy_free(char *first, char *second, int flag)
{
  if (flag == 0)
    return ;
  else if (flag == 1)
    free(first);
  else if (flag == 0)
    free (second);
  else if (flag == 2)
    {
      free(first);
      free(second);
    }
}

char	*my_strcopy(char *first, char *second, int flag)
{
  char	*final;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((final = malloc((my_strlen(first) + my_strlen(second) + 1)
		      * sizeof(char *))) == NULL)
    return (NULL);
  while (first[i])
    {
      final[i] = first[i];
      i = i + 1;
    }
  while (second[j])
    {
      final[i] = second[j];
      i = i + 1;
      j = j + 1;
    }
  final[i] = '\0';
  my_strcpy_free(first, second, flag);
  return (final);
}
