/*
** exec_cmd_utils.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:20:45 2014 lancel_e
** Last update Sun Jun  1 17:40:11 2014 lancel_e
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "all.h"

char	**get_path(char **envp)
{
  int	i;
  char	**pre;
  char	**path;

  i = 0;
  if (envp == NULL)
    return (NULL);
  while (envp[i])
    {
      if (envp[i][0] == 'P' && envp[i][1] == 'A' &&
          envp[i][2] == 'T' && envp[i][3] == 'H' &&
          envp[i][4] == '=')
        {
	  pre = my_str_to_wordtab(envp[i], '=');
	  path = my_str_to_wordtab(pre[1], ':');
	  wordtab_end(pre);
	  return (path);
        }
      i = i + 1;
    }
  return (NULL);
}

char	**get_args(char *cmd)
{
  char	**d_arg;

  if (cmd == NULL)
    return (NULL);
  if ((d_arg = my_str_to_wordtab(cmd, ' ')) == NULL)
    return (NULL);
  return (d_arg);
}

char	*finall_path_maker(char *one, char *two)
{
  char	*three;
  int	i;
  int	j;

  j = 0;
  i = 0;
  if ((three = malloc(my_strlen(one) + my_strlen(two) + 2)) == NULL)
    return (NULL);
  while (one[i])
    {
      three[i] = one[i];
      i = i + 1;
    }
  three[i] = '/';
  i = i + 1;
  while (two[j] && two[j] != ' ')
    {
      three[i] = two[j];
      i = i + 1;
      j = j + 1;
    }
  three[i] = '\0';
  return (three);
}

char	*get_cmd(char *cmd)
{
  char	*ret;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (cmd[i] != ' ' && cmd[i])
    {
      i = i + 1;
      j = j + 1;
    }
  if ((ret = my_malloc(j + 1)) == NULL)
    return (NULL);
  i = 0;
  while (cmd[i] != ' ' && cmd[i])
    {
      ret[i] = cmd[i];
      i = i + 1;
    }
  ret[i] = '\0';
  return (ret);
}

int	is_exec_found(char **path, char *cmd, int *i)
{
  int	ok;

  ok = 0;
  while (path[*i])
    {
      if (access(finall_path_maker(path[*i], get_cmd(cmd)), X_OK) != -1)
	{
	  ok = 1;
	  return (ok);
	}
      *i = *i + 1;
    }
  return (ok);
}
