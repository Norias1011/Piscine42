/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:35:27 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/10 17:12:56 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_FUNCTIONS_H
# define HELPER_FUNCTIONS_H

void	print_str(char *str);
void	set_p_hold(char *place_holder);
void	s_init_h(char *cero_key, char ***dict, int lines, char *p_hold);
void	prt_one_nine(char *p_hold, char *numbers, char ***dict, int lines);
void	prt_ten_nineteen(char *p_hold, char *numbers, char ***dict, int lines);
void	prt_twenty_ninety(char *p_hold, char *numbers, char ***dict, int lines);
void	ft_strcpy(char *dest, char *src);
void	filler(char *dest, char *src);
void	get_key(char *str, char **dictionary_key_array);
void	get_value(char *str, char **dictionary_value_array);
void	string_validator(int lines, char **splits, char ***dictionary);
void	cero_handler(char ***dict, int lines);
int		key_is_equal(char *key, char *to_search);
char	*get_search_key(int groups);
void	get_multiplier_value(int groups, int lines, char ***dictionary);
void	print_key(char *key, char ***dictionary, int lines);
int		last_digits_int(char decimal, char unity);
int		arr_len(char *str);
int		is_digit(char c);
int		is_number(char c);
int		get_amount_of_lines(char *src);
int		is_printable(char c);
int		is_zero(int groups, char **numbers);

#endif
