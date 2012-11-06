/*
** my_strlen.c for my_strlen in /home/ayel_a//afs/liens/rendu/piscine/Jour_04
** 
** Made by christophe1 ayel
** Login   <ayel_a@epitech.net>
** 
** Started on  Wed Oct 10 15:06:13 2012 christophe1 ayel
** Last update Thu Oct 11 16:12:08 2012 christophe1 ayel
*/

int	my_strlen(char *str)
{
  int	x;

  x = 0;
  while (str[x] != 0)
    {
      x = x + 1;
    }
  return (x);
}
