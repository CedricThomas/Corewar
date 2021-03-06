/*
** exec_head.c for exec_head in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Wed Mar 22 22:22:03 2017 Arthur Knoepflin
** Last update Sat Apr  1 20:53:30 2017 Nicolas Polomack
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"
#include "op.h"

int	get_cycle_next(t_game *g, t_heads *head, t_ins *actual)
{
  int	pos;
  t_ins	*tmp;

  pos = head->pos;
  if (actual->cmd == 9)
    pos += actual->val[0];
  else
    pos += actual->tot_byte;
  if ((tmp = get_instruc(g, pos)) == NULL)
    return (0);
  return (g_op_tab[tmp->cmd - 1].nbr_cycles);
}

void	exec_head(t_game *g,
		  t_heads *head,
		  void (*fnt[16])(t_game *, t_heads *, t_ins *))
{
  t_ins	*ins;

  if (g->cycle >= head->ctn_cycle)
    {
      if ((ins = get_instruc(g, head->pos)) == NULL)
	{
	  head->pos += 1;
	  return ;
	}
      head->ctn_cycle = g->cycle + get_cycle_next(g, head, ins);
      fnt[ins->cmd - 1](g, head, ins);
      if (ins->cmd != 9 || (ins->cmd == 9 && !head->carry))
	head->pos += ins->tot_byte;
      free(ins);
    }
  update_live(g);
}
