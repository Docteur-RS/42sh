/*
** string_to_delete.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Jun  1 19:19:25 2014 lancel_e
** Last update Sun Jun  1 19:19:26 2014 lancel_e
*/

#include <unistd.h>
#include <stdlib.h>

void	char_print(char character)
{
  write(1, &character, 1);
}

void	string_print(char *text)
{
  if (text != NULL)
    {
      while (*text != '\0')
	{
	  char_print(*text);
	  text = text + 1;
	}
    }
}

void	aff_struct(char **tab)
{
  int	count;

  count = 0;
  if (tab == NULL)
    string_print("tab = NULL\n");
  else
    {
      while (tab[count] != NULL)
	{
	  string_print(tab[count]);
	  char_print('\n');
	  count = count + 1;
	}
    }
}
