/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:06:43 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/25 10:45:10 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putendl(char const *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
