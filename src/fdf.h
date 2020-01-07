/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:32:39 by pfu               #+#    #+#             */
/*   Updated: 2019/12/17 21:12:32 by pfu              ###   ########.fr       */
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
	char			*arr; //number string
	struct s_grid	*next;
}					t_grid;

typedef	struct		s_3d_point
{
	int				x;
	int				y;
	int				z;
}					t_3d_point;

// x' = x / (z + 1)
// y' = y / (z + 1)
typedef struct 		s_new_2d
{
	double			x;
	double			y;
};

typedef struct		s_info
{
	int				rows;
	int				cols;
	int				max_z;
	int				min_z;
	int				win_h;
	int				win_w;
	t_3d_point			**ori_xyz_3d; // 2D array of t_point
}					t_info;

//int					read_draw_fdf(int fd, t_info **info);
int					read_draw_fdf(int fd);
t_grid				*get_grid(char *line, int row);
void				print_grid_array(t_grid *grid_head);
void				free_grid(t_grid **grid_head);

t_info  *create_info_struct(void);
void    print_info(t_info *info);

#endif
