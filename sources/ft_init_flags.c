/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:02:50 by bemmanue          #+#    #+#             */
/*   Updated: 2021/06/29 13:02:54 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_clean_flags(t_list **tab)
{
	(*tab)->space = 0;
	(*tab)->dash = 0;
	(*tab)->zero = 0;
	(*tab)->width = 0;
	(*tab)->prec = -1;
}

void	ft_init_flags(t_list **tab)
{
	(*tab)->space = 0;
	(*tab)->dash = 0;
	(*tab)->zero = 0;
	(*tab)->width = 0;
	(*tab)->prec = -1;
	(*tab)->length = 0;
}
