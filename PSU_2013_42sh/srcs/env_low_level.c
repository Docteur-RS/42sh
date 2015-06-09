/*
** env_low_level.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:19:14 2014 lancel_e
** Last update Sun May 25 23:38:02 2014 lancel_e
*/

#include <unistd.h>
#include <stdlib.h>
#include "all.h"

int	d_tab_recpy_doc(char **old, char **new, int *i, int *j)
{
  while (old[*i])
    {
      if ((new[*i] = my_malloc(my_strlen(old[*i]) + 1)) == NULL)
	return (MASTER_ERROR);
      while (old[*i][*j])
	{
	  new[*i][*j] = old[*i][*j];
	  *j = *j + 1;
	}
      new[*i][*j] = '\0';
      *j = 0;
      *i = *i + 1;
    }
  return (0);
}

char	**d_tab_cpy_doc(char **v_old, char *add)
{
  char	**new;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((new = malloc(sizeof(*v_old) * (my_strtab(v_old)+ 2))) == NULL)
    return (NULL);
  if (d_tab_recpy_doc(v_old, new, &i, &j) == MASTER_ERROR)
    return (NULL);
  if ((new[i] = malloc(my_strlen(add) + 1)) == NULL)
    return (NULL);
  j = 0;
  while (add[j])
    {
      new[i][j] = add[j];
      j = j + 1;
    }
  new[i][j] = '\0';
  i = i + 1;
  new[i] = NULL;
  return (new);
}

char		**d_tab_unset_doc(char **v_old, int pos)
{
  t_unset	unset;

  d_tab_unset_doc_ini(&unset, 0);
  if (pos < 0 || pos > my_strtab(v_old))
    return (NULL);
  if ((unset.new = malloc((sizeof(char*) * (my_strtab(v_old))))) == NULL)
    return (NULL);
  while (v_old[unset.i])
    if (unset.i != pos)
      {
	unset.new[unset.k] = my_malloc(my_strlen(v_old[unset.i]) + 1);
	while (v_old[unset.i][unset.j])
	  {
	    unset.new[unset.k][unset.j] = v_old[unset.i][unset.j];
	    unset.j = unset.j + 1;
	  }
	unset.new[unset.k][unset.j] = '\0';
	unset.j = 0;
	d_tab_unset_doc_ini(&unset, 1);
      }
    else
      unset.i = unset.i + 1;
  unset.new[unset.k] = NULL;
  return (unset.new);
}
