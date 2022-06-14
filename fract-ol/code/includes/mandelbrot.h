#ifndef MANDELBROT_FRACTAL_H
# define MANDELBROT_FRACTAL_H

void	mandelbrotSet(void);
void	mandelbrot(t_complex min, t_complex max, t_complex factor, int max_itaeration);
void	colors(int iteration, int max_iteration);

#endif	/* MANDELBROT_FRACTAL_H */
