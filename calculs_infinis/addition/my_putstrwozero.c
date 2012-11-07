/*
** my_putstrwozero.c for evalxpr in /home/casoni_f//Projets/git/bistro/calculs_infinis
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Wed Nov  7 13:09:19 2012 fabien casoni
** Last update Wed Nov  7 13:11:38 2012 fabien casoni
*/

int	my_putstrwozero(char *str)
{
  int	i;

  i = 0;
  while (str[i] == '0')
    i += 1;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i += 1;
    }
}
