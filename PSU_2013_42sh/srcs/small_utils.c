/*
** small_utils.c for 42sh in /home/lancel_e/Documents/PROJET/new 42sh/NEW WORKSPACE/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 12:25:43 2014 lancel_e
** Last update Sun Jun  1 15:31:45 2014 lancel_e
*/

#include <sys/wait.h>
#include "all.h"

int	ret_then_wait(int ret)
{
  int	status;

  if (ret == -1)
    return (-1);
  if (wait(&status) == -1)
    return (-1);
  return (0);
}

void	small_modif_to_buff(char *buff, int n)
{
  buff[n - 1] = '\n';
  buff[n] = '\0';
}

void	free_path_arg(char **path, char **d_arg)
{
  wordtab_end(path);
  wordtab_end(d_arg);
}

int	wait_for_son()
{
  int	isdead;

  if (wait(&isdead) == -1)
    return (-1);
  wait_func(isdead);
  return (0);
}
