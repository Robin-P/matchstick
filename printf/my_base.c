/*
** my_base.c for  in /home/robin/delivery/PSU_2016_my_printf/lib
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Tue Nov 15 11:52:10 2016 Robin Pronnier
** Last update Fri Jun  9 19:39:16 2017 Robin Pronnier
*/

#include <stdlib.h>
#include "my.h"

int	my_base(long int nb, int base, int caps)
{
  char	*av;
  int	i;
  int	res;

  i = 0;
  av = malloc(sizeof(char) + 50);
  while (nb != 0)
    {
      res = nb % base;
      if (res <= 9)
	res = res + '0';
      else
	res = res + caps;
      av[i] = res;
      nb = nb / base;
      i = i + 1;
    }
  my_putstr(my_revstr(av));
  return (0);
}

int		my_baseb(va_list ap)
{
  va_list	aq;

  va_copy(aq, ap);
  if (va_arg(aq, long int) == 0)
    {
      my_putchar('0');
      return (0);
    }
  my_base(va_arg(ap, long int), 2, 55);
  va_end(aq);
  return (0);
}

int		my_baseo(va_list ap)
{
  va_list	aq;

  va_copy(aq, ap);
  if (va_arg(aq, long int) == 0)
    {
      my_putchar('0');
      return (0);
    }
  my_base(va_arg(ap, long int), 8, 55);
  va_end(aq);
  return (0);
}

int		my_basex(va_list ap)
{
  va_list	aq;

  va_copy(aq, ap);
  if (va_arg(aq, long int) == 0)
    {
      my_putchar('0');
      return (0);
    }
  my_base(va_arg(ap, long int), 16, 87);
  va_end(aq);
  return (0);
}

int		my_baseX(va_list ap)
{
  va_list	aq;

  va_copy(aq, ap);
  if (va_arg(aq, long int) == 0)
    {
      my_putchar('0');
      return (0);
    }
  my_base(va_arg(ap, long int), 16, 55);
  va_end(aq);
  return (0);
}
