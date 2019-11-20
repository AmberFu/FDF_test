/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:32:39 by pfu               #+#    #+#             */
/*   Updated: 2019/11/19 22:15:27 by pfu              ###   ########.fr       */
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
	char			**arr;
	struct s_grid	*next;
}					t_grid;

typedef struct		s_info
{
	int				x;
	int				y;
}					t_info;

void    read_draw_fdf(int fd);

t_grid  *get_xy(char *line, int row);
void    print_arr(char **arr);
void    print_grid_array(t_grid **grid_head);


#endif
