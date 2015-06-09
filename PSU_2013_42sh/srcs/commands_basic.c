/*
** commands_basic.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:21:39 2014 lancel_e
** Last update Sun Jun  1 19:21:40 2014 lancel_e
*/

#include <stdlib.h>
#include "parser_42sh.h"

char	*commands_copy_special(char *text, char *end)
{
  int	length;
  char	*pointer;
  int	length_save;

  length = 0;
  while ((*text != '\0') && (string_compare(text, end, (-1)) != 0))
    {
      text = text + 1;
      length = length + 1;
    }
  text = text - length;
  if (length >= 1)
    length = length - 1;
  if ((pointer = malloc(sizeof(char) * (length + 1))) == NULL)
    return (NULL);
  length_save = length;
  while (length != 0)
    {
      *pointer = *text;
      pointer = pointer + 1;
      text = text + 1;
      length = length - 1;
    }
  *pointer = '\0';
  return (pointer - length_save);
}

void	command_delete_caracter_alone(char **tab)
{
  int	count;

  count = 0;
  if (tab == NULL)
    string_print("tab = NULL\n");
  else
    {
      while (tab[count] != NULL)
	{
	  if ((tab[count][0] != '\0') && (tab[count][1] == 1))
	    tab[count][1] = '\0';
	  count = count + 1;
	}
    }
}

int	command_line_is_a_command(char *text)
{
  if (text == NULL)
    return (-1);
  if (string_length(text) != 2)
    return (-1);
  if (((*text >= '1') && (*text <= '7')) && (*(text + 1) == 1))
    return (0);
  else
    return (-1);
}

int	command_analyse_message(char error)
{
  if (error == 1)
    string_print("Invalid null command.\n");
  else if (error == 2)
    string_print("Ambiguous input redirect.\n");
  else if (error == 3)
    string_print("Missing name for redirect.\n");
  else if (error == 4)
    string_print("Malloc Fail.\n");
  else if (error == 5)
    string_print("Keywords & and && and || are not managed.\n");
  else
    string_print("Error : Unknow Error\n");
  return (-1);
}

char	*command_copy_special_command(char *end)
{
  char	*pointer;

  if ((pointer = malloc(sizeof(char) * 3)) == NULL)
    return (NULL);
  if (string_compare(end, ">>", 0) == 0)
    *pointer = '4';
  if (string_compare(end, "<<", 0) == 0)
    *pointer = '5';
  if (string_compare(end, "||", 0) == 0)
    *pointer = '6';
  if (string_compare(end, "&&", 0) == 0)
    *pointer = '7';
  if (string_compare(end, "&", 0) == 0)
    *pointer = '8';
  if (string_compare(end, "|", 0) == 0)
    *pointer = '1';
  if (string_compare(end, ">", 0) == 0)
    *pointer = '2';
  if (string_compare(end, "<", 0) == 0)
    *pointer = '3';
  *(pointer + 1) = 1;
  *(pointer + 2) = '\0';
  return (pointer);
}
