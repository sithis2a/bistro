/*
** my_putstr.c for my_putstr in /home/ayel_a//afs/day03/my_putstr
** 
** Made by christophe1 ayel
** Login   <ayel_a@epitech.net>
** 
** Started on  Fri Oct  5 11:50:57 2012 christophe1 ayel
** Last update Tue Nov  6 16:52:10 2012 christophe1 ayel
*/

void	my_putstr(char *str)
{
  int	x;

  x = 0;
  while (str[x] != 0)
    {
      my_putchar(str[x]);
      x = x + 1;
    }
}
