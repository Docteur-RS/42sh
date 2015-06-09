/*
** my_strlen.c for my_strlen.c in /home/lancel_e/rendu/Piscine-C-lib
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Tue Oct  8 14:01:49 2013 lancel_e
** Last update Sun May 25 17:32:12 2014 lancel_e
*/

int	my_strlen(char *tab)
{
  int	i;

  i = -1;
  while (tab[++i] != '\0')
    ;
  return (i);
}
