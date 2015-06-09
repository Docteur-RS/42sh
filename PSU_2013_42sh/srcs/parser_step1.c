/*
** parser_step1.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:22:10 2014 lancel_e
** Last update Sun Jun  1 19:22:11 2014 lancel_e
*/

#include "parser_42sh.h"

int	parser_step1(char *text)
{
  while (*text != '\0')
    {
      while (((*text != '\0') && ((*text != 34) && (*text != 39))))
	text = text + 1;
      if (*text == '\0')
	return (0);
      text = text + 1;
      while ((*text != '\0') && ((*text != 34) && (*text != 39)))
	text = text + 1;
      if (*text == '\0')
	return (-1);
      text = text + 1;
    }
  return (0);
}
