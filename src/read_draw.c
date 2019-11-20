/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:04:15 by pfu               #+#    #+#             */
/*   Updated: 2019/11/19 22:16:33 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_grid	*get_xy(char *line, int row)
{
	t_grid	*grid;

	if ((grid = (t_grid *)malloc(sizeof(t_grid))) == NULL)
		return (NULL);
	grid->row = row;
	grid->arr = ft_strsplit(line, ' ');
	grid->next = NULL;
	return (grid);
}

void	print_arr(char **arr)
{
	char	*ptr;

	ptr = *arr;
	while (ptr != NULL)
	{
		printf(" \"%s\" ", ptr);
		ptr++;
	}
	printf("\n");
}

void	print_grid_array(t_grid **grid_head)
{
	t_grid	*ptr;
	int		i;

	i = 0;
	ptr = *grid_head;
	while (ptr != NULL)
	{
		printf("row[%d]: arr = ", ptr->row);
		print_arr(ptr->arr);
		ptr = ptr->next;
		i++;
	}
}

void	read_draw_fdf(int fd)
{
	int		x;
	char	*line;
	t_grid	**grid_head;
	t_grid	*prev;

	x = 0;
	grid_head = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (x == 0)
		{
			*grid_head = get_xy(line, x);
			prev = *grid_head;
		}
		else
		{
			prev->next = get_xy(line, x);
			prev = prev->next;
		}
		print_grid_array(grid_head);
		free(line);
		x++;
	}
}
