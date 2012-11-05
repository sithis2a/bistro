/*
** stack.c for bistro in /home/casoni_f//Test/try_list/try_pile
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Tue Oct 30 16:26:41 2012 fabien casoni
** Last update Tue Oct 30 19:28:58 2012 fabien casoni
*/

#include <stdlib.h>
#include "stack.h"

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

void	display_pile(t_pile *pile)
{
  t_elem	*actual;

  actual = malloc(sizeof(*actual));
  if (pile == NULL || actual == NULL)
    return;
  actual = pile->first;
  while (actual != NULL)
    {
      printf("%s\n", actual->token);
      actual = actual->next;
    }
  printf("\n");
}

/*
int	main()
{
  t_pile	*pile;

  pile = malloc(sizeof(*pile));
  stack(pile, "45");
  stack(pile, "74");
  stack(pile, "98");
  printf("Etat de la pile:\n");
  display_pile(pile);
  printf("Je destack %s\n", unstack(pile));
  printf("Je destack %s\n", unstack(pile));
  printf("\nEtat de la pile:\n");
  display_pile(pile);
  free(pile);
}
*/
