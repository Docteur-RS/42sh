/*
** commands_analyse.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:18:20 2014 lancel_e
** Last update Sun Jun  1 19:18:20 2014 lancel_e
*/

#include <stdlib.h>
#include "parser_42sh.h"

int	command_analyse_next0(char **tab, int *count)
{
  if (tab == NULL)
    return (-1);
  if  (command_line_is_a_command(tab[0]) == 0)
    {
      if ((tab[0][0] == '3') || (tab[0][0] == '5'))
        return (command_analyse_message(3));
      else
        return (command_analyse_message(1));
    }
  if ((tab[0][0] == '-') && (tab[0][1] == '1'))
    *count = 0;
  else
    *count = 1;
  return (0);
}

int	command_analyse_next1(char **tab, int *count, char *left, char *right)
{
  if (command_line_is_a_command(tab[*count]) == 0)
    {
      if (((tab[*count][0] == '6') || (tab[*count][0] == '7'))
	  || (tab[*count][0] == '0'))
	return (command_analyse_message(5));
      if ((tab[*count][0] == '5') || (tab[*count][0] == '3'))
	{
	  if (*left == 0)
	    *left = *left + 1;
	  else
	    return (command_analyse_message(2));
	}
      if ((tab[*count][0] == '4') || (tab[*count][0] == '2'))
	{
	  if (*right == 0)
	    *right = *right + 1;
	  else
	    return (command_analyse_message(2));
	}
    }
  return (0);
}

int	commmand_analyse_next2(char **tab, int count)
{
  if (count >= 2)
    count = count - 2;
  if (((tab[count] != NULL) && (command_line_is_a_command(tab[count]) == 0))
      && (tab[count][0] == '\0'))
    {
      if ((tab[count][0] == '2') || (tab[count][0] == '4'))
        return (command_analyse_message(3));
      else
        return (command_analyse_message(1));
    }
  return (0);
}

int	command_analyse_next3(char **tab, int count)
{
  if (((count >= 2) && (command_line_is_a_command(tab[count]) == 0))
      && ((tab[count][0] == '3') || (tab[count][0] == '5')))
    return (command_analyse_message(2));
  if (tab[count] != NULL)
    if (tab[count + 1] != NULL)
      if (tab[count + 2] != NULL)
	if (((tab[count + 3] != NULL) &&
	     (command_line_is_a_command(tab[count]) == 0))
	    && ((tab[count][0] == '2') || (tab[count][0] == '4')))
	  return (command_analyse_message(2));
  return (0);
}

int	command_analyse(char **tab)
{
  int	count;
  char	left;
  char	right;

  count = 0;
  if (command_analyse_next0(tab, &count) == (-1))
    return (-1);
  left = 0;
  right = 0;
  while ((tab[count] != NULL) &&
	 ((tab[count][0] && tab[count][0] != '-') && (tab[count][1] &&
						      tab[count][1] != '1')))
    {
      if (command_analyse_next1(tab, &count, &left, &right) == (-1))
	return (-1);
      if (command_analyse_next3(tab, count) == (-1))
	return (-1);
      count = count + 2;
    }
  if (commmand_analyse_next2(tab, count) == (-1))
    return (-1);
  return (0);
}
