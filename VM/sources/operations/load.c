/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:24 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/24 09:42:55 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void direct_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	//ft_putstr("In direct_load\n");
	if (ope->param_type[0] == IND_CODE)
		proc->r[(size_t)ope->param[1] - 1] = read_int(vm, mod_pc(proc->pc + (ope->param[0] % IDX_MOD)));
	else
		proc->r[(size_t)ope->param[1] - 1] = ope->param[0];
	proc->carry = ope->param[0] == 0 ? 1 : 0;
}

void indirect_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;

	//ft_putstr("In indirect_load\n");
	if (ope->param_type[0] == T_REG)
		a = proc->r[(size_t)ope->param[0] - 1];
	else if (ope->param_type[0] == T_IND)
		a = mod_pc(proc->pc + (ope->param_type[0] % IDX_MOD));
	else
		a = ope->param[0];
	if (ope->param_type[1] == T_IND)
		b = mod_pc(proc->pc + (ope->param_type[1] % IDX_MOD));
	else
		b = ope->param[1];
	proc->r[(size_t)ope->param[2] - 1] = read_int(vm, a + b);
	proc->carry = a + b == 0 ? 1 : 0;
}

void long_indirect_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;

	//ft_putstr("In long_indirect_load\n");
	if (ope->param_type[0] == T_REG)
		a = proc->r[(size_t)ope->param[0] - 1];
	else if (ope->param_type[0] == T_IND)
		a = mod_pc(proc->pc + ope->param[0]);
	else
		a = ope->param[0];
	if (ope->param_type[1] == T_IND)
		b = mod_pc(proc->pc + ope->param[1]);
	else
		b = ope->param[1];
	proc->r[(size_t)ope->param[2] - 1] = read_int(vm, a + b);
	proc->carry = a + b == 0 ? 1 : 0;
}

void long_direct_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	//ft_putstr("In long_direct_load\n");
	if (ope->param_type[0] == IND_CODE)
		proc->r[(size_t)ope->param[1] - 1] = read_int(vm, proc->pc);
	else
		proc->r[(size_t)ope->param[1] - 1] = ope->param[0];
	proc->carry = !ope->param[0] ? 1 : 0;
}
