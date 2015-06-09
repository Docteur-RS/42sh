/*
** wildcard_handling.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:19:10 2014 lancel_e
** Last update Sun Jun  1 19:19:11 2014 lancel_e
*/

#include <sys/types.h>
#include <glob.h>
#include <stdlib.h>
#include "globing.h"
#include "all.h"

int		check_for_wildcards(char **args)
{
  int		i;
  int		n;
  int		nb;

  n = 0;
  nb = 0;
  while (args[n] != NULL)
    {
      i = 0;
      while (args[n][i] != '\0')
	{
	  if (args[n][i] == '*')
	    ++nb;
	  ++i;
	}
      ++n;
    }
  return (nb);
}

int		has_wildcard(char *arg)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (arg[i] != '\0')
    {
      if (arg[i] == '*')
	++nb;
      ++i;
    }
  return (nb);
}

int		exec_glob(char **args, glob_t globbuf, char **env, char *path)
{
  int		i;
  int		n;
  pid_t		pid;

  i = 0;
  n = 0;
  while (args[i] != NULL)
    {
      if (has_wildcard(args[i]) == 0)
	globbuf.gl_pathv[n++] = args[i];
      ++i;
    }
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      if (setsid() == -1)
	return (-1);
      execve(path, &globbuf.gl_pathv[0], env);
      return (MASTER_ERROR);
    }
  if (pid > 0)
    wait(&pid);
  return (0);
}

int		glob_handling(char **env, char **args, char *path)
{
  glob_t	globbuf;
  int		i;
  int		n;
  int		flag;

  i = 0;
  flag = 0;
  globbuf.gl_offs = wordtab_count(args) - check_for_wildcards(args);
  while (args[i] != NULL)
    if ((has_wildcard(args[i])) > 0)
      {
	if (flag == 0)
	  {
	    n = glob(args[i++], GLOB_DOOFFS, NULL, &globbuf);
	    flag = 1;
	  }
	else
	  n = glob(args[i++], GLOB_DOOFFS | GLOB_APPEND, NULL, &globbuf);
	if (n != 0)
	  return (n);
      }
    else
      ++i;
  return (exec_glob(args, globbuf, env, path));
}
