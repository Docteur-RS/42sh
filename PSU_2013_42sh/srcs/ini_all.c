/*
** ini_all.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:21:21 2014 lancel_e
** Last update Sun May 25 23:34:40 2014 lancel_e
*/

#include <unistd.h>
#include "all.h"

int	ini_and_epur_red_right(t_list *list)
{
  if (list->next->next->cmd == NULL || list->next->cmd == NULL)
    return (-1);
  list->next->cmd = my_epur(list->next->cmd);
  return (0);
}

int	ini_and_epur_red_right_for_unique(t_list *list)
{
  if (list->next->cmd == NULL || list->cmd == NULL)
    return (-1);
  list->next->cmd = my_epur(list->next->cmd);
  return (0);
}

void	ini_all_red_right(int *ret, int *newfd)
{
  *ret = 0;
  *newfd = 0;
}

int	wait_and_close(int status, int newfd)
{
  if (wait(&status) == -1)
    return (-1);
  if (close(newfd) == -1)
    return (-1);
  return (0);
}
