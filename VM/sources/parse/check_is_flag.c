/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:34:27 by vduong            #+#    #+#             */
/*   Updated: 2018/11/16 17:35:13 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int check_is_flag(char **av, int i)
{
	if (av[i][0] == '-')
		return (!ft_strcmp(av[i], "-dump") || !ft_strcmp(av[i], "-n") ? 1 : -1);
	else
		return (0);
}