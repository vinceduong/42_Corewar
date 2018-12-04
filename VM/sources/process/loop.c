/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aetchego <aetchego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:49:51 by vduong            #+#    #+#             */
/*   Updated: 2018/12/04 17:38:13 by aetchego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		handle_processes(t_vm *vm)
{
	t_proc	*process;

	process = vm->processes;
	while (process)
	{
		if (!process->cycles)
			load_instruction(process, vm);
		process->cycles--;
		if (!process->cycles)
			execute_instruction(process, vm);
		process = process->next;
	}
}

void			loop(t_vm *vm)
{
	int step;

	step = 1;
	while (1)
	{
		vm->sbs = 0;
		//dump_ram(vm);
		if (vm->visu == 1)
			display(vm, step);
		step++;
		if (vm->cycles_total == vm->dump_cycle && !vm->visu)
			dump_ram(vm);
		vm->cycles_total++;
	//	printf("Cycle = %d, Number of processes = %d\n", vm->cycles_total, vm->num_processes);
		handle_processes(vm);
		vm->cycles_left--;
		if (!vm->cycles_left && !check_processes(vm))
			break ;
	}
	vm->win = 1;
	printf("Total cycles = %d\n", vm->cycles_total);
	dump_ram(vm);
}