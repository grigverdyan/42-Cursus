#include <unistd.h>
#include <stdarg.h>
#include "stdio.h"

void	ft_put_number(long digits, int length, char *sign, int *g_var);
void	ft_put_hexadecimal(unsigned digits, unsigned length, char *sign, int *g_var);
int	ft_printf(const char *format, ...);

int main()
{
    printf("%d\n", ft_printf("%x", 42));
}

int	ft_printf(const char *format, ...)
{
	int g_var = 0;
	va_list ap;
	va_start(ap, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				int	 length = 0;
				char *string = va_arg(ap, char *);
				if (!string)
					string = "(null)";
				while (string[length])
					length++;
				g_var += length;
				write(1, string, length);
			}
			else if (*format == 'd')
			{
				long long decimal = va_arg(ap, int);
				if (decimal < 0)
				{
					write(1, "-", 1);
					g_var++;
					decimal *= -1;
				}
				ft_put_number(decimal, 10, "0123456789", &g_var);
			}
			else if (*format == 'x')
			{
				int hexadecimal = va_arg(ap, int);
				ft_put_hexadecimal(hexadecimal, 16, "0123456789abcdef", &g_var);
			}
			format++;
		}
		else
			g_var += write(1, format++, 1);
	}
	va_end(ap);
	return (g_var);
}

void	ft_put_number(long digits, int length, char *sign, int *g_var)
{
	if (digits >= length)
		ft_put_number(digits / length, length, sign, g_var);
	write(1, &sign[digits % length], 1);
	(*g_var) += 1;
}

void	ft_put_hexadecimal(unsigned digits, unsigned length, char *sign, int *g_var)
{
	if (digits >= length)
		ft_put_hexadecimal(digits / length, length, sign, g_var);
	write(1, &sign[digits % length], 1);
	(*g_var) += 1;
}
