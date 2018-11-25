/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:11:06 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/25 13:26:56 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	dump(t_vm *vm)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		i % 32 == 0 ? ft_printf("0x%.4x : ", i) : 0;
		ft_printf("%.2x ", vm->ram[i].content);
		(i + 1) % 32 == 0 ? ft_printf("\n") : 0;
	}
	ft_printf("\n\n");
	exit(1);
}
