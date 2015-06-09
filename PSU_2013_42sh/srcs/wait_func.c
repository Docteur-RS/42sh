/*
** wait_func.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:26:47 2014 lancel_e
** Last update Sun Jun  1 19:24:21 2014 lancel_e
*/

#include <stdio.h>
#include <sys/wait.h>
#include "all.h"

void	sub_wait(int status)
{
  int	signal;

  signal = 0;
  if ((signal = WTERMSIG(status)) == SIGSEGV || signal == SIGALRM)
    dprintf(2, "Segmentation fault\n");
  else if (signal == SIGPIPE)
    dprintf(2, "Broken pipe\n");
  else if (signal == SIGABRT)
    dprintf(2, "Aborted\n");
  else if (signal == SIGTERM)
    dprintf(2, "Terminated\n");
  else if (signal == SIGFPE)
    dprintf(2, "Floating point exception\n");
}

int	wait_func(int status)
{
  if (WIFSIGNALED(status) == 1)
    sub_wait(status);
  return (0);
}
