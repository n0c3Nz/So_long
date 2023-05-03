/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:08:50 by guortun-          #+#    #+#             */
/*   Updated: 2023/02/08 12:33:27 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

// AUX FUNCTIONS FROM LIBFT
size_t	ft_strlen(const char *s);
int		ft_numlen(int n, char *base);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_putunbr_fd_base(unsigned int n, int fd, char *base);
void	ft_putnbr_fd_base(int n, int fd, char *base);
int		ft_putaddr_fd(unsigned long int n, int fd);

#endif
