/*
** pos_in_args.c for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/srcs
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun May 25 23:24:08 2014 lancel_e
** Last update Sun May 25 23:24:08 2014 lancel_e
*/

int		pos_in_arg(int value, int flag)
{
  static int	nb = 0;

  if (flag == 1)
    nb = value;
  return (nb);
}
