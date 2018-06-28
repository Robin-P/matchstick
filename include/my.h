/*
** my.h for  in /home/robin/delivery/CPE/CPE_2016_matchstick
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Jun  9 17:14:51 2017 Robin Pronnier
** Last update Sun Jun 11 12:31:40 2017 Robin Pronnier
*/

#ifndef MY_H_
# define MY_H_

#include <stdarg.h>

int	find_line_atk(char **, int);
int	pick_one_stick(char **, int);
int	print_bot_attack(char **, int, int);
int	free_tab(char **);
int	check_first_arg(char *);
void	my_putchar(char);
int	my_putstr(char *);
int	my_put_nbr(int);
int	my_strlen(char *);
int	my_getnbr(char *);
char	*get_next_line(int);
void	my_show_tab(char **);
int	turn_based(char **, int, int);
int	strlenstick(char *);
int	check_sec_arg(char *);
int	end(char **);
int	returns(int);
int	bot_pos(int, int);
int	my_puterr(char *, int);
int	bot(char **, int, int);
int	dec_bin(int);
int	bin_dec(int);
char	**remove_sticks(char **, int, int);
char	**malloc_map(char **, int);
int	my_printf(char *, ...);
short	my_short(int);
long	my_long(int);
int	my_put_usdnbr(unsigned int);
int	my_base(long int, int, int);
int	my_putstrv2(char *);
int	type(char *, int, va_list);
int	type2(char *, int, va_list);
int	type3(char *, int, va_list);
char	*my_revstr(char *);
int	my_put_nbr1(va_list);
int	my_baseo(va_list);
int	my_basex(va_list);
int	my_baseX(va_list);
int	my_putchar1(va_list);
int	my_p(va_list);
int	my_putstr1(va_list);
int	my_baseb(va_list);
int	my_putstrv21(va_list);
int	my_mod(va_list);
int	my_put_usdnbr1(va_list);
int	my_add(va_list, char *, int);
int	my_space(va_list, char *, int);
int	my_diez(va_list, char *, int);

#endif /* !MY_H_ */
