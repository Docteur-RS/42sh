/*
** my_getenv.c for 42sh in ~/42sh/VERIFIER LA NORME/srcs/Fichiers à check/
** 
** Made by lalann_a
** Login   <lalann_a@epitech.net>
** 
** Started on  Sun Jun  1 14:45:11 2014 lalann_a
** Last update Sun Jun  1 14:45:56 2014 lalann_a
*/

#include <unistd.h>
#include "all.h"

int	match(char *s1, char *s2)
{
  int	i;

  i = -1;
  while (s2[++i])
    {
      if (s1[i] != s2[i])
	return (-1);
    }
  i = -1;
  while (s1[++i] != '=' && s1[i])
    {
      if (s1[i] != s2[i])
	return (-1);
    }
  if (s2[i] != '\0')
    return (-1);
  return (1);
}

int	my_getenv(char **envp, char *str)
{
  char	tmp;

  if (str == NULL)
    return (-1);
  if ((tmp = line_envp(envp, str)) == -1)
    return (-1);
  return (tmp);
}

int	line_envp(char **envp, char *str)
{
  int	i;

  i = 0;
  while (envp[i])
    {
      if (match(envp[i], str) == 1)
	return (++i);
      ++i;
    }
  return (-1);
}
