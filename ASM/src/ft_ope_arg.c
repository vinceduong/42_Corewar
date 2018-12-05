/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:48:00 by tescriva          #+#    #+#             */
/*   Updated: 2018/12/05 01:37:24 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_nb_param(t_asm *f)
{
	f->ope.id = -1;
	while (++f->ope.id < 16 && ft_strcmp(op_tab[f->ope.id].name, f->ope.name))
		;
	f->ope.id == 16 ? error("Instruction is wrong") : 0;
	f->ope.nb_param = op_tab[f->ope.id].nb_param;
}

void ft_check_param(char *str, t_asm *f)
{
	int i;
	int n;
	int nb;

	i = 0;
	nb = -1;
	n = i + f->ope.param[nb];
	while (++nb < f->ope.nb_param)
	{
		while (str[n] && str[n] != ',' && str[n] != ' ' && str[n] != '\t')
		{
			f->ope.param[nb]++;
			n = i + f->ope.param[nb];
		}
		f->ope.p[nb] = ft_strsub(str, i, f->ope.param[nb]);
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != SEPARATOR_CHAR)
			i++;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] == COMMENT_CHAR)
			break ;
		(str[i] && nb == f->ope.nb_param - 1) || (str[i] != SEPARATOR_CHAR && str[i])
			|| f->ope.p[nb][0] == 0 ? error("lol") : 0;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
	}
	nb != f->ope.nb_param - 1 ? error("Comment Char before param") : 0;
}

void ft_fill_ope(char *str, t_asm *f)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i + j] && str[i + j] != ' ' && str[i + j] != '\t')
		j++;
	f->ope.name = ft_strsub(str, i, j);
	i = i + j;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	ft_nb_param(f);
	ft_check_param(str + i, f);
	ft_test_arg(f);
}

void ft_ope_arg(char *str, t_asm *f)
{
	int i;
	int val;

	i = -1;
	val = 0;
	f->error = 0;
	printf("yo\n" );
	while (str[++i])
		str[i] != ' ' || str[i] != '\t' ? val++ : 0;
	val ? ft_fill_ope(str, f) : 0;
	val ? f->error = 1 : 0;
}
