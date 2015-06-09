/*
** string_espacewordslength.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:19:36 2014 lancel_e
** Last update Sun Jun  1 19:19:37 2014 lancel_e
*/

#include <stdlib.h>
#include "parser_42sh.h"

int	string_espacewords_length_next0(char *text, int *result,
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
      *result = *result + 1;
      text = text + 1;
      temp = temp + 1;
    }
  return (temp);
}

int	string_espacewords_length_next1(int *result, char *insert, int *temp)
{
  while (*insert != '\0')
    {
      *result = *result + 1;
      insert = insert + 1;
      *temp = *temp + 1;
    }
  return (*result);
}

int	string_espacewords_length_next2(int *result, char *search, int *temp)
{
  while (*search != '\0')
    {
      *result = *result + 1;
      search = search + 1;
      *temp = *temp + 1;
    }
  return (*result);
}

int	string_espacewords_length_next3(char *text, int *result, int *temp)
{
  while (*text != '\0')
    {
      *result = *result + 1;
      text = text + 1;
      *temp = *temp + 1;
    }
  return (*result);
}

int	string_espacewords_length(char *text, char *search,
				   char *insert, unsigned int block)
{
  int	result;
  int	temp;

  result = 0;
  temp = string_espacewords_length_next0(text, &result, search, block);
  text = text + temp;
  if (*text == '\0')
    return ((int)string_length(text - temp));
  if ((temp >= (int)string_length(insert))
      && (string_compare(text - string_length(insert), insert, (-1)) != 0))
    string_espacewords_length_next1(&result, insert, &temp);
  string_espacewords_length_next2(&result, search, &temp);
  text = text + string_length(search);
  if (*text != '\0')
    {
      if (string_compare(text, insert, (-1)) == 0)
	text = text + string_length(insert);
      string_espacewords_length_next1(&result, insert, &temp);
    }
  string_espacewords_length_next3(text, &result, &temp);
  return (result);
}
