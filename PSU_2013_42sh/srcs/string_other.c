/*
** string_other.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:22:38 2014 lancel_e
** Last update Sun Jun  1 19:22:38 2014 lancel_e
*/

#include <stdlib.h>
#include "parser_42sh.h"

int	string_length_define(char *start, char *end)
{
  int	result;

  result = 0;
  while ((*start != '\0') && (start != end))
    {
      result = result + 1;
      start = start + 1;
    }
  return (result);
}

char	*string_copy_define(char *start, char *end)
{
  int	length;
  char	*pointer;

  if ((start == NULL) || (end == NULL))
    return (NULL);
  length = string_length_define(start, end);
  if ((pointer = malloc(sizeof(char) * (length + 1))) == NULL)
    return (NULL);
  while ((*start != '\0') && (start != end))
    {
      *pointer = *start;
      pointer = pointer + 1;
      start = start + 1;
    }
  *pointer = '\0';
  pointer = pointer - length;
  return (pointer);
}

char	*string_search_define(char *text, char *search)
{
  if ((text == NULL) || (search == NULL))
    return (NULL);
  if (*search == '\0')
    {
      while (*text != '\0')
	text = text + 1;
      return (text);
    }
  while ((*text != '\0') &&
         (string_compare(text, search, (-1)) != 0))
      text = text + 1;
  return (text);
}
