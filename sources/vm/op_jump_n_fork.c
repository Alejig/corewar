/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_jump_n_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 15:40:46 by vlaroque          #+#    #+#             */
/*   Updated: 2020/06/12 21:25:41 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		op_zjmp(t_data *data, t_process *process, t_cache *c)
{
	(void)data;
	if (process->carry)
		todo_change_pc(process, c->args[0].short_data);
	return (0);
}

int		op_fork(t_data *data, t_process *process, t_cache *c)
{
	int		pc;

	(void)data;
	pc = process->pc;
	pc += (c->args[0].short_data % IDX_MOD) % MEM_SIZE;
	pc = pc_fix(pc);
	todo_fork(process, pc);
	return (0);
}

int		op_lfork(t_data *data, t_process *process, t_cache *c)
{
	int		pc;

	(void)data;
	pc = process->pc;
	pc += c->args[0].short_data % MEM_SIZE;
	pc = pc_fix(pc);
	todo_fork(process, pc);
	return (0);
}
