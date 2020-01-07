/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:04:15 by pfu               #+#    #+#             */
/*   Updated: 2020/01/06 12:16:54 by pfu              ###   ########.fr       */
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

/************* For test: *****************/
void	print_grid_array(t_grid *grid_head)
{
	int		i;

	/****/
	ft_putstr("\n\nprint_grid_array():\n");
	/****/
	i = 0;
	while (grid_head != NULL)
	{
		ft_putstr("row[");
		ft_putnbr(grid_head->row);
		ft_putstr("] ");
		ft_putstr("ptr->arr = \n");
		ft_putstr(grid_head->arr);
		ft_putchar('\n');
		grid_head = grid_head->next;
		i++;
	}
}
/********************************************/

void	free_grid(t_grid **grid_head)
{
	t_grid	*ptr;
	t_grid	*next;

	ptr = *grid_head;
	while (ptr != NULL)
	{
		free(ptr->arr);
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
	free(grid_head);
}

t_info	*create_info_struct(void)
{
	t_info	*info;

	if ((info = (t_info *)malloc(sizeof(t_info))) == NULL)
        return (NULL);
	info->rows = 0;
	info->cols = 0;
	info->max_z = 0;
	info->min_z = 0;
	info->ori_xyz_3d = NULL;
	return (info);
}

void	free_info(t_info *info)
{
	/*
	int		i;

	i = -1;
	while (++i < info->y) // row
		free(info->matrix[i]);
	free(matrix);*/
	free(info);
}

/********************************************/

void	print_info(t_info *info)
{
	ft_putstr("\nPRINT INFO:\n");
	ft_putstr("info->x = ");
	ft_putnbr(info->rows);
	ft_putchar('\n');
	ft_putstr("info->y = ");
	ft_putnbr(info->cols);
	ft_putchar('\n');
	ft_putstr("info->max_z = ");
	ft_putnbr(info->max_z);
	ft_putchar('\n');
	ft_putstr("info->min_z = ");
	ft_putnbr(info->min_z);
	ft_putstr("\n\n");
	// free_info(info);
}

/********************************************/

void	file_to_grid(int fd, t_grid	**grid_head)
{
	t_grid	*grid_ptr;
	int		rows_nbr;
	char	*line;

	rows_nbr = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (rows_nbr == 0) //First list
		{
			grid_ptr = get_grid(line, rows_nbr);
			*grid_head = grid_ptr;
		}
		else //others
		{
			grid_ptr->next = get_grid(line, rows_nbr);
			grid_ptr = grid_ptr->next;
		}
		free(line);
		rows_nbr++;
	}
}

int		get_line_info(char *arr, t_info	**info_struct)
{
	/* Get info */
}

int		grid_to_info(t_grid	*grid_head, t_info	**info_struct)
{
	int		last_row;
	int		col_size;
	int		first_col_size;

// Get 1) How many line? (x pos)...loop until last one + 1 (start from 0)
//     2) How many columns? (y pos)...col size must be the same number
	first_col_size = get_line_size(grid_head->arr);
	while (grid_head != NULL)
	{
		last_row = grid_head->row;
		// col_size = get_line_info(grid_head->arr);
		col_size = get_line_info(grid_head->arr, info_struct);
		if (col_size != first_col_size)
			return (-1);
		grid_head = grid_head->next;
	}


	*info_struct = create_info_struct();
	print_info(*info_struct);
}


/* Do validate!!! -> directly put into int 2d ? */
int		read_draw_fdf(int fd)
{
	t_grid	**grid_head;
	t_info	*info_struct;

	if ((grid_head = (t_grid **)malloc(sizeof(t_grid *))) == NULL)
		return (-1);
	file_to_grid(fd, grid_head);
	print_grid_array(*grid_head);
	// save t_grid to 2D interger array:
	if (grid_to_info(*grid_head, &info_struct) < 0)
		return (-1);

	// FREE memory:
	free_info(info_struct);
	free_grid(grid_head);
	return (0);
}
