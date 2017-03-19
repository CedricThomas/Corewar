/*
** write.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Sun Mar 19 18:06:29 2017 Nicolas Polomack
** Last update Sun Mar 19 19:41:45 2017 
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "op.h"
#include "my.h"

void	write_simple_instruct(t_instruct *instruct, t_asm *myasm)
{
  char	*dir;
  int	size;
  char	*byte_code;
  char	str[DIR_SIZE % IDX_MOD];

  dir = instruct->args[0];
  my_memset(str, 0, DIR_SIZE % IDX_MOD);
  if ((instruct->op->type[0] & T_LAB) == T_LAB)
    dir = my_unsigned_to_char((unsigned int)
			      label_to_addr(myasm, instruct,
					    dir + 2, &size));
  if (size)
    my_printf("error : %d\n", size);
  byte_code = my_char_int_to_bytes(dir + (dir[0] == '%'), &size);
  my_strncpy(str + ((DIR_SIZE % IDX_MOD) - size), byte_code, size);
  write(myasm->fd, str, DIR_SIZE % IDX_MOD);
}

void	write_live_instruct(t_instruct *instruct, t_asm *myasm)
{
  char	*dir;
  int	size;
  char	*byte_code;
  char	str[4];

  dir = instruct->args[0];
  my_memset(str, 0, 4);
  if ((instruct->op->type[0] & T_LAB) == T_LAB)
    dir = my_unsigned_to_char((unsigned int)
                              label_to_addr(myasm, instruct,
                                            dir + 2, &size));
  if (size)
    my_printf("error : %d\n", size);
  byte_code = my_char_int_to_bytes(dir + (dir[0] == '%'), &size);
  my_strncpy(str + (4 - size), byte_code, size);
  write(myasm->fd, str, 4);
}

void	write_math_instruct(t_instruct *instruct, t_asm *myasm)
{
  int	i;

  write_args_type(instruct, myasm->fd);
  i = -1;
  while (++i < instruct->op->nbr_args)
  	write_standard_reg(instruct, i, myasm);
}

void	write_logic_instruct(t_instruct *instruct, t_asm *myasm)
{
  int	i;

  i = -1;
  while (++i < instruct->op->nbr_args)
  {
	if ((instruct->op->type[i] & T_DIR) == T_DIR)
	  write_standard_dir(instruct, i, myasm);
	else if ((instruct->op->type[i] & T_IND) == T_IND)
	  write_standard_ind(instruct, i, myasm);
	else if ((instruct->op->type[i] & T_REG) == T_REG)
	  write_standard_reg(instruct, i, myasm);
  }
}