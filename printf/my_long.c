/*
** my_long.c for  in /home/robin/delivery/PSU_2016_my_printf
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Wed Nov 16 16:01:18 2016 Robin Pronnier
** Last update Fri Jun  9 19:37:47 2017 Robin Pronnier
*/

#include "my.h"

long	my_long(int nb)
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
