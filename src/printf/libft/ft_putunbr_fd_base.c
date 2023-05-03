/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:08:34 by guortun-          #+#    #+#             */
/*   Updated: 2023/02/08 12:33:22 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd_base(unsigned int n, int fd, char *base)
{
	size_t		m;
	size_t		base_size;
	static int	i;

	m = (size_t)n;
	base_size = 0;
	base_size = ft_strlen(base);
	i = 0;
	if (m >= base_size)
		ft_putunbr_fd_base(m / base_size, fd, base);
	m %= base_size;
	write (fd, &base[m], 1);
	return (i++);
}
