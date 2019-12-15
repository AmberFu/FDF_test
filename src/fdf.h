/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:32:39 by pfu               #+#    #+#             */
/*   Updated: 2019/12/14 20:59:31 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_grid
{
	int				row;
	char			*arr; // may change to a struct: row_len(Y) and int array[]
	struct s_grid	*next;
}					t_grid;

typedef struct		s_info
{
	int				x;
	int				y;
}					t_info;

int		read_draw_fdf(int fd);

t_grid	*get_grid(char *line, int row);
void	print_grid_array(t_grid **grid_head);
void	free_grid(t_grid **grid_head);

#endif
