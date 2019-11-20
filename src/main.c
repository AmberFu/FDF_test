/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:55:51 by pfu               #+#    #+#             */
/*   Updated: 2019/11/19 18:02:35 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		print_usage(void)
{
	ft_putstr("Usage: ./fdf input_file\n");
	return (-1);
}

int		print_error(void)
{
	ft_putstr("error\n");
	return (-1);
}

int		main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (print_usage());
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (print_error());
	read_draw_fdf(fd);
	return (0);
}
