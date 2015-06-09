/*
** echo_tcsh_ref.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:19:08 2014 lancel_e
** Last update Sun Jun  1 14:55:54 2014 lancel_e
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "all.h"

char	check_string(char *cmd)
{
  int	i;
  int	double_quote;
  int	quote;

  i = 0;
  double_quote = 0;
  quote = 0;
  while (cmd[i] != ' ')
    ++i;
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '"')
	++double_quote;
      else if (cmd[i] == '\'')
	++quote;
      ++i;
    }
  if ((quote % 2 == 0) && (double_quote % 2 == 0))
    return (' ');
  else if ((quote % 2 == 1) && (double_quote % 2 == 0))
    return ('\'');
  else if ((quote % 2 == 0) && (double_quote % 2 == 1))
    return ('"');
  return (' ');
}

int		print_escape_char(char char_to_print, int i)
{
  int			n;
  const t_escape	escape[] = {
    {'a', '\a'},
    {'b', '\b'},
    {'t', '\t'},
    {'n', '\n'},
    {'v', '\v'},
    {'f', '\f'},
    {'r', '\r'},
    {'\\', '\\'},
    {'\0', '\0'},
  };

  n = 0;
  while (escape[n].escape_char != '\0')
    {
      if (char_to_print == escape[n].escape_char)
	{
	  my_putchar(escape[n].to_print);
	  return (i += 2);
	}
      ++n;
    }
  return (i += 2);
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

char	print_arg(char *cmd, char pattern)
{
  int	i;

  i = 1;
  if (strcmp("echo", cmd) == 0)
    return ('\n');
  else if (strcmp("echo -n", cmd) == 0)
    return ('\0');
  while (cmd[i - 1] != ' ')
    i = i + 1;
  if (pattern == '\0')
    i = i + NB_TO_ARG;
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '\\' &&
	  (cmd[i + 1] == 'a' || cmd[i + 1] == 'b' || cmd[i + 1] == 't' ||
	   cmd[i + 1] == 'n' || cmd[i + 1] == 'v' || cmd[i + 1] == 'f' ||
	   cmd[i + 1] == 'r' || cmd[i + 1] == '\\'))
	{
	  i = print_escape_char(cmd[i + 1], i);
	  continue ;
	}
      my_putchar(cmd[i++]);
    }
  return ('\n');
}

int	echo_tcsh_ref(char *cmd)
{
  char	unmatched;

  if ((unmatched = check_string(cmd)) == '"' || unmatched == '\'')
    {
      printf("Unmatched %c.\n", unmatched);
      return (-1);
    }
  if (minus_n_option(cmd) == 1)
    my_putchar(print_arg(cmd, '\0'));
  else
    my_putchar(print_arg(cmd, '\n'));
  return (0);
}
