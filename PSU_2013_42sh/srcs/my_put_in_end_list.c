/*
** my_put_in_end_list.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:22:40 2014 lancel_e
** Last update Sun Jun  1 14:50:47 2014 lalann_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "list.h"

int		my_put_in_end_list(t_list **list, char *cmd, int num)
{
  t_list	*elem;
  t_list	*tmp;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->cmd = cmd;
  elem->num = num;
  elem->next = NULL;
  if (*list == NULL)
    return (-1);
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
      return (1);
    }
  return (0);
}
