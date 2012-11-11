/*
** stack.c for bistro in /home/casoni_f//Test/try_list/try_pile
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Tue Oct 30 16:26:41 2012 fabien casoni
** Last update Sun Nov 11 21:00:03 2012 fabien casoni
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

void	stack(t_pile *pile, char token)
{
  t_elem	*new;

  new = malloc(sizeof(*new));
  if (pile == NULL || new == NULL)
    return;
  new->token = token;
  new->next = pile->first;
  pile->first = new;
}

void	stackstr(t_pile *pile, char token, int pos)
{
  t_elem	*new;

  new = malloc(sizeof(*new));
  if (pile == NULL || new == NULL)
    return;
  new->str[pos] = token;
  new->next = pile->first;
  pile->first = new;
}

char	unstack(t_pile *pile)
{
  char		token_unstacked;
  t_elem	*elem_unstacked;

  elem_unstacked = malloc(sizeof(elem_unstacked));
  if (pile == NULL || elem_unstacked == NULL)
    return ('\0');
  token_unstacked = 0;
  elem_unstacked = pile->first;
  if (pile != NULL && pile->first != NULL)
    {
      token_unstacked = elem_unstacked->token;
      pile->first = elem_unstacked->next;
      free(elem_unstacked);
    }
  return (token_unstacked);
}

char	*unstackstr(t_pile *pile)
{
  char		*token_unstacked;
  t_elem	*elem_unstacked;
  int		i;

  i = 0;
  elem_unstacked = malloc(sizeof(*elem_unstacked));
  token_unstacked = malloc(sizeof(*token_unstacked));
  if (elem_unstacked == NULL || token_unstacked == NULL)
    return ('\0');
  elem_unstacked = pile->first;
  if (pile != NULL && pile->first != NULL)
    {
      while (elem_unstacked->str[i] != '\0')
	{
	  token_unstacked[i] = elem_unstacked->str[i];
	  i += 1;
	}
      token_unstacked[i] = '\0';
      pile->first = elem_unstacked->next;
      free(elem_unstacked);
    }
  return (token_unstacked);
}
