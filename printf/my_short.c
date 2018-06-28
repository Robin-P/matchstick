/*
** my_short.c for  in /home/robin/delivery/PSU_2016_my_printf
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Wed Nov 16 15:44:42 2016 Robin Pronnier
** Last update Fri Jun  9 19:37:31 2017 Robin Pronnier
*/

#include "my.h"

short	my_short(int nb)
{
  if (nb < 0)
    {
      if (nb == -32767)
	{
	  my_put_nbr(-3276);
	  my_putchar('7');
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
