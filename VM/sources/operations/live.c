/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:01:37 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/20 17:13:22 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void live(t_vm *vm, t_proc *proc, t_operation *ope)
{
	(void)ope;
	proc->alive = 1;
	vm->players[proc->player].nb_live++;
	vm->players[proc->player].last_live = vm->cycle;
	//ft_printf("The player \"%s\" ($%d) is alive ! ",
		//vm->players[proc->player].filename, proc->player);
}