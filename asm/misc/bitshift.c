/*
** bitshift.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Fri Mar 17 20:37:36 2017 Nicolas Polomack
** Last update Sat Mar 18 20:56:57 2017 
*/

#include <stdlib.h>
#include "my_printf.h"
#include "my.h"
#include "asm.h"

char	*my_char_int_to_bytes(char *str, int *packets)
{
  int	i;
  int	l;
  int	c;
  char	*len;

  if (str == NULL)
    return (NULL);
  str = convert_base(str, "0123456789", "01");
  i = my_strlen(str);
  *packets = i / 8 + (i % 8 != 0);
  if ((len = malloc(*packets)) == NULL)
    return (NULL);
  my_memset(len, 0, *packets);
  l = *packets - 1;
  c = 0;
  while (i--)
    {
      if (str[i] == '1')
	len[l] += 1 << (c % 8);
      if ((c++ % 8) == 7)
	l -= 1;
    }
  free(str);
  return (len);
}

void	print_mem_char(char a, int e)
{
  if (e != 7)
    print_mem_char(a, e + 1);
  my_putchar(((a >> e) & 1) + '0');
}

int	get_prog_size(t_instruct *instr)
{
  int	i;

  i = 0;
  while (instr)
    {
      i += get_instruct_size(instr);
      instr = instr->next;
    }
  return (i);
}
