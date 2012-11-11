/*
** frpn.c for evalxpr in /home/casoni_f//Projets/C/eval_expr
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Mon Nov  5 15:41:03 2012 fabien casoni
** Last update Sun Nov 11 20:54:27 2012 fabien casoni
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

char	*mmalloc(t_elem *elem, t_pile *pile)
{
  elem = malloc(sizeof(*elem));
  pile = malloc(sizeof(*pile));
  if (elem == NULL || pile == NULL)
    return (NULL);
  return ("OK");
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
  return (1);
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
  return (1);
}

void	check_operande(char *str, t_control *ctrl)
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
