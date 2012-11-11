/*
** my.h for my.h in /home/casoni_f//Test/Jour_09
** 
** Made by fabien casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Thu Oct 11 11:31:18 2012 fabien casoni
** Last update Thu Nov  8 11:45:44 2012 fabien casoni
*/

#ifndef	__MY_H__
# define	__MY_H__

#include "struct.h"

void	my_putchar(char c);
int	my_isneg(int nb);
void	my_put_nbr(int nb);
void	my_swap(int *a, int *b);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
void	stack(t_pile *pile, char token);
char	unstack(t_pile *pile);
void	display_pile(t_pile *pile);
char	*mmalloc(t_elem *elem, t_pile *pile);
int	check_nonop(char *str, t_pile *pile, t_elem *actual, t_control *ctrl);
int	check_operator(char *str, t_pile *pile, t_elem *actual, t_control *ctrl);
void	check_operande(char *str, t_control *ctrl);
void	freestack(t_elem *actual, t_control *ctrl, t_pile *pile);
void	initctrl(t_control *control);

#endif
