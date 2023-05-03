/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:09:32 by guortun-          #+#    #+#             */
/*   Updated: 2023/02/08 12:34:07 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

int	uns_handler(unsigned int n, int fd, char *base)
{
	return (ft_putunbr_fd_base(n, fd, base) + 1);
}
