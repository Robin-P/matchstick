/*
** bot.c for  in /home/robin/delivery/CPE/CPE_2016_matchstick
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Jun  9 19:29:01 2017 Robin Pronnier
** Last update Sun Jun 11 11:16:47 2017 Robin Pronnier
*/

#include <stdlib.h>
#include "my.h"

static int	my_xor(char **map)
{
  int	xor;
  int	lin;

  lin = 1;
  xor = 0;
  while (map[lin + 1] != NULL)
    {
      if (strlenstick(map[lin]) > 0)
	xor = xor ^ dec_bin(strlenstick(map[lin]));
      ++lin;
    }
  return (xor);
}

int		print_bot_attack(char **map, int lin, int stick)
{
  my_printf("AI removed %d match(es)", stick);
  my_printf(" from line %d\n", lin);
  map = remove_sticks(map, lin, stick);
  return (0);
}

int		bot(char **map, int max_stick, int nb_lin)
{
  int		lin;
  int		stick;
  int		xor;
  int		rm;

  rm = 0;
  lin = 1;
  if (find_line_atk(map, max_stick) == 0)
    return (0);
  while (map[lin + 1] != NULL)
    {
      xor = my_xor(map);
      rm = bin_dec((xor = xor ^ dec_bin(strlenstick(map[lin]))));
      if (((stick = strlenstick(map[lin]) - rm) > 0) &&
	  stick <= max_stick)
	return (print_bot_attack(map, lin, stick));
      ++lin;
    }
  lin = pick_one_stick(map, nb_lin);
  return (print_bot_attack(map, lin, 1));
}
