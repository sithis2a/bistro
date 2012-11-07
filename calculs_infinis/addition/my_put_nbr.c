/*
** my_put_nbr.c for my_put_nbr in /home/ayel_a//afs/put_nbr
** 
** Made by christophe1 ayel
** Login   <ayel_a@epitech.net>
** 
** Started on  Tue Oct 23 11:36:04 2012 christophe1 ayel
** Last update Tue Nov  6 16:53:12 2012 christophe1 ayel
*/

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    my_putchar('0' + nb);
}
