/*
** main.c for  in /home/robin/delivery/CPE/CPE_2016_matchstick
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Jun  9 17:15:53 2017 Robin Pronnier
** Last update Sat Jun 10 21:36:51 2017 Robin Pronnier
*/

#include <stdlib.h>
#include "my.h"

int	main(int ac, char **av)
{
  int	ret;
  char	**map;

  map = NULL;
  if (ac == 3 && (check_first_arg(av[1]) != 1) &&
      check_sec_arg(av[2]) >= 0 &&
      (ret = my_getnbr(av[2])) > 0)
    return (turn_based(map, my_getnbr(av[1]), my_getnbr(av[2])));
  else
    return (84);
}
