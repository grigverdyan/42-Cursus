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

