/*
** struct_control.c for evalxpr in /home/casoni_f//Projets/C/eval_expr
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Mon Nov  5 15:35:51 2012 fabien casoni
** Last update Mon Nov  5 16:45:48 2012 fabien casoni
*/

#include <stdlib.h>
#include "struct_control.h"

void	initctrl(t_control *control)
{
  control->i = 0;
  control->k = 0;
  control->tmp = malloc(sizeof(*control->tmp));
  if (control->tmp == NULL)
    return;
}
