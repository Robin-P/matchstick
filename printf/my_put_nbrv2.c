/*
** my_put_nbrv2.c for  in /home/robin/delivery/PSU_2016_my_printf/lib
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Tue Nov 15 10:36:22 2016 Robin Pronnier
** Last update Fri Jun  9 19:38:07 2017 Robin Pronnier
*/

#include "my.h"

int	my_put_usdnbr(unsigned int nb)
{
  if (nb <= 9)
    my_putchar(nb + 48);
  if (nb > 9)
    {
      my_put_usdnbr(nb / 10);
      my_put_usdnbr(nb % 10);
    }
  return (0);
}

int	my_put_usdnbr1(va_list ap)
{
  my_put_usdnbr(va_arg(ap, unsigned int));
  return (0);
}
