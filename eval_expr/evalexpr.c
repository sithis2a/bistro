/*
** evalexpr.c for evalxpr in /home/casoni_f//Projets/C/eval_expr
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Fri Oct 26 10:29:27 2012 fabien casoni
** Last update Mon Nov  5 19:17:06 2012 fabien casoni
*/

#include <stdlib.h>
#include "frpn.h"
#include "stack.h"
#include "struct_control.h"

int	check_neg(char *str)
{
  int	i;
  int	is_neg;

  i = 0;
  is_neg = 1;
  while (str[i] == '-' || str[i] == '+' || str[i] == '(')
    {
      if (str[i] == '-')
	is_neg *= -1;
      i += 1;
    }
  return (is_neg);
}

void    str_to_rpn(char *str, t_control *control)
{
  t_elem	*actual;
  t_pile	*pile;
  int		ret;

  if (mmalloc(actual, pile) == NULL)
    return;
  actual->next = NULL;
  pile->first = actual;
  while (str[control->i] != '\0')
    {
      if (check_nonop(str, pile, actual,control) == 2)
        ret += 1;
      else if (check_operator(str, pile, actual, control) == 2)
        ret += 1;
      else
        check_operande(str, control, pile);
      control->i += 1;
    }
  freestack(actual, control, pile);
}

int	eval_expr(char *str)
{
  int		result;
  t_control	*ctrlstr;

  if (str != NULL)
    {
      ctrlstr = malloc(sizeof(*ctrlstr));
      if (ctrlstr == NULL)
	return (-99999999);
      initctrl(ctrlstr);
      str_to_rpn(str, ctrlstr);
      printf("%s\n", ctrlstr->tmp);
      //result = calc_rpn(control->tmp);
      //return (result);
    }
}

int	main(int ac, char **av)
{
  if (ac > 1)
    {
      eval_expr(av[1]);
      //my_putnbr(eval_expr(av[1]));
    }
  return (0);
}
