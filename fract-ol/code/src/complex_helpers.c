#include "complex_helpers.h"
#include "fractol.h"

void	initComplex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}
