/*
** pre_loops.c for 42sh in /home/lancel_e/Documents/PROJET/new 42sh/save_all for new workspace/mixte des 3 normes/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 15:20:20 2014 lancel_e
** Last update Sun Jun  1 15:20:20 2014 lancel_e
*/

#include "all.h"

int	pre_loop_pv(t_manage *man, char **pv, int ret)
{
  ret = loop_pv(man, pv);
  wordtab_end(pv);
  if (ret == MASTER_ERROR)
    return (MASTER_ERROR);
  return (0);
}

int	pre_loop_without_pv(t_manage *man, int ret)
{
  ret = loop_without_pv(man);
  if (ret == MASTER_ERROR)
    return (MASTER_ERROR);
  return (0);
}
