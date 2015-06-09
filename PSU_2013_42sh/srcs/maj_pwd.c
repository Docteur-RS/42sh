/*
** maj_pwd.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:21:35 2014 lancel_e
** Last update Wed May 28 20:13:48 2014 lancel_e
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "all.h"

int	unsetenv_for_pwd(t_manage *man, char *cmd, int pos)
{
  pos = 0;
  if ((pos = my_getenv(man->all_env->my_env, cmd)) == -1)
    return (ERROR);
  man->all_env->my_env = d_tab_unset_doc(man->all_env->my_env, pos - 1);
  return (SUCCESS);
}

int	setenv_manager_pwd(t_manage *man, char *cmd, char *buff)
{
  int	ret;

  if ((man->all_env->oldpwd = my_getenv_line(man->all_env->my_env, cmd))
      != NULL)
    unsetenv_for_pwd(man, cmd, 1);
  if ((ret = my_getenv(man->all_env->my_env, cmd)) != -1)
    unsetenv_for_pwd(man, cmd, 1);
  man->all_env->my_env = d_tab_cpy_doc(man->all_env->my_env,
				       pwd_sep(cmd, buff, '='));
  return (SUCCESS);
}

char	*init_pwd(int *fd, char **av, char **envp, char *buff)
{
  int	pid;
  int	ret;
  char	*pwd;

  pwd = NULL;
  if (pipe(fd) == -1)
    return (NULL);
  if ((pid = fork()) == 0)
    {
      if (close(fd[0]) == -1)
	return (NULL);
      if (dup2(fd[1], 1) == -1)
	return (NULL);
      if (access(buff, F_OK | X_OK) != -1)
      	if ((ret = execve(buff, av, envp)) == -1)
      	  return (NULL);
    }
  else if (pid > 0)
    {
      if ((pwd = init_in_fork(fd, &pid)) == NULL)
	return (NULL);
    }
  else
    return (NULL);
  return (pwd);
}

char	*pwd_fork(char *buff, char **av, char **envp)
{
  int	fd[2];
  char	*pwd;

  if ((pwd = init_pwd(fd, av, envp, buff)) == NULL)
    return (NULL);
  return (pwd);
}

char	*call_pwd(t_manage *man, char **envp)
{
  char	*buff;
  char	*tab[2];

  buff = NULL;
  tab[0] = "pwd";
  tab[1] = NULL;
  if ((buff = pwd_fork("/bin/pwd", tab, envp)) == NULL)
    return (NULL);
  if (setenv_manager_pwd(man, "PWD", buff) == ERROR)
    return (NULL);
  return (buff);
}
