/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:28:42 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/14 18:43:35 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm.h"

int ft_parser(char **av, t_vm *vm)
{
	if (ft_check_arg(av, vm) == 0)
	/*if (ft_flag(av, vm) == 0)
	if (ft_check_champ(av, vm) == 0)
	if (ft_init_player(vm) == 0)*/
	return (1);
}
