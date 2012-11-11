/*
** struct.h for evalxrp in /home/casoni_f//Projets/git/bistro/eval_expr
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Thu Nov  8 11:34:19 2012 fabien casoni
** Last update Thu Nov  8 11:38:09 2012 fabien casoni
*/

#ifndef		_STRUCT_H_
# define	_STRUCT_H_

typedef struct	s_elem
{
  char	token;
  struct s_elem	*next;
}		t_elem;

typedef struct	s_pile
{
  t_elem	*first;
}		t_pile;

typedef struct	s_control
{
  int	i;
  int	k;
  char	*tmp;
}		t_control;

#endif	/* _STRUCT_H_ */
