/*
** my_revstr.c for  in /home/robin/delivery/CPool_Day06
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Mon Oct 10 13:27:55 2016 Robin Pronnier
** Last update Fri Jun  9 19:36:39 2017 Robin Pronnier
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	d;
  int	f;

  i = 0;
  d = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  i = i - 1;
  while (d < i)
    {
      f = str[d];
      str[d] = str[i];
      str[i] = f;
      d = d + 1;
      i = i - 1;
    }
  return (str);
}

int	my_revstr1(va_list ap)
{
  my_revstr(va_arg(ap, char *));
  return (0);
}
