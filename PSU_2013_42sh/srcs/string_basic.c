/*
** string_basic.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:19:43 2014 lancel_e
** Last update Sun Jun  1 19:19:44 2014 lancel_e
*/

#include <unistd.h>
#include <stdlib.h>

unsigned int	string_length(char *text)
{
  unsigned int	length;

  length = 0;
  if (text != NULL)
    {
      while (*text != '\0')
	{
	  length = length + 1;
	  text = text + 1;
	}
    }
  return (length);
}

char	*string_copy(char *text)
{
  int	length;
  char	*pointer;

  if (text == NULL)
    return (NULL);
  length = string_length(text);
  if ((pointer = malloc(sizeof(char) * (length + 1))) == NULL)
    return (NULL);
  while (*text != '\0')
    {
      *pointer = *text;
      pointer = pointer + 1;
      text = text + 1;
    }
  *pointer = '\0';
  pointer = pointer - length;
  return (pointer);
}

int	string_compare(char *left, char *right, int flag)
{
  if ((left == NULL) || (right == NULL))
    return (-1);
  while (((*left != '\0') && (*right != '\0'))
	 && (*left == *right))
    {
      left = left + 1;
      right = right + 1;
    }
  if (flag >= 0)
    if ((*left == '\0') && (*right == '\0'))
      return (0);
    else
      return (-1);
  else
    if (*right == '\0')
      return (0);
    else
      return (-1);
  return (-1);
}

char	*string_search(char *text, char *search)
{
  if ((text == NULL) || (search == NULL))
    return (NULL);
  while ((*text != '\0') &&
	 (string_compare(text, search, (-1)) == 0))
    text = text + 1;
  if (*text == '\0')
    return (NULL);
  return (text);
}
