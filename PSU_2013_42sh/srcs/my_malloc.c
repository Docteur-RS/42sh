/*
** my_malloc.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:22:28 2014 lancel_e
** Last update Sun May 25 23:22:29 2014 lancel_e
*/

#include <stdlib.h>
#include "all.h"

void	*my_malloc(int size)
{
  void	*ptr;

  if (size < 0)
    size = 0;
  ptr = malloc(size * sizeof(char *));
  if (ptr == NULL)
    {
      my_putstr("Error : Cannot malloc.\n");
      return (NULL);
    }
  return (ptr);
}

void	my_free(void *var)
{
  if (var)
    free(var);
}
