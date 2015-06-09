/*
** disp_tab.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:18:29 2014 lancel_e
** Last update Sun May 25 23:18:29 2014 lancel_e
*/

#include <stdio.h>
#include <stdlib.h>

void	disp_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL)
    printf("tab = %s\n", tab[i]);
}
