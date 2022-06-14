#include "mlx.h"
#include "fractol.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();

	win = mlx_new_window(mlx, WIDTH, HEIGHT, "fractol");
	printImage(mlx, win);
	mlx_loop(mlx);
}

void	printImage(void *mlx, void *win)
{
	int	i;
	int	j;
	
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			mlx_pixel_put(mlx, win, i, j, 0xABCDEF);
		}
	}
}
