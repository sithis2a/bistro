/*
** addition.c for addition in /home/ayel_a//calculs_infinis
** 
** Made by christophe1 ayel
** Login   <ayel_a@epitech.net>
** 
** Started on  Sat Nov  3 18:22:03 2012 christophe1 ayel
** Last update Wed Nov  7 10:59:30 2012 fabien casoni
*/

# include <stdlib.h>
# include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	size(char *str, char *str2)
{
  char	*result;
  int	a;
  int	b;
  char *other;
  char *result2;

  result = malloc(sizeof(*result));
  a = my_strlen(str);
  b = my_strlen(str2);
  if (a >= b)
    {
      result = str;
      other = str2;
    }
  else if (b > a)
    {    
      result = str2;
      other = str;
    }
  result2 = change_result(result);
  addition(result2, other);
}

char	*change_result(char *result)
{
  char *result2;
  int	a;
  int	b;

  result2 = malloc(sizeof(*result + 1));
  a = my_strlen(result);
  b = a + 1;
  result2[0] = '0';
  while (b > 0)
    { 
      result2[b] = result[a];
      a = a - 1;
      b = b - 1;
    }
  return (result2);
}

int	addition(char *result, char *other)
{
  int	a;
  int	b;

  a = my_strlen(result);
  b = my_strlen(other);
  while (b >= 0)
    {
      result[a] = result[a] + other[b] - '0';
      if (result[a] > '9')
	{
	  result[a] = result[a] - 10;
	  result[a - 1] = result[a - 1] + 1;
	}
      a = a - 1;
      b = b - 1;
    }
  my_putstr(result);
}

int	main(int argc, char **argv)
{
  size(argv[1], argv[2]);
  my_putchar('\n');
}
