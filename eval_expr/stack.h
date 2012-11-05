/*
** stack.h for bistro in /home/casoni_f//Test/try_list/try_pile
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Tue Oct 30 16:27:12 2012 fabien casoni
** Last update Tue Oct 30 19:02:34 2012 fabien casoni
*/

#ifndef		_MAIN_H_
# define	_MAIN_H_

typedef struct	s_elem
{
  char	token;
  struct s_elem	*next;
}		t_elem;

typedef struct	s_pile
{
  t_elem	*first;
}		t_pile;

#endif	/*_MAIN_H_*/
