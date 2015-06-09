/*
** one_redirec_manage.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:23:24 2014 lancel_e
** Last update Sun Jun  1 15:03:29 2014 lalann_a
*/

#include <stdio.h>
#include <unistd.h>
#include "list.h"
#include "all.h"

int	exe_redirec_unique_two(t_manage *man, t_list *list, int *p)
{
  if (list->num == 3)
    {
      if (redirec_left(man, list, p, 1) == MASTER_ERROR)
	return (MASTER_ERROR);
      return (1);
    }
  else if (list->num == 5)
    {
      if (d_red_left(man, list, p, 1) == MASTER_ERROR)
	return (MASTER_ERROR);
      return (1);
   }
  return (0);
}

int	exe_redirec_unique(t_manage *man, t_list *list)
{
  int	ret;
  int	p[2];

  pipe(p);
  ret = 0;
  if (list->num == 2)
    {
      if (red_right_for_unique(man, list, p) == MASTER_ERROR)
	return (MASTER_ERROR);
      return (1);
    }
  else if (list->num == 4)
    {
      if (d_red_right_for_unique(man, list, p) == MASTER_ERROR)
	return (MASTER_ERROR);
      return (1);
    }
  else
    if ((ret = exe_redirec_unique_two(man, list, p)) == MASTER_ERROR)
      return (MASTER_ERROR);
  if (ret == 1)
    return (1);
  return (0);
}

int	special_all_left_case(t_manage *man, t_list *list)
{
  int	fd;

  fd = 0;
  if (list->num == 3)
    {
      if (list->next->num == 2 || list->next->num == 4)
	{
	  if (list->next->next->num == -1)
	    if (redirec_left_spe(man, list) == MASTER_ERROR)
	      return (MASTER_ERROR);
	  return (1);
	}
    }
  else if (list->num == 5)
    {
      if (list->next->num == 2 || list->next->num == 4)
	{
	  if (list->next->next->num == -1)
	    if (d_red_left_spe(man, list, fd) == MASTER_ERROR)
	      return (MASTER_ERROR);
	  return (1);
	}
    }
  return (0);
}

int	only_one_redirec_manage(t_manage *man, t_list *list)
{
  int	ret;

  ret = 0;
  if ((ret = special_all_left_case(man, list)) == 1)
    return (1);
  if (ret == MASTER_ERROR)
    return (MASTER_ERROR);
  if (list->next->num == -1)
    {
      if (list->num != 1)
	{
       	  if ((ret = exe_redirec_unique(man, list)) == MASTER_ERROR)
	    return (MASTER_ERROR);
	  if (ret == 1)
	    return (1);
	}
      return (0);
    }
  return (0);
}
