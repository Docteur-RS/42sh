/*
** string_espacewords.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:22:23 2014 lancel_e
** Last update Sun Jun  1 19:51:38 2014 lancel_e
*/

#include <stdlib.h>
#include "parser_42sh.h"

int	string_espacewords_next0(char *text, char *pointer,
				 char *search, unsigned int block)
{
  int	temp;
  char	quote;

  quote = '\0';
  temp = 0;
  while (*text != '\0')
    {
      if ((quote == '\0') && ((*text == 34) || (*text == 39)))
	quote = *text;
      else if ((quote != '\0') && ((*text == 34) || (*text == 39)))
	quote = '\0';
      else if (string_compare(text, search, (-1)) == 0)
	{
	  if (block == 0)
	    break ;
	  else
	    block = block - 1;
	}
      *pointer = *text;
      text = text + 1;
      pointer = pointer + 1;
      temp = temp + 1;
    }
  return (temp);
}

char	*string_espacewords_next1(char *pointer, char *insert, int *temp)
{
  while (*insert != '\0')
    {
      *pointer = *insert;
      pointer = pointer + 1;
      insert = insert + 1;
      *temp = *temp + 1;
    }
  return (pointer);
}

char	*string_espacewords_next2(char *pointer, char *search, int *temp)
{
  while (*search != '\0')
    {
      *pointer = *search;
      pointer = pointer + 1;
      search = search + 1;
      *temp = *temp + 1;
    }
  return (pointer);
}

char	*string_espacewords_next3(char *text, char *pointer, int *temp)
{
  while (*text != '\0')
    {
      *pointer = *text;
      pointer = pointer + 1;
      text = text + 1;
      *temp = *temp + 1;
    }
  *pointer = '\0';
  return (pointer);
}

char	*string_espacewords(char *text, char *search,
			    char *insert, unsigned int block)
{
  char	*pointer;
  int	temp;
  int	length;

  length = string_espacewords_length(text, search, insert, block);
  if ((pointer = malloc(sizeof(char) * (length + 1))) == NULL)
    return (NULL);
  temp = string_espacewords_next0(text, pointer, search, block);
  pointer = pointer + temp;
  text = text + temp;
  if (*text == '\0')
    return (string_copy(text - temp));
  if ((temp >= (int)string_length(insert))
      && (string_compare(text - string_length(insert), insert, (-1)) != 0))
    pointer = string_espacewords_next1(pointer, insert, &temp);
  pointer = string_espacewords_next2(pointer, search, &temp);
  text = text + string_length(search);
  if (*text != '\0')
    {
      if (string_compare(text, insert, (-1)) == 0)
	text = text + string_length(insert);
      pointer = string_espacewords_next1(pointer, insert, &temp);
    }
  return (string_espacewords_next3(text, pointer, &temp) - temp);
}
