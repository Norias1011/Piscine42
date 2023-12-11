/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:35:09 by jlievano          #+#    #+#             */
/*   Updated: 2023/12/10 20:35:11 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

void	set_p_hold(char *p_hold)
{
	p_hold[0] = '1';
	p_hold[1] = '0';
	p_hold[2] = '0';
	p_hold[3] = '\0';
}

void	s_init_h(char *cero_key, char ***dict, int lines, char *p_hold)
{
	print_key(cero_key, dict, lines);
	print_key(p_hold, dict, lines);
}

void	prt_one_nine(char *p_hold, char *numbers, char ***dict, int lines)
{
	p_hold[0] = numbers[2];
	p_hold[1] = '\0';
	print_key(p_hold, dict, lines);
}

void	prt_ten_nineteen(char *p_hold, char *numbers, char ***dict, int lines)
{
	p_hold[0] = numbers[1];
	p_hold[1] = numbers[2];
	p_hold[2] = '\0';
	print_key(p_hold, dict, lines);
}

void	prt_twenty_ninety(char *p_hold, char *numbers, char ***dict, int lines)
{
	p_hold[0] = numbers[1];
	p_hold[1] = '0';
	p_hold[2] = '\0';
	print_key(p_hold, dict, lines);
	p_hold[0] = numbers[2];
	p_hold[1] = '\0';
	print_key(p_hold, dict, lines);
}
