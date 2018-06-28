/*
** bot_attacks.c for  in /home/robin/delivery/CPE/CPE_2016_matchstick
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Sat Jun 10 21:30:26 2017 Robin Pronnier
** Last update Sat Jun 10 22:00:22 2017 Robin Pronnier
*/

#include <stdlib.h>
#include "my.h"

int	find_line_atk(char **map, int max_sticks)
{
  int	i;
  int	stick;
  int	sticks;
  int	stock_i;

  i = 0;
  stick = 0;
  sticks = 0;
  while (map[++i + 1] != NULL)
    {
      if (strlenstick(map[i]) == 1)
	++stick;
      else if (strlenstick(map[i]) > 1)
	{
	  ++sticks;
	  stock_i = i;
	}
    }
  if (sticks == 1 && (stick % 2 == 1) &&
      strlenstick(map[stock_i]) <= max_sticks)
    return (print_bot_attack(map, stock_i, strlenstick(map[stock_i])));
  else if (sticks == 1 && (stick % 2 == 0) &&
	   strlenstick(map[stock_i]) - 1 <= max_sticks)
    return (print_bot_attack(map, stock_i, strlenstick(map[stock_i]) - 1));
  return (1);
}

int	pick_one_stick(char **map, int c)
{
  int	i;

  i = 1;
  while (i <= c)
    {
      if (strlenstick(map[i]) != 0)
	return (i);
      ++i;
    }
  return (0);
}
