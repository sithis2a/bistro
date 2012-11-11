/*
** crpn.c for eval_expr in /home/casoni_f//Projets/git/bistro/eval_expr
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Sun Nov 11 19:24:15 2012 fabien casoni
** Last update Sun Nov 11 21:09:23 2012 fabien casoni
*/

#include "my.h"
#include "struct.h"

void	checking(t_control *ctrl, t_elem *actual, t_pile *pile)
{
  if (ctrl->tmp[ctrl->i] == ' ')
    {
      if (ctrl->tmp[ctrl->i + 1] >= '0' && ctrl->tmp[ctrl->i + 1] <= '9')
	return;
      else
	stack(pile, ' ');
    }
  else if (ctrl->tmp[ctrl->i] >= '0' && ctrl->tmp[ctrl->i] <= '9')
    {
      if (ctrl->tmp[ctrl->i + 1] >= '0' && ctrl->tmp[ctrl->i + 1] <= '9')
	{
	  actual->str[ctrl->k] = ctrl->tmp[ctrl->i];
	  actual->str[ctrl->k + 1] = ctrl->tmp[ctrl->i + 1];
	  stackstr(pile, '\0', ctrl->k + 2);
	  ctrl->i += 1;
	}
      else
	{
	  stackstr(pile, ctrl->tmp[ctrl->i], ctrl->k);
	  stackstr(pile, '\0', ctrl->k + 1);
	}
    }
  else
    do_op(ctrl, actual, pile);
}

void	do_op(t_control *ctrl, t_elem *actual, t_pile *pile)
{
  char	*val1;
  char	*val2;

  if (ctrl->tmp[ctrl->i] == '+')
    {
      val2 = unstackstr(pile);
      val1 = unstackstr(pile);
      stack(pile, add(val1, val2));
    }
  else if (ctrl->tmp[ctrl->i] == '-')
    {
      val2 = unstackstr(pile);
      val1 = unstackstr(pile);
      stack(pile, less(val1, val2));
    }
  else if (ctrl->tmp[ctrl->i] == '/')
    {
      val2 = unstackstr(pile);
      val1 = unstackstr(pile);
      stack(pile, division(val1, val2));
    }
  else if (ctrl->tmp[ctrl->i] == '%')
    {
      val2 = unstackstr(pile);
      val1 = unstackstr(pile);
      stack(pile, modulo(val1, val2));
    }
  else
    {
      val2 = unstackstr(pile);
      val1 = unstackstr(pile);
      stack(pile, mult(val1, val2));
    }
}
