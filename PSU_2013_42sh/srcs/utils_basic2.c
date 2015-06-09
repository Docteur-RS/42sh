/*
** utils_basic2.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:26:40 2014 lancel_e
** Last update Sun May 25 23:39:04 2014 lancel_e
*/

#include <unistd.h>
#include "all.h"

int	strlen_to_limit(char *str, char sepa)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == sepa)
        break ;
      i = i + 1;
    }
  return (i);
}

int	strcomp_env(char *one, char *two, char sepa)
{
  int	i;

  i = 0;
  while (one[i] != sepa && one[i] && two[i])
    {
      if (one[i] != two[i])
        return (-1);
      i = i + 1;
    }
  return (0);
}

int	is_number(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < 48 || str[i] > 57) && str[i] != '-')
	return (-1);
      i = i + 1;
    }
  return (0);
}

char	*str_mallocate(char *str)
{
  char	*new;
  int	i;

  i = 0;
  if ((new = my_malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i])
    {
      new[i] = str[i];
      i = i + 1;
    }
  new[i] = '\0';
  return (new);
}
