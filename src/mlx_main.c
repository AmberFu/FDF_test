/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:01:44 by pfu               #+#    #+#             */
/*   Updated: 2019/11/27 21:20:47 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compile with this command: 
 * => gcc mlx_main.c -L ../minilibx_macos -lmlx -L ../libft -lft -framework OpenGL -framework AppKit
 * */

#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"

int		test_fun(int key, void *para)
{
	ft_putstr("key = ");
	ft_putnbr(key);
	ft_putchar('\n');
	return (0);
}

int		mouse_test(int button, int x, int y, void *param)
{
	// button 1: left
	// button 2: right
	// button 3: two sides & push middle
	// button 4: middle forward
	// button 5: middle backward
	ft_putstr("button = ");
	ft_putnbr(button);
	ft_putstr(", x = ");
	ft_putnbr(x);
	ft_putstr(", y = ");
	ft_putnbr(y);
	ft_putchar('\n');
	return (0);
}

int		main()
{
	int		size_x;
	int		size_y;
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;

	size_x = 500;
	size_y = 500;
	x = -1;
	y = 501;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, "FDF");
	while (++x < size_x && --y > 0)
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 255);
	mlx_string_put(mlx_ptr, win_ptr, 100, 100, 0x00FF7F, "Hi!"); //For color: 0x + #RRGGBB
	mlx_key_hook(win_ptr, test_fun, (void *)0);
	mlx_mouse_hook(win_ptr, mouse_test, (void *)0);
	//mlx_expose_hook(win_ptr, expose_test, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
