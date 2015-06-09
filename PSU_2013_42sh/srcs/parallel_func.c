/*
** parallel_func.c for 42sh$ in /home/jamme-_c/rendu/42sh_func/my_echo_dollar
** 
** Made by jamme-_c
** Login   <jamme-_c@epitech.net>
** 
** Started on  Wed Apr 23 22:22:36 2014 jamme-_c
** Last update Sat May 24 17:28:49 2014 lancel_e
*/

#include "dollar.h"

int	how_many_dollars(char *str)
{
  int	i;
  int	dol;

  i = 0;
  dol = 0;
  while (str[i])
    {
      if (str[i] == '$')
	dol = dol + 1;
      i = i + 1;
    }
  return (dol);
}
