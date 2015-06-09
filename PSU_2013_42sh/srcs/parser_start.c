/*
** parser_start.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:20:23 2014 lancel_e
** Last update Sun Jun  1 19:20:24 2014 lancel_e
*/

#include <stdlib.h>
#include "parser_42sh.h"

char	*parser_add_spaces_word(char number)
{
  char	*pointer;

  if ((pointer = malloc(sizeof(char) *
			(((((number + 1) / 2) + 3) / 3) + 1))) == NULL)
    return (NULL);
  if (number == 0)
    *pointer = ' ';
  if ((number == 1) || (number == 8))
    *pointer = '>';
  if ((number == 2) || (number == 7))
    *pointer = '<';
  if ((number == 3) || (number == 6))
    *pointer = '|';
  if ((number == 4) || (number == 5))
    *pointer = '&';
  if (number == 8)
    *(pointer + 1) = '>';
  if (number == 7)
    *(pointer + 1) = '<';
  if (number == 6)
    *(pointer + 1) = '|';
  if (number == 5)
    *(pointer + 1) = '&';
  *(pointer + ((((number + 1) / 2) + 3) / 3)) = '\0';
  return (pointer);
}

char	*parser_add_spaces(char *text, unsigned int block)
{
  char	*p_b;
  char	*p_a;
  char	word;
  char	*search;

  word = 8;
  p_b = string_copy(text);
  while (word != 0)
    {
      search = parser_add_spaces_word(word);
      if ((p_a = string_espacewords(p_b, search, " ", block)) == NULL)
	return (NULL);
      if (string_compare(p_b, p_a, 0) == 0)
	{
	  block = 0;
	  word = word - 1;
	}
      else
	block = block + 1;
      free(p_b);
      free(search);
      p_b = string_copy(p_a);
      free(p_a);
    }
  return (p_b);
}
char	**parser_start_next2(char *pointer_before)
{
  char	**final;

  final = commands_keywords_extract_create(pointer_before);
  if (command_analyse(final) == 0)
    {
      if (commands_keywords_write(pointer_before, final) == (-1))
	{
	  command_analyse_message(1);
	  free(final);
	  free(pointer_before);
	  return (NULL);
	}
      command_delete_caracter_alone(final);
      free(pointer_before);
      return (final);
    }
  else
    {
      free(pointer_before);
      return (NULL);
    }
}

char	**parser_start_next1(char *pointer_before, char *pointer_new)
{
  if ((pointer_before = parser_add_spaces(pointer_new, 0)) == NULL)
    return (NULL);
  if (*pointer_before == '\0')
    {
      free(pointer_before);
      free(pointer_new);
      return (NULL);
    }
  free(pointer_new);
  pointer_new = parser_eliminate_keywords_with_spaces(pointer_before);
  free(pointer_before);
  return (parser_start_next2(pointer_new));
}

char	**parser_start(char *pointer_before)
{
  int	malloc_size;
  char	*pointer_new;

  if (parser_step1(pointer_before) != 0)
    {
      command_analyse_message(1);
      return (NULL);
    }
  malloc_size = parser_spaces_tabulations_count_less(pointer_before);
  if (malloc_size == (-1))
    return (NULL);
  pointer_new = parser_spaces_tabulations_create_less(pointer_before,
						      malloc_size, 0);
  if (pointer_new == NULL)
    return (NULL);
  free(pointer_before);
  return (parser_start_next1(pointer_before, pointer_new));
}
