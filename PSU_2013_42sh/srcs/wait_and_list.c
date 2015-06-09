/*
** wait_and_list.c for 42sh in /home/lancel_e/Documents/PROJET/new 42sh/save_all for new workspace/mixte des 3 normes
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 15:12:11 2014 lancel_e
** Last update Sun Jun  1 15:15:02 2014 lancel_e
*/

#include <sys/wait.h>
#include "all.h"
#include "list.h"

void	wait_and_list(t_list **list, int status)
{
  wait(&status);
  *list = (*list)->next;
}
