#include "mlx.h"

void	print_img(void *mlx, void *win)
{
	int	i;
	int	j;
	//int	x = 0;
	//int	y = 0;
	i = -1;
	while (++i < 800)
	{
		j = -1;
		while (++j < 800)
		{
			mlx_pixel_put(mlx, win, i, j, 0xABCDEF);
		}
	}
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();



	win = mlx_new_window(mlx, 800, 800, "fractol");
	print_img(mlx, win);
	mlx_loop(mlx);
}

