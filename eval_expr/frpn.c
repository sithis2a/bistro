/*
** frpn.c for evalxpr in /home/casoni_f//Projets/C/eval_expr
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Mon Nov  5 15:41:03 2012 fabien casoni
** Last update Mon Nov  5 16:46:18 2012 fabien casoni
*/

#include <stdlib.h>
#include "stack.h"
#include "struct_control.h"

char	*mmalloc(t_elem *elem, t_pile *pile)
{
  elem = malloc(sizeof(*elem));
  pile = malloc(sizeof(*pile));
  if (elem == NULL || pile == NULL)
    return (NULL);
}

int	check_nonop(char *str, t_pile *pile, t_elem *actual, t_control *ctrl)
{
  if (str[ctrl->i] == '(')
    {
      stack(pile, str[ctrl->i]);
      return (2);
    }
  else if (str[ctrl->i] == ')')
    {
      while (actual != NULL && actual->token != '(')
	{
	  ctrl->tmp[ctrl->k] = unstack(pile);
	  actual = actual->next;
	  ctrl->tmp[(ctrl->k) + 1] = ' ';
	  ctrl->k += 2;
	}
      return (2);
    }
  else if (str[ctrl->i] == ' ')
    {
      ctrl->tmp[ctrl->k] = ' ';
      ctrl->k += 1;
      return (2);
    }
}

int	check_operator(char *str, t_pile *pile, t_elem *actual, t_control *ctrl)
{
  if (str[ctrl->i] == '+' || str[ctrl->i] == '-')
    {
      if (actual->token == '%' || actual->token == '/' || actual->token == '*')
	{
	  ctrl->tmp[ctrl->k] = unstack(pile);
	  actual = actual->next;
	  ctrl->tmp[(ctrl->k) + 1] = ' ';
	  ctrl->k += 2;
	}
      stack(pile, str[ctrl->i]);
      return (2);
    }
  else if (str[ctrl->i] == '/' || str[ctrl->i] == '%' || str[ctrl->i] == '*')
    {
      if (actual->token == '%' || actual->token == '/' || actual->token == '*')
	{
	  ctrl->tmp[ctrl->k] = unstack(pile);
	  actual = actual->next;
	  ctrl->tmp[(ctrl->k) + 1] = ' ';
	  ctrl->k += 2;
	}
      stack(pile, str[ctrl->i]);
      return (2);
    }
}

void	check_operande(char *str, t_control *ctrl, t_pile *pile)
{
  while (str[ctrl->i] != ' ')
    {
      ctrl->tmp[ctrl->k] = str[ctrl->i];
      ctrl->k += 1;
      ctrl->i += 1;
    }
  ctrl->tmp[ctrl->k] = str[ctrl->i];
  ctrl->k += 1;
}

void	freestack(t_elem *actual, t_control *ctrl, t_pile *pile)
{
  while (actual != NULL)
    {
      ctrl->tmp[ctrl->k] = unstack(pile);
      actual = actual->next;
      ctrl->tmp[(ctrl->k) + 1] = ' ';
      ctrl->k += 2;
    }
}

void	str_to_rpn(char *str, t_control *control)
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
