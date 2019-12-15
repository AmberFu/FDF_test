/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:04:15 by pfu               #+#    #+#             */
/*   Updated: 2019/12/14 21:03:40 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_grid	*get_grid(char *line, int row)
{
	t_grid	*grid;

	if ((grid = (t_grid *)malloc(sizeof(t_grid))) == NULL)
		return (NULL);
	grid->row = row;
	grid->arr = ft_strdup(line);
	grid->next = NULL;
	return (grid);
}

void	print_grid_array(t_grid **grid_head)
{
	t_grid	*ptr;
	int		i;

	i = 0;
	ptr = *grid_head;
	while (ptr != NULL)
	{
		ft_putstr("row[");
		ft_putnbr(i);
		ft_putstr("] ");
		ft_putstr("ptr->arr = \n");
		ft_putstr(ptr->arr);
		ft_putchar('\n');
		ptr = ptr->next;
		i++;
	}
}

void	free_grid(t_grid **grid_head)
{
	t_grid  *ptr;

	ptr = *grid_head;
	while (ptr != NULL)
	{
		free(ptr->arr);
		ptr = ptr->next;
	}
	free(grid_head);
}

int		read_draw_fdf(int fd)
{
	int		x;
	char	*line;
	t_grid	*grid_ptr;
	t_grid	**grid_head;

	x = 0;
	if ((grid_head = (t_grid **)malloc(sizeof(t_grid *))) == NULL)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		if (x == 0) //First list
		{
			grid_ptr = get_grid(line, x);
			grid_head = &grid_ptr;
		}
		else //others
		{
			grid_ptr->next = get_grid(line, x);
			grid_ptr = grid_ptr->next;
		}
		free(line);
		x++;
	}
	print_grid_array(grid_head);
	//free_grid(grid_head);
	return (0);
}
