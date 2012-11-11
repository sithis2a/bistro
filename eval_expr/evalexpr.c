/*
** evalexpr.c for evalxpr in /home/casoni_f//Projets/C/eval_expr
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Fri Oct 26 10:29:27 2012 fabien casoni
** Last update Sun Nov 11 20:50:58 2012 fabien casoni
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

void    str_to_rpn(char *str, t_control *control)
{
  t_elem	*actual;
  t_pile	*pile;
  int		ret;

  if (mmalloc(actual, pile) == NULL)
    return;
  ret = 0;
  actual->next = NULL;
  pile->first = actual;
  while (str[control->i] != '\0')
    {
      if (check_nonop(str, pile, actual, control) == 2)
        ret += 1;
      else if (check_operator(str, pile, actual, control) == 2)
        ret += 1;
      else
        check_operande(str, control);
      control->i += 1;
    }
  freestack(actual, control, pile);
}

void	calcrpn(t_control *control)
{
  t_elem	*actual;
  t_pile	*pile;

  actual->next = NULL;
  pile->first = actual;
  control->i = 0;
  while (control->tmp[control->i] != '\0')
    {
      checking(control, actual, pile);
      control->i += 1;
    }
  my_putstr(actual->str);
}

void	eval_expr(char *str)
{
  t_control	*ctrlstr;

  if (str != NULL)
    {
      if ((ctrlstr = malloc(sizeof(*ctrlstr))) == NULL)
	return;
      initctrl(ctrlstr);
      str_to_rpn(str, ctrlstr);
      my_putstr(ctrlstr->tmp);
    }
}

int	main(int ac, char **av)
{
  if (ac > 1)
    eval_expr(av[1]);
  return (0);
}
