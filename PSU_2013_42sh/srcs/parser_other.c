/*
** parser_other.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:21:58 2014 lancel_e
** Last update Sun Jun  1 19:34:57 2014 lancel_e
*/

#include <stdlib.h>
#include "parser_42sh.h"

char	*parser_add_spaces_before_after(char *text)
{
  int	length;
  char	*pointer;

  length = string_length(text) + 1;
  pointer = malloc(sizeof(char) * (length + 1));
  while (*text != '\0')
    {
      *pointer = *text;
      text = text + 1;
      pointer = pointer + 1;
    }
  *pointer = ' ';
  pointer = pointer + 1;
  *pointer = '\0';
  return (pointer - length);
}

void	parser_free_char_star_star(char **commands)
{
  int	count;

  count = 0;
  if (commands != NULL)
    {
      while (commands[count] != NULL)
	{
	  free(commands[count]);
	  count = count + 1;
	}
      free(commands);
    }
}
