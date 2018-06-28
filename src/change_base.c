/*
** change_base.c for  in /home/robin/delivery/CPE/CPE_2016_matchstick/src
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Jun  9 19:52:04 2017 Robin Pronnier
** Last update Fri Jun  9 19:52:05 2017 Robin Pronnier
*/

#include "my.h"

int	my_power_rec(int nb, int p)
{
  int	nbr;

  if (p < 0)
    nbr = 0;
  else
    {
      nbr = 1;
      if (p > 0)
	nbr = my_power_rec(nb, p - 1) * nb;
    }
  return (nbr);
}

int	dec_bin(int nb)
{
  int	bin;
  int	zero;

  bin = 0;
  zero = 0;
  while (nb != 0)
    {
      if (bin == 0 && (nb % 2 == 0))
	zero = zero + 1;
      bin = bin * 10 + nb % 2;
      nb = nb / 2;
    }
  while (zero != 0)
    {
      bin = bin * 10;
      zero = zero - 1;
    }
  return (bin);
}

int	bin_dec(int nb)
{
  int	dec;
  int	i;

  dec = 0;
  i = 0;
  while (nb != 0)
    {
      if (nb % 10 == 1)
	dec = dec + my_power_rec(2, i);
      i = i + 1;
      nb = nb / 10;
    }
  return (dec);
}
