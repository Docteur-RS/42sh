/*
** commands_keywords_extract.c for 42sh in /home/lancel_e/Documents/PROJET/new 42sh/save_all for new workspace/mixte des 3 normes/save tout le monde + parser hugues/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 16:53:41 2014 lancel_e
** Last update Sun Jun  1 16:53:41 2014 lancel_e
*/

#include <stdlib.h>
#include "parser_42sh.h"

int	command_key_next0(char *text, int *count, char more)
{
  char	*search;
  char	word;
  int	temp;

  word = 8;
  temp = 0;
  while (word != 0)
    {
      search = parser_add_spaces_word(word);
      if (search == NULL)
	return (-1);
      if (string_compare(text, search, (-1)) == 0)
	{
	  *count = *count + more;
	  temp = string_length(search);
	  word = 1;
	}
      free(search);
      word = word - 1;
    }
  return (temp);
}

int	commands_keywords_extract_count(char *text)
{
  char	quote;
  int	count;

  count = 1;
  command_key_next0(text, &count, (-1));
  while (*text != '\0')
    {
      if ((*text == 34) || (*text == 39))
	{
	  quote = *text;
	  text = text + 1;
	  while ((*text != '\0') && (*text != quote))
	    text = text + 1;
	  if (text == '\0')
	    return (-1);
	}
      else
	text = text + command_key_next0(text, &count, 2);
      if (*text != '\0')
	text = text + 1;
    }
  return (count + 1);
}

char	*commands_keyboards_extract_create_next0(char *text, char **pointer,
						 int *count, int flag)
{
  char	*search;
  char	word;

  word = 9;
  while (--word != 0)
    {
      if ((search = parser_add_spaces_word(word)) == NULL)
	return (NULL);
      if (string_compare(text, search, (-1)) == 0)
	{
	  if (flag == 0)
	    *count = 0;
	  else
	    {
	      if ((pointer[(*count)++] =
		   command_copy_special_command(search)) == NULL)
		return (NULL);
	      pointer[(*count)++] = string_copy("");
	      text = text + string_length(search);
	    }
	  word = 1;
	}
      free(search);
    }
  return (text);
}

char	**command_keywords_extract_create_next1(char *text, char **pointer,
						int *count)
{
  char	*sv;
  char	quote;

  while (*text != '\0')
    {
      if ((*text == 34) || (*text == 39))
	{
	  quote = *text;
	  text = text + 1;
	  while ((*text != '\0') && (*text != quote))
	    text = text + 1;
	  if (text == '\0')
	    return (NULL);
	}
      else
	{
	  sv = commands_keyboards_extract_create_next0(text, pointer, count, 1);
	  if (sv == NULL)
	    return (NULL);
	  text = sv;
	}
      if (*text != '\0')
	text = text + 1;
    }
  return (pointer);
}

char	**commands_keywords_extract_create(char *text)
{
  int	*count;
  int	length;
  char	**pointer;

  if ((count = malloc(sizeof(int) * 1)) == NULL)
    return (NULL);
  *count = 1;
  if ((length = commands_keywords_extract_count(text)) == (-1))
    return (NULL);
  if ((pointer = malloc(sizeof(char *) * (length + 1))) == NULL)
    return (NULL);
  if (commands_keyboards_extract_create_next0(text, pointer, count, 0) == NULL)
    return (NULL);
  if (*count == 1)
    pointer[0] = string_copy("");
  if (command_keywords_extract_create_next1(text, pointer, count) == NULL)
    return (NULL);
  pointer[*count] = string_copy("-1");
  *count = *count + 1;
  pointer[*count] = NULL;
  return (pointer);
}
