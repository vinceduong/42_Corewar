/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_pc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:52:44 by vduong            #+#    #+#             */
/*   Updated: 2018/11/25 13:27:07 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		mod_pc(int value)
{
    int pc;

    pc = value % MEM_SIZE;
    if (pc < 0)
        pc += MEM_SIZE;
    return (pc);
}
