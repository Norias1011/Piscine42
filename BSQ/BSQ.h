/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:41:38 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/13 11:59:10 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_cat(void);
void	ft_putnbr(int nb);
char	ft_char_void(char *argv);
char	ft_char_obst(char *argv);
char	ft_char_full(char *argv);
char	**ft_read_file(char *argv);
char	*read_input(char *path);
void	ft_second_line(int fd);
char	*ft_strcpy(char *dest, char *src);
void	ft_print_names(int i, int argc, char **argv);
void	ft_show_file(int i, int fd, int argc, char **argv);
char	**ft_fill_map(char **map, int c, int l, char *argv);
void	ft_print_solutions(int i, char *argv);
int		ft_number_lines(char *argv);
int		ft_number_columns(char *argv);
int		ft_strlen(char *str);
int		ft_check_char(char *argv);
int		ft_check_columns(char *argv);
int		ft_check_returns(char *argv);
int		ft_check_map(char *argv);
int		ft_next_columns(char *argv, int fd);
int		ft_atoi(char *str);
int		ft_size_file(char *argv);
int		ft_min(int a, int b, int c);
int		**ft_generate_map(int l, int c);
int		ft_biggest_square(char **map, int c, int l, char o);
int		ft_find_position_square(char **map, int c, int l, char o);
int		check_buf(char *argv);
int		ft_get_len(char *argv);

#endif
