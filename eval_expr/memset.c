/*
** memset.c for eval_xpr in /home/casoni_f//Projets/C/eval_expr
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Wed Oct 31 13:18:44 2012 fabien casoni
** Last update Wed Oct 31 13:20:09 2012 fabien casoni
*/

void	mem_set(char *buff, int c, int size)
{
  while (size > 0)
    {
      buff[size] = c;
      size -= 1;
    }
}
