/*
** epur_start_end.c for  in /home/lancel_e/Documents/PROJET/new 42sh
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Wed May 28 20:08:14 2014 lancel_e
** Last update Sun Jun  1 18:44:19 2014 lancel_e
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "all.h"

void	bye_tab(char *str)
{
  while (*str != '\0' && (*str == ' ' || *str == '\t'))
    {
      *str = ' ';
      str = str + 1;
    }
  while (*str != '\0')
    str = str + 1;
  str = str - 1;
  while (*str && (*str == ' ' || *str == '\t'))
    {
      *str = ' ';
      str = str - 1;
    }
}

void	bye_space_init(char *str, int *i, int *count, int *j)
{
  bye_tab(str);
  while (str[++*i] != '\0' && str[*i] == ' ')
    ++*count;
  while (str[++*i] != '\0')
    ;
  while (str[--*i] && str[*i] == ' ' && *i >= 0)
    ++*count;
  *j = *i + 2;
}

char	*bye_space(char *str)
{
  int   i;
  char  *final;
  int   count;
  int   j;

  count = 0;
  i = -1;
  bye_space_init(str, &i, &count, &j);
  if ((final = malloc(strlen(str) - count + 1)) == NULL)
    return (NULL);
  i = -1;
  while (str[++i] != '\0' && str[i] == ' ')
    ;
  --i;
  count = -1;
  while (str[++i] && i < j)
    final[++count] = str[i];
  if (final[count] != '\0' && final[count] != ' ')
    final[++count] = '\0';
  final[count] = '\0';
  free(str);
  return (final);
}
