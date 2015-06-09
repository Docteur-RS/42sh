/*
** my_put_in_list.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:22:49 2014 lancel_e
** Last update Sun Jun  1 14:51:55 2014 lalann_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "list.h"

int		my_put_in_list(t_list **list, char *cmd, int num)
{
  t_list	*elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (MASTER_ERROR);
  elem->cmd = cmd;
  elem->num = num;
  elem->next = *list;
  *list = elem;
  return (0);
}

void	my_show_list(t_list *list)
{
  while (list != NULL)
    {
      printf("%d, %s\n", list->num, list->cmd);
      list = list->next;
    }
}

void		free_list(t_list *list)
{
  t_list	*tmp;

  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp);
    }
}
