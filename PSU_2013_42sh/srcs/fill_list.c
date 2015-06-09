/*
** fill_list.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:20:57 2014 lancel_e
** Last update Sun Jun  1 19:28:37 2014 lancel_e
*/

#include <stdlib.h>
#include "list.h"
#include "all.h"

char	**bye_space_in_double(char **av)
{
  int	i;

  i = -1;
  while (av[++i] != NULL)
    if ((av[i] = bye_space(av[i])) == NULL)
      return (NULL);
  return (av);
}

int	linked_list(t_manage *man, t_list *list, char **av)
{
  int	i;

  i = 2;
  if ((av = bye_space_in_double(av)) == NULL)
    return (MASTER_ERROR);
  if (my_put_in_list(&list, av[0], (my_getnbr(av[1]))) == MASTER_ERROR)
    return (MASTER_ERROR);
  while (av[i] != NULL)
    {
      if (av[i + 1] == NULL)
	break ;
      if (my_put_in_end_list(&list, av[i], (my_getnbr(av[i + 1]))) ==
	  MASTER_ERROR)
	return (MASTER_ERROR);
      i += 2;
    }
  if (av[i] != NULL)
    if (my_put_in_end_list(&list, av[i], -1) ==
	MASTER_ERROR)
      return (MASTER_ERROR);
  if (get_it_on(man, list) == MASTER_ERROR)
    return (MASTER_ERROR);
  free_list(list);
  return (0);
}

int		create_list(t_manage *man, char **av)
{
  t_list	*list;

  list = NULL;
  if (linked_list(man, list, av) == MASTER_ERROR)
    return (MASTER_ERROR);
  return (0);
}
