/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:09:12 by guortun-          #+#    #+#             */
/*   Updated: 2023/02/08 12:33:59 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

int	num_handler(int n, int fd, char *base)
{
	ft_putnbr_fd_base(n, fd, base);
	return (ft_numlen(n, base));
}
