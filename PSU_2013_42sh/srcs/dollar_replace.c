/*
** main.c for 42 in /home/jamme-_c/rendu/42sh_func/echo_dollar_de_ouf
** 
** Made by jamme-_c
** Login   <jamme-_c@epitech.net>
** 
** Started on  Sat May 31 19:08:54 2014 jamme-_c
** Last update Sun Jun  1 14:20:10 2014 lancel_e
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "dollar.h"

char	*cpy_to_char(char *str, char end, int *i)
{
  char	*cmd;
  int	save;
  int	ct;

  ct = 0;
  save = *i;
  while (str[*i] && str[*i] != end)
    {
      ct = ct + 1;
      *i = *i + 1;
    }
  if ((cmd = malloc(ct + 1)) == NULL)
    return (NULL);
  ct = 0;
  while (str[save] && str[save] != end)
    {
      cmd[ct] = str[save];
      save = save + 1;
      ct = ct + 1;
    }
  cmd[ct] = '\0';
  return (cmd);
}

char	*my_replace(char *before, char *cmd, int *i)
{
  char	*after;
  char	*final;

  after = cpy_to_char(cmd, '\0', i);
  final = my_strcopy(before, "\n", 0);
  final = my_strcopy(final, after, 0);
  return (final);
}

char	*search(char *str, char **envp)
{
  char	*final;
  char	*var_name;
  char	*before;
  char	*after;
  char	*content;
  int	i;

  i = 0;
  before = cpy_to_char(str, '$', &i);
  var_name = copy_var_name(str, ' ', '$', &i);
  var_name = var_name + 1;
  if (var_name[0] == '\0')
    return (my_replace(before, str, &i));
  else if ((content = my_getenv_line(envp, var_name)) == NULL)
    {
      fprintf(stderr, "%s: Undefined variable.\n", var_name);
      return (NULL);
    }
  after = cpy_to_char(str, '\0', &i);
  final = my_strcopy(before, content, 0);
  final = my_strcopy(final, after, 0);
  return (final);
}

void	del_carac_to_dollar(char *cmd)
{
  int	i;

  i = 0;
  while (cmd[i])
    {
      if (cmd[i] == '\n')
	cmd[i] = '$';
      ++i;
    }
}

char	*dispatch(char *cmd, char **envp)
{
  int	nb_dollars;
  int	i;

  if ((nb_dollars = nb_dollars_exist(cmd)) == 0)
    return (cmd);
  i = 0;
  while (i < nb_dollars)
    {
      if ((cmd = search(cmd, envp)) == NULL)
	return (NULL);
      ++i;
    }
  del_carac_to_dollar(cmd);
  return (cmd);
}
