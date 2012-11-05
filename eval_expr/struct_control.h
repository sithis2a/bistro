/*
** struct_control.h for evalxpr in /home/casoni_f//Projets/C/eval_expr
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Mon Nov  5 15:22:08 2012 fabien casoni
** Last update Mon Nov  5 16:13:42 2012 fabien casoni
*/

#ifndef		_STRUCT_CONTROL_H_
# define	_STRUCT_CONTROL_H_

typedef struct	s_control
{
  int	i;
  int	k;
  char	*tmp;
}		t_control;

void	initctrl(t_control *control);

#endif	/* _STRUCT_CONTROL_H_ */
