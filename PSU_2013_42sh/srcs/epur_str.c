/*
** epur_str.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:19:41 2014 lancel_e
** Last update Sun May 25 23:38:12 2014 lancel_e
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "all.h"

void	ini_var(int *i, int *k)
{
  *i = 0;
  *k = 0;
}

void	first_space(char *str, int *i)
{
  while (str[*i] == ' ' && str[*i])
    *i = *i + 1;
}

char	*my_epur(char *str)
{
  char	*ret;
  int	i;
  int	k;

  ini_var(&i, &k);
  if ((ret = my_malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  first_space(str, &i);
  while (str[i])
    {
      if (str[i] != ' ')
	{
          ret[k] = str[i];
          k = k + 1;
        }
      else if (str[i + 1] != '\0' && str[i] == ' ' && str[i + 1] != ' ')
        {
          ret[k] = ' ';
          k = k + 1;
        }
      i = i + 1;
    }
  ret[k] = '\0';
  free(str);
  return (ret);
}

void	replace_all_tab(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\t')
	str[i] = ' ';
      i = i + 1;
    }
}
