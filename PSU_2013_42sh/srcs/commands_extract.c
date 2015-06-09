/*
** commands_extract.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:21:18 2014 lancel_e
** Last update Sun Jun  1 19:38:10 2014 lancel_e
*/

#include <stdlib.h>
#include "parser_42sh.h"

int	commands_keywords_transform(char *text)
{
  int	temp;

  temp = *text - '0';
  if (temp == 1)
    return (3);
  if (temp == 2)
    return (1);
  if (temp == 3)
    return (2);
  if (temp == 4)
    return (8);
  if (temp == 5)
    return (7);
  if (temp == 6)
    return (6);
  if (temp == 7)
    return (5);
  if (temp == 8)
    return (4);
  return (0);
}

char	*commands_keywords_write_next0(char **tab, char *text,
				       int count, char more)
{
  char	*pt_0;
  char	*pt_1;

  pt_0 = parser_add_spaces_word(commands_keywords_transform(tab[count + 1]));
  if (*text == ' ')
    text = text + 1;
  if (*pt_0 == ' ')
    pt_1 = string_copy_define(text, string_search_define(text, "") - more);
  else
    pt_1 = string_copy_define(text, string_search_define(text, pt_0) - more);
  free(pt_0);
  return (pt_1);
}

char	*commands_keywords_write_next1(char **tab, int count, char *text)
{
  if (tab[count][0] == '\0')
    {
      free(tab[count]);
      if ((tab[count + 1][0] == '-') && (tab[count + 1][1] == '1'))
	{
	  tab[count] = commands_keywords_write_next0(tab, text, count, 0);
	  return (text);
	}
      else
	{
	  tab[count] = commands_keywords_write_next0(tab, text, count, 1);
	  if (*(text + string_length(tab[count])) == '\0')
	    return (NULL);
	  if (*(text + string_length(tab[count]) +
		string_length(tab[count + 1])) == '\0')
	    return (NULL);
	  if (*(text + string_length(tab[count]) +
		string_length(tab[count + 1])) == '\0')
	    return (NULL);
	  return (text + string_length(tab[count])
		  + string_length(tab[count + 1]) + 1);
	}
    }
  return (text);
}

int	commands_keywords_write_next2(char *text, char **tab, int count)
{
  if (*(text + 1) == '\0')
    return (-1);
  if ((*(text + string_length(tab[count])
	 + string_length(tab[count + 1]) - 2) == '\0')
      && (!((tab[count + 1] != NULL)
	    && (string_compare(tab[count + 1], "-1", 0) == 0))))
    return (-1);
  if ((*(text + string_length(tab[count])) != '\0')
      && (*(text + string_length(tab[count])
	    + string_length(tab[count + 1])) == '\0'))
    return (-1);
  return (0);
}

int	commands_keywords_write(char *text, char **tab)
{
  int	count;

  count = 0;
  free(tab[count]);
  if (tab[count + 2] == NULL)
    tab[count] = commands_keywords_write_next0(tab, text, count, 0);
  else
    tab[count] = commands_keywords_write_next0(tab, text, count, 1);
  if (commands_keywords_write_next2(text, tab, count) == (-1))
    return (-1);
  text = text + string_length(tab[count]) + string_length(tab[count + 1]) + 1;
  count = count + 1;
  while (tab[count] != NULL)
    {
      while ((tab[count] != NULL) && (tab[count][0] != '\0'))
	count = count + 1;
      if (tab[count] != NULL)
	{
	  text = commands_keywords_write_next1(tab, count, text);
	  if (text == NULL)
	    return (-1);
	  count = count + 1;
	}
    }
  return (0);
}
