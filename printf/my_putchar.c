/*
** my_putchar.c for  in /home/robin/delivery/CPool_Day07/lib/my
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Tue Oct 11 20:01:09 2016 Robin Pronnier
** Last update Fri Jun  9 19:36:56 2017 Robin Pronnier
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putchar1(va_list ap)
{
  my_putchar(va_arg(ap, int));
  return (0);
}

int	my_mod(va_list ap)
{
  ap = ap;
  my_putchar('%');
  return (0);
}
