/*
** printf.c for  in /home/robin/delivery/PSU_2016_my_printf
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Wed Nov  9 12:43:50 2016 Robin Pronnier
** Last update Sat Jun 10 21:15:37 2017 Robin Pronnier
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int	(*ptr_fct_type[12])(va_list ap) =
{
  my_put_nbr1,
  my_put_nbr1,
  my_baseo,
  my_basex,
  my_baseX,
  my_putchar1,
  my_p,
  my_putstr1,
  my_baseb,
  my_putstrv21,
  my_mod,
  my_put_usdnbr1
};

int	(*ptr_fct_flag[3])(va_list ap, char *str, int i) =
{
  my_space,
  my_add,
  my_diez
};

int	my_type(char *type, char *str, int i, va_list ap)
{
  int	c;

  c = 0;
  while (type[c] != str[i + 1] && c < 13)
    c = c + 1;
  if (c < 12)
    ptr_fct_type[c](ap);
  else
    my_putchar('%');
  return (i + 1);
}

int	my_flags(char *flag, char *str, int i, va_list ap)
{
  int	c;

  c = 0;
  while (str[i + 1] != '\0' && flag[c] != str[i + 1] && c < 3)
    c = c + 1;
  if (c < 3)
    i = ptr_fct_flag[c](ap, str, i);
  return (i);
}

int		my_printf(char *str, ...)
{
  va_list	ap;
  int		i;
  char		type[] = "dioxXcpsbS%u";

  i = 0;
  va_start(ap, str);
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] == '%')
	{
	  i = my_type(type, str, i, ap);
	}
      else
	my_putchar(str[i]);
      i = i + 1;
    }
  va_end(ap);
  return (0);
}
