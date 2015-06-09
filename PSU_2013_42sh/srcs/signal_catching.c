/*
** signal_catching.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:25:24 2014 lancel_e
** Last update Sun Jun  1 19:23:50 2014 lancel_e
*/

#include <signal.h>
#include <stdio.h>
#include "all.h"

void    aff_prompt()
{
  signal_catch();
  my_putchar('\n');
}

int     signal_catch()
{
  if (signal(SIGINT, aff_prompt) == SIG_ERR)
    return (-1);
  return (0);
}
