/*
** frpn.h for evalxpr in /home/casoni_f//Projets/C/eval_expr
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Mon Nov  5 19:13:09 2012 fabien casoni
** Last update Mon Nov  5 19:18:09 2012 fabien casoni
*/

#ifndef		_FRPN_H_
# define	_FRPN_H_

#include "stack.h"
#include "struct_control.h"

char	*mmalloc(t_elem *elem, t_pile *pile);
int	check_nonop(char *str, t_pile *pile, t_elem *actual, t_control *ctrl);
int	check_operator(char *str, t_pile *pile, t_elem *actual, t_control *ctrl);
void	check_operande(char *str, t_control *ctrl, t_pile *pile);
void	freestack(t_elem *actual, t_control *ctrl, t_pile *pile);

#endif	/* _FRPN_H_ */
