/*
** my_putstr.c for  in /home/robin/delivery/CPool_Day04
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Thu Oct  6 17:38:27 2016 Robin Pronnier
** Last update Fri Jun  9 19:38:24 2017 Robin Pronnier
*/

#include <stdlib.h>
#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    {
      my_putstr("(null)");
      return (0);
    }
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

int	my_putstr1(va_list ap)
{
  my_putstr(va_arg(ap, char *));
  return (0);
}
