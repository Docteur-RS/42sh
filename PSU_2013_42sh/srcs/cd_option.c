/*
** cd_option.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:17:18 2014 lancel_e
** Last update Sun May 25 23:37:31 2014 lancel_e
*/

#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "all.h"

char	*dispatch_cd_cmd(t_manage *man, char *buff)
{
  if (buff[0] == '~')
    return (go_from_home(man, buff));
  return (buff);
}

int	cd_options(t_manage *man, char **buffer)
{
  *buffer = *buffer + 2;
  if (*buffer[0] == ' ' || *buffer[0] == '\t')
    *buffer = *buffer + 1;
  if ((*buffer = dispatch_cd_cmd(man, *buffer)) == NULL)
    return (ERROR);
  return (0);
}

int	cd_error(char *buffer, struct stat *s)
{
  if (S_ISDIR(s->st_mode))
    {
      if (chdir(buffer) == ERROR)
	return (x_report(0));
    }
  else
    return (err_report(6, buffer));
  return (0);
}

char	*init_in_fork(int *fd, int *pid)
{
  char	buffer[BUFF_SIZE];
  int	ret;
  char	*pwd;

  if (wait(pid) == -1)
    return (NULL);
  if (close(fd[1]) == -1)
    return (NULL);
  if ((ret = read(fd[0], buffer, BUFF_SIZE - 1)) <= 0)
    return (NULL);
  buffer[ret - 1] = '\0';
  if ((pwd = strdup(buffer)) == NULL)
    return (NULL);
  return (pwd);
}

char	*pwd_sep(char *s1, char *s2, char c)
{
  int	i;
  int	j;
  char	*final;

  final = NULL;
  i = -1;
  j = 0;
  if ((final = malloc(my_strlen(s1) + my_strlen(s2) + 2)) == NULL)
    return (NULL);
  final[my_strlen(s1) + my_strlen(s2) + 1] = '\0';
  while (s1[++i])
    {
      final[j] = s1[i];
      ++j;
    }
  i = -1;
  final[j] = c;
  ++j;
  while (s2[++i])
    {
      final[j] = s2[i];
      ++j;
    }
  disp_pwd(final);
  return (final);
}
