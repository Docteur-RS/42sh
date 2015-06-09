/*
** get_next_line.h for 42sh in /home/lancel_e/rendu/PSU_2013_42sh/headers
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Wed May 28 18:56:46 2014 lancel_e
** Last update Wed May 28 19:02:35 2014 lancel_e
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define LEN  1

typedef struct	s_var
{
  int		i;
  char		*the_line;
  char		my_buff;
  int		resul;
}		t_var;

char	*get_next_line(const int fd);
char	*my_append_for_malloc_doc(char *tab, char c);
int	my_strlen(char *tab);

#endif /* !get_next_line.h  */
