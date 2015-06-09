/*
** d_red_left.c for 42sh in /home/lalann_a/lalanne
** 
** Made by lalann_a
** Login   <lalann_a@epitech.net>
** 
** Started on  Tue Apr 3 15:23:07 2014 lalann_a
** Last update Sun Jun  1 13:56:33 2014 lancel_e
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "list.h"
#include "all.h"

int	send_to_pipe_spe(int pipefd[2], char *arg_list)
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
  wait(&status);
  return (0);
}

int	exec_d_red_left_spe(t_manage *man, char *cmd, int pipefd[2], int fd)
{
  int	pid;

  if ((pid = fork()) == -1)
    return (-1);
  else if (pid == 0)
    {
      dup2(fd, 1);
      if ((close(pipefd[1])) == -1)
	return (-1);
      if (dup2(pipefd[0], 0) == -1)
	return (-1);
      if (exe(man, cmd) == MASTER_ERROR)
	return (MASTER_ERROR);
    }
 return (pid);
}

int	cmd_handling_spe(t_manage *man, t_list *list, char *arg_list, int fd)
{
  int	pipefd[2];
  pid_t	son_pid;

  if ((pipe(pipefd)) == -1)
    return (-1);
  if ((son_pid = exec_d_red_left_spe(man, list->cmd, pipefd, fd)) ==
      MASTER_ERROR)
    return (MASTER_ERROR);
  if ((send_to_pipe(pipefd, arg_list)) == MASTER_ERROR)
    return (MASTER_ERROR);
  if (((close(pipefd[0])) == -1) || ((close(pipefd[1])) == -1))
    return (-1);
  return (son_pid);
}

int	get_fd_open_spe(t_list *list)
{
  int	fd;

  fd = 0;
  list->next->next->cmd = my_epur(list->next->next->cmd);
  if (list->next->num == 4)
    if ((fd = open(list->next->next->cmd, O_CREAT | O_APPEND | O_WRONLY, 0644))
	< 0)
      return (-1);
  if (list->next->num == 2)
    if ((fd = open(list->next->next->cmd, O_CREAT | O_TRUNC | O_WRONLY, 0644))
	< 0)
      return (-1);
  return (fd);
}

int	d_red_left_spe(t_manage *man, t_list *list, int fd)
{
  char	*arg_list;
  char	buff[4096];
  char	*buffer;
  int	i;
  int	n;

  if ((arg_list = malloc(200 * sizeof(char))) == NULL)
    return (MASTER_ERROR);
  while (42)
    {
      my_putstr("? ");
      if ((n = read(0, buff, 4095)) == 0)
      	return (-1);
      buff[n - 1] = '\0';
      if (strcmp(list->next->cmd, buff) == 0)
	break ;
      if ((buffer = (d_red_left_util_spe(buff, arg_list, &n))) == NULL)
      	return (-1);
    }
  if ((i = d_red_left_error_spe(&fd, list, arg_list, man)) == MASTER_ERROR)
    return (MASTER_ERROR);
  if (i == -1)
    return (-1);
  free(arg_list);
  return (0);
}
