/*
** additional_func.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:16:36 2014 lancel_e
** Last update Sun May 25 23:16:37 2014 lancel_e
*/

#include <stdlib.h>
#include "all.h"
#include "get_next_line.h"

int	init_new_and_check_pos(char **new, char **v_old, int pos)
{
  if (pos < 0 || pos > my_strtab(v_old))
    return (-1);
  if ((new = malloc((sizeof(char*) * (my_strtab(v_old))))) == NULL)
    return (-1);
  return (0);
}

int	init_var_and_check_fd(t_var *to, const int fd)
{
  if (fd == -1)
    return (-1);
  to->resul = 0;
  to->i = 0;
  if ((to->the_line = my_malloc(2 * sizeof(char *))) == NULL)
    return (-1);
  to->the_line[1] = '\0';
  return (0);
}
