/*
** parser_spacestabulations.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:22:04 2014 lancel_e
** Last update Sun Jun  1 19:22:05 2014 lancel_e
*/

#include <stdlib.h>
#include "parser_42sh.h"

char	*parser_space(char *text, char save, int *result)
{
  if ((*text == 34) || (*text == 39))
    {
      save = *text;
      *result = *result + 1;
      text = text + 1;
      while ((*text != '\0') && (*text != save))
	{
	  text = text + 1;
	  *result = *result + 1;
	}
      if (*text == '\0')
	return (NULL);
      *result = *result + 1;
      text = text + 1;
    }
  else
    {
      while ((*text != '\0') && ((*text < 0) || (*text > 32)))
	{
	  *result = *result + 1;
	  text = text + 1;
	}
    }
  return (text);
}

int	parser_spaces_tabulations_count_less(char *text)
{
  int	search;
  int	result;

  result = 0;
  while ((*text != '\0') && ((*text >= 1) && (*text <= 32)))
    text = text + 1;
  while (*text != '\0')
    {
      if ((text = parser_space(text, 0, &result)) == NULL)
	return (-1);
      search = 0;
      while ((*text != '\0') && ((*text >= 1) && (*text <= 32)))
	{
	  text = text + 1;
	  search = search + 1;
	}
      if (*text != '\0')
	{
	  text = text - search;
	  result = result + 1;
	  while ((*text != '\0') && ((*text >= 1) && (*text <= 32)))
	    text = text + 1;
	}
    }
  return (result);
}

void	parser_spaces_tabulations_create_less_next0(char *text, char *pointer)
{
  *pointer = *text;
}

char	*parser_space_next1(char *text, char *pointer,
			 int *search, int flag)
{
  char	save;

  *search = 0;
  if ((*text == 34) || (*text == 39))
    {
      save = *text;
      parser_spaces_tabulations_create_less_next0(text++, pointer++);
      while ((*text != '\0') && (*text != save))
	parser_spaces_tabulations_create_less_next0(text++, pointer++);
      if (*text == '\0')
	return (NULL);
      parser_spaces_tabulations_create_less_next0(text++, pointer++);
    }
  else
    while ((*text != '\0') && ((*text < 0) || (*text > 32)))
      parser_spaces_tabulations_create_less_next0(text++, pointer++);
  while ((*text != '\0') && ((*text >= 1) && (*text <= 32)))
    {
      text = text + 1;
      *search = *search + 1;
    }
  if (flag >= 0)
    return (text);
  else
    return (pointer);
}

char	*parser_spaces_tabulations_create_less(char *text,
					       int malloc_size, int search)
{
  char	*pointer;
  char	*pointer_save;

  pointer = malloc(sizeof(char) * (malloc_size + 1));
  if (pointer == NULL)
    return (NULL);
  while ((*text != '\0') && ((*text >= 1) && (*text <= 32)))
    text = text + 1;
  while (*text != '\0')
    {
      pointer_save = parser_space_next1(text, pointer, &search, (-1));
      text = parser_space_next1(text, pointer, &search, 0);
      pointer = pointer_save;
      if (*text != '\0')
	{
	  text = text - search;
	  *pointer = ' ';
	  pointer = pointer + 1;
	  while ((*text != '\0') && ((*text >= 1) && (*text <= 32)))
	    text = text + 1;
	}
    }
  *pointer = '\0';
  return (pointer - malloc_size);
}
