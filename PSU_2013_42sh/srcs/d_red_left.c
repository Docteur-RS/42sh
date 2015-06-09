/*
** d_red_left.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:21:01 2014 lancel_e
** Last update Sun Jun  1 19:21:02 2014 lancel_e
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "all.h"

int	send_to_pipe(int pipefd[2], char *arg_list)
{
  int	status;
  int	pid;

  if ((pid = fork()) == -1)
    return (-1);
  else if (pid == 0)
    {
      if ((close(pipefd[0])) == -1)
	return (-1);
      write(pipefd[1], arg_list, my_strlen(arg_list));
      return (MASTER_ERROR);
    }
  if (wait(&status) == -1)
    return (-1);
  return (0);
}

int	exec_d_red_left(t_manage *man, char *cmd, int pipefd[2],
			int *p, int flag)
{
  int	pid;

  if ((pid = fork()) == -1)
    return (-1);
  else if (pid == 0)
    {
      if (flag == 0)
	{
	  if (dup2(p[1], 1) == -1)
	    return (-1);
	  if (close(p[0]) == -1)
	    return (-1);
	}
      if ((close(pipefd[1])) == -1)
	return (-1);
      if (dup2(pipefd[0], 0) == -1)
	return (-1);
      if (exe(man, cmd) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
  return (pid);
}

int	cmd_handling(t_manage *man, t_list *list, char *arg_list,
		     int *p, int flag)
{
  int	pipefd[2];
  int	son_pid;

  pos_in_arg(0, 1);
  if ((pipe(pipefd)) == -1)
    return (-1);
  if ((son_pid = exec_d_red_left(man, list->cmd,
				 pipefd, p, flag)) == MASTER_ERROR)
    return (MASTER_ERROR);
  if ((send_to_pipe(pipefd, arg_list)) == MASTER_ERROR)
    return (MASTER_ERROR);
  if (((close(pipefd[0])) == -1) || ((close(pipefd[1])) == -1))
    return (-1);
  return (son_pid);
}

void	put_buff_to_args(char buff[4096], char *args)
{
  int	i;

  i = 0;
  while (buff[i] != '\0')
    {
      args[pos_in_arg(0, 0)] = buff[i];
      pos_in_arg((pos_in_arg(0, 0) + 1), 1);
      ++i;
    }
  args[pos_in_arg(0, 0)] = '\0';
  memset(buff, '\0', 4096);
}

int	d_red_left(t_manage *man, t_list *list, int *p, int flag)
{
  char	*arg_list;
  char	buff[4096];
  int	i;
  int	n;

  if ((arg_list = malloc(200 * sizeof(char))) == NULL)
    return (-1);
  while (42)
    {
      my_putstr("? ");
      if ((n = read(0, buff, 4095)) == 0)
	return (-1);
      buff[n - 1] = '\0';
      if (strcmp(list->next->cmd, buff) == 0)
	break ;
      small_modif_to_buff(buff, n);
      if ((arg_list = realloc(arg_list, 4096 * sizeof(char))) == NULL)
	return (-1);
      put_buff_to_args(buff, arg_list);
    }
  arg_list[pos_in_arg(0, 0)] = '\0';
  if ((i = cmd_handling(man, list, arg_list, p, flag)) == MASTER_ERROR)
    return (MASTER_ERROR);
  wait_and_free(arg_list, i, n);
  return (0);
}
