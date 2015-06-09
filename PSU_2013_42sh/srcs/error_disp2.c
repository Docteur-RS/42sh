/*
** error_disp2.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:19:53 2014 lancel_e
** Last update Sun May 25 23:19:53 2014 lancel_e
*/

#include <stdio.h>
#include "all.h"

void	file_err(char *cmd)
{
  dprintf(2, "%s: Permission denied.\n", cmd);
}

void	not_a_dir_err(char *last)
{
  dprintf(2, "%s: Not a directory.\n", last);
}

void	cd_arg_err()
{
  dprintf(2, "cd: Too many arguments.\n");
}
