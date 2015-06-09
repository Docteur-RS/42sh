/*
** my_str_cpy.c for 42sh in /home/grelli_t/ABUZAY/42sh/my_geten
** 
** Made by grelli_t
** Login   <grelli_t@epitech.net>
** 
** Started on  Wed Mar 26 15:59:22 2014 grelli_t
** Last update Sun May 25 23:23:01 2014 lancel_e
*/

#include <unistd.h>
#include <stdlib.h>
#include "all.h"

int	my_strlen_line(char *str, int line)
{
  int	i;

  i = 0;
  while (str[line])
  {
    ++line;
    ++i;
  }
  return (i);
}

int	my_while_sep_isnt(char	*str, char sep)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == sep)
	return (i);
      ++i;
    }
  return (0);
}

char	*my_strcpy(char *final, char *start)
{
  int	i;

  if (start == NULL)
    return (NULL);
  if ((final = malloc(my_strlen_line(start, 0) + 1)) == NULL)
    return (NULL);
  i = -1;
  while (start[++i])
    final[i] = start[i];
  final[i] = '\0';
  return (final);
}

char	*my_strcpy_since_line(char *start, char *final, int line)
{
  int	i;
  int	j;

  (void)line;
  final = NULL;
  i = -1;
  if (start == NULL)
      return (NULL);
  while (start[++i] != '=' && start[i]);
  ++i;
  if (start[i] == '\0')
    return (NULL);
  if ((final = malloc((my_strlen_line(start, i) + 1))) == NULL)
    return (NULL);
  final[my_strlen_line(start, i)] = '\0';
  --i;
  j = -1;
  while (start[++i])
      final[++j] = start[i];
  return (final);
}
