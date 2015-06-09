/*
** d_red_left_utils.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:18:55 2014 lancel_e
** Last update Sun May 25 23:18:55 2014 lancel_e
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "all.h"

void	wait_and_free(char *arg_list, int i, int n)
{
  if (waitpid(i, &n, 0) == -1)
    return ;
  free(arg_list);
}

int	turn_arg_list(t_list *list, char *buff, int n)
{
  my_putstr("? ");
  if ((n = read(0, buff, 1023)) == 0)
    return (-1);
  buff[n - 1] = '\0';
  if (strcmp(list->next->cmd, buff) == 0)
    return (1);
  buff[n - 1] = '\n';
  buff[n] = '\0';
  return (0);
}
