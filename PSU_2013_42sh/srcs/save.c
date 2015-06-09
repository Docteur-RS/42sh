/*
** echo_tcsh_ref.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:19:08 2014 lancel_e
** Last update Sun May 25 23:19:09 2014 lancel_e
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "all.h"

void	print_char(char c)
{
  write(1, &c, 1);
}


int	minus_n_option(char *cmd)
{
  int	i;

  i = 0;
  while (cmd[i])
    {
      if (cmd[i] == '-' && cmd[i + 1] == 'n')
	return (1);
      ++i;
    }
  return (0);
}

void	print_arg(char *cmd, char pattern)
{
  int	i;

  i = 1;
  if (strcmp("echo", cmd) == 0)
    {
      printf("\n");
      return ;
    }
  else if (strcmp("echo -n", cmd) == 0)
    return ;
  while (cmd[i] != ' ')
    i = i + 1;
  ++i;
  if (pattern == '\0')
    i = i + NB_TO_ARG;
  while (cmd[i])
    {
      print_char(cmd[i]);
      ++i;
    }
  print_char(pattern);
}

int	echo_tcsh_ref(char *cmd)
{
  if (minus_n_option(cmd) == 1)
    print_arg(cmd, '\0');
  else
    print_arg(cmd, '\n');
  return (0);
}
