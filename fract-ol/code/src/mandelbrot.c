#include "mandelbrot.h"
#include "fractol.h"
#include "complex_helpers.h"
#include <math.h>

void	mandelbrotSet(void)
{
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	int			max_ieration;

	min = initComplex(-2.0, -2.0);
	max.re = 2.0;
	max.im = min.im + HEIGHT / WIDTH * (max.re - min.re);
	factor = initComplex(
			(max.re - min.re) / (WIDTH - 1),
			(max.im - min.im) / (HEIGHT - 1));
	max_iteration = 256;
	mandelbrot(min, max, factor, max_iteration);
	
}

void	mandelbrot(t_complex min, t_complex max, t_complex factor, int max_iter)
{
	int			iter;
	int			x;
	int			y;
	t_complex	z;
	t_complex	c;

	y = -1;
	while (++y < HEIGHT)
	{
		c.im = max.im - y * factor.im;
		x = -1;
		while  (x < WIDTH)
		{
			c.re = min.re + x * factor.re;
			z = initComplex(c.re, c.im);
			iteration = 0;
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iter < max_iter)
			{
				z = initComplex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
						z.re * z.im * c.im * 2.0);
				iteration++;
			}
			colors(iter, mx_iter);
		}
	}
}

void	colors(int iter, int max_iter)
{
	double	t;
	double	red;
	double	green;
	double	blue;

	t = (double)iter / (double)max_iter;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
}
