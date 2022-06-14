#ifndef	FRACTOL_H
# define FRACTOL_H

# define HEIGHT	800
# define WIDTH	800

typedef struct	s_complex
{
	double re;
	double im;
}	t_complex;

void	printImage(void *mlx, void *win);

#endif	/* FRACTOL_H */
