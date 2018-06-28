/*
** my_print_nbr.c for  in /home/robin/delivery/CPool_Day03
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Thu Oct  6 08:14:29 2016 Robin Pronnier
** Last update Fri Jun  9 19:37:15 2017 Robin Pronnier
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      if (nb == -2147483648)
	{
	  my_put_nbr(-214748364);
	  my_putchar('8');
	  return (0);
	}
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0 && nb <= 9)
    {
      my_putchar(nb + 48);
    }
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  return (0);
}

int	my_put_nbr1(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
  return (0);
}

int		my_p(va_list ap)
{
  va_list	aq;

  va_copy(aq, ap);
  if (va_arg(aq, long int) == 0)
    my_putstr("(nil)");
  else
    {
      my_putstr("0x");
      my_base(va_arg(ap, long int), 16, 87);
    }
  va_end(aq);
  return (0);
}
