/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:17 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/20 20:43:18 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void corewar_fork(t_vm *vm, t_proc *proc, t_operation *ope)
{
	t_proc *fork;

	if (ope->param[0] == 0)
	{
		fork = init_process(vm, proc->pc + (ope->param[0] % IDX_MOD),
			proc->player);
	}
	else
		fork = init_process(vm, proc->pc, proc->player);
	fork->carry = proc->carry;
	fork->alive = proc->alive;
}

void lfork(t_vm *vm, t_proc *proc, t_operation *ope)
{
	t_proc *fork;

	if (ope->param[0] == 0)
		fork = init_process(vm, proc->pc, proc->player);
	fork->carry = proc->carry;
	fork->alive = proc->alive;
}
