/*
** error_disp1.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:19:46 2014 lancel_e
** Last update Sun May 25 23:19:47 2014 lancel_e
*/

#include <stdio.h>
#include "all.h"

void	setenv_err()
{
  dprintf(2, "setenv: Too many arguments.\n");
}

void	err_fnf(char *str)
{
  dprintf(2, "%s: Command not found.\n", str);
}

void	err_syntax()
{
  dprintf(2, "exit: Expression Syntax.\n");
}

void	unsetenv_err()
{
  dprintf(2, "unsetenv: Too few arguments\n");
}

void	cd_err(char *last)
{
  dprintf(2, "%s: No such file or directory\n", last);
}
