/*
** error_manage.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:20:14 2014 lancel_e
** Last update Sun May 25 23:20:15 2014 lancel_e
*/

#include <stdio.h>
#include "all.h"

int	x_report(int i)
{
  my_putstr("\e[0;31m");
  if (i == 0)
    printf("Error[x:0]: ");
  printf("Undefined error occured... System is still up\n");
  my_putstr("\e[0;31m");
  return (-1);
}

int	err_report(int i, char *str)
{
  my_putstr("\e[0;31m");
  if (i == 0)
    err_fnf(str);
  else if (i == 1)
    err_syntax();
  else if (i == 2)
    setenv_err();
  else if (i == 3)
    unsetenv_err();
  else if (i == 4)
    cd_err(str);
  else if (i == 5)
    file_err(str);
  else if (i == 6)
    not_a_dir_err(str);
  else if (i == 7)
    cd_arg_err();
  my_putstr("\e[0m");
  return (-1);
}
