/*
** parser_reconstruct.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:20:29 2014 lancel_e
** Last update Sun Jun  1 19:20:30 2014 lancel_e
*/

#include <stdlib.h>
#include "parser_42sh.h"

void	string_replace_next(char *pointer, char *text)
{
  *pointer = *text;
}

char	*string_replace(char *text, char *start, char *end, char *replace)
{
  int	length;
  char	*pointer;

  length = string_length(text) + string_length(replace)
    - (string_length(start) - string_length(end));
  if ((pointer = malloc(sizeof(char) * (length + 1))) == NULL)
    return (NULL);
  while ((*text != '\0') && (text != start))
    string_replace_next(pointer++, text++);
  while (*replace != '\0')
    string_replace_next(pointer++, replace++);
  while (*end != '\0')
    string_replace_next(pointer++, end++);
  *pointer = '\0';
  return (pointer - length);
}

char	*parser_del_next0(char *text, char *search, char *replace)
{
  char	*text_before;
  char	*text_after;
  char	*end;
  char	*start;

  start = string_copy(text);
  text_before = start;
  text_after = NULL;
  while (*start != '\0')
    {
      if ((*start == *search) && (string_compare(start, search, (-1)) == 0))
	{
	  end = start + string_length(search);
	  if ((text_after = string_replace(text_before, start,
					   end, replace)) == NULL)
	    return (NULL);
	  free(text_before);
	  text_before = string_copy(text_after);
	  start = text_before;
	}
      start = start + 1;
    }
  if (text_after != NULL)
    free(text_after);
  return (text_before);
}

char	*parser_eliminate_keywords_with_spaces(char *text)
{
  char	*text_before;
  char	*text_after;

  text_before = string_copy(text);
  text_after = parser_del_next0(text_before, " > > ", " >> ");
  free(text_before);
  text_before = parser_del_next0(text_after, " < < ", " << ");
  free(text_after);
  text_after = parser_del_next0(text_before, " | | ", " || ");
  free(text_before);
  text_before = parser_del_next0(text_after, " & & ", " && ");
  free(text_after);
  return (text_before);
}
