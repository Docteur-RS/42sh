/*
** globing.h for 42sh in /home/lancel_e/Documents/PROJET/new 42sh/NEW WORKSPACE/headers
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 10:56:55 2014 lancel_e
** Last update Sun Jun  1 12:19:29 2014 lancel_e
*/
#ifndef GLOBING_H_
# define GLOBING_H_

# include <glob.h>

int	check_for_wildcards(char **args);
int	has_wildcard(char *arg);
int	exec_glob(char **args, glob_t globbuf, char **env, char *path);
int	glob_handling(char **env, char **args, char *path);

#endif /* !GLOBING_H_*/
