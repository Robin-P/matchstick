/*
** my_type.c for  in /home/robin/delivery/PSU_2016_my_printf
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Thu Nov 17 13:46:08 2016 Robin Pronnier
** Last update Fri Jun  9 19:39:34 2017 Robin Pronnier
*/

#include "my.h"

int		my_add(va_list ap, char *str, int i)
{
  va_list	aq;
  va_list	al;
  int		c;

  c = 0;
  i = i + 1;
  va_copy(aq, ap);
  va_copy(al, ap);
  while (str[i] == '+')
    {
      c = c + 1;
      i = i + 1;
    }
  if (c != 0)
    {
      if (va_arg(aq, int) >= 0 && (str[i] == 'd' || str[i] == 'i'))
	my_putchar('+');
      else if (va_arg(al, long int) >= 0 && (str[i] == 'p'))
	my_putchar('+');
    }
  va_end(aq);
  va_end(al);
  return (c);
}

int		my_space(va_list ap, char *str, int i)
{
  va_list	aq;
  int		c;

  c = 0;
  i = i + 1;
  va_copy(aq, ap);
  while (str[i] == ' ')
    {
      c = c + 1;
      i = i + 1;
    }
  if (c != 0)
    {
      if (va_arg(aq, int) >= 0)
	my_putchar(' ');
    }
  va_end(aq);
  return (c);
}

int	my_diez(va_list ap, char *str, int i)
{
  int	c;

  ap = ap;
  c = 0;
  i = i + 1;
  while (str[i] == '#')
    {
      c = c + 1;
      i = i + 1;
    }
  if (c != 0)
    {
      if (str[i] == 'o' || str[i] == 'x'|| str[i] == 'X')
	my_putchar('0');
      if (str[i] == 'x' || str[i] == 'X')
	my_putchar(str[i]);
    }
  return (c);
}
