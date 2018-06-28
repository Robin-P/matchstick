/*
** my_putstrv2.c for  in /home/robin/delivery/PSU_2016_my_printf/lib
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Mon Nov 14 14:59:37 2016 Robin Pronnier
** Last update Fri Jun  9 19:38:39 2017 Robin Pronnier
*/

#include <stdlib.h>
#include "my.h"

int	tsm(char *str, int i)
{
  if (str[i] < 8 && str[i] >= 0)
    {
      my_putstr("00");
      my_base(str[i], 8, 55);
    }
  else if (str[i] < 64 && str[i] >= 0)
    {
      my_putchar('0');
      my_base(str[i], 8, 55);
    }
  else
    my_base(-str[i], 8, 55);
  return (0);
}

int	my_putstrv2(char *str)
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
      if (str[i] < 32 || str[i] > 126)
	{
	  my_putchar('\\');
	  tsm(str, i);
	}
      else
	my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

int	my_putstrv21(va_list ap)
{
  my_putstrv2(va_arg(ap, char *));
  return (0);
}
