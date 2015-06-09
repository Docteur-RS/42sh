/*
** list.h for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/headers
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Wed May 28 19:01:28 2014 lancel_e
** Last update Sun Jun  1 17:22:53 2014 lalann_a
*/

#ifndef LIST_H_
# define LIST_H_

# define MASTER_ERROR -10
# define ERROR -1
# define SUCCESS 1
# define YES 2
# define NO 3

typedef struct	t_list
{
  char		*cmd;
  int		*fd;
  int		num;
  struct t_list	*next;
}		t_list;

void	my_putchar(char);
void	my_putstr(char *);
void	free_list(t_list *);
int	my_put_in_end_list(t_list **, char *, int);
int	my_put_in_list(t_list **, char *, int);
void	my_show_list(t_list *);

#endif /* !LIST_H_ */
