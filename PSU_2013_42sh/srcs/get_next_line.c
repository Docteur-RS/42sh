/*
** get_next_line.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:21:07 2014 lancel_e
** Last update Sun Jun  1 16:43:30 2014 lancel_e
*/

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "get_next_line.h"
#include "all.h"

char	*get_next_line(const int fd)
{
  t_var	to;

  if (init_var_and_check_fd(&to, fd) == -1)
    return (NULL);
  if ((to.resul = read(fd, &to.my_buff, LEN)) == 0)
    return (NULL);
  if (to.resul < 0 && errno != EINTR)
    return (NULL);
  if (to.resul == 1)
    {
      while (((to.resul == 1 && to.my_buff !='\n')) && (to.my_buff != 0))
        {
	  to.the_line[to.i] = to.my_buff;
	  to.i = to.i + 1;
	  if ((to.the_line = my_append_for_malloc_doc(to.the_line, to.my_buff))
	      == NULL)
	    return (NULL);
	  to.resul = read(fd, &to.my_buff, LEN);
        }
    }
  to.the_line[to.i] = '\0';
  return (to.the_line);
}

char	*my_append_for_malloc_doc(char *tab, char c)
{
  int	i;
  char	*temp;

  i = 0;
  if ((temp = malloc((my_strlen(tab) + 2) * sizeof(char))) == NULL)
    return (NULL);
  while (tab[i])
    {
      temp[i] = tab[i];
      i = i + 1;
    }
  temp[i] = c;
  i = i + 1;
  temp[i] = '\0';
  free(tab);
  tab = temp;
  return (temp);
}
