/*
** my_getenv_line.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:22:14 2014 lancel_e
** Last update Sun May 25 23:22:14 2014 lancel_e
*/

#include <unistd.h>
#include "all.h"

int	match_line(char *s1, char *s2)
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

char	*my_getenv_line_spe(char **envp, char *str)
{
  char	*tmp;
  char	*final;

  final = NULL;
  tmp = NULL;
  if (str == NULL || str[0] == '\0')
    return ("$");
  if ((tmp = line_envp_line(envp, str)) == NULL)
    return (NULL);
  if ((final = my_strcpy_since_line(tmp, final, my_while_sep_isnt(tmp, '='))) ==
      NULL)
    return (NULL);
  return (final);
}

char	*my_getenv_line(char **envp, char *str)
{
  char	*tmp;
  char	*final;

  final = NULL;
  tmp = NULL;
  if (str == NULL)
    return (NULL);
  if ((tmp = line_envp_line(envp, str)) == NULL)
    return (NULL);
  if ((final = my_strcpy_since_line(tmp, final, my_while_sep_isnt(tmp, '='))) ==
      NULL)
    return (NULL);
  return (final);
}

char	*line_envp_line(char **envp, char *str)
{
  int	i;

  i = 0;
  while (envp[i])
    {
      if (match_line(envp[i], str) == 1)
	return (envp[i]);
      ++i;
    }
  return (NULL);
}
