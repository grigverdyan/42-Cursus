#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int ft_printf(char *str, ...);
size_t	print_specifier(const char c, va_list ap);
size_t	ft_putnbr_base(ssize_t nbr, char *base, size_t len, char specifier);
void	print_base(ssize_t num, char *base, size_t len, size_t *count);
size_t	ft_putchar(const char c);
size_t	ft_putstr(const char *str);
char	*ft_strchr(const char *s, int c);

int main()
{
    ft_printf("%s\n", "toto");
    ft_printf("Magic %s is %d\n", "number", 42);
    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}

int ft_printf(char *str, ...)
{
    va_list	ap;
	size_t	i = -1;
	size_t	count = 0;
	char	*specifiers = "sdx";

	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%' && ft_strchr(specifiers, str[i + 1]))
			count += print_specifier(str[i + 1], ap);
		else
			count += ft_putchar(str[i]);
	}
	va_end(ap);
	return (count);
}

size_t	print_specifier(const char c, va_list ap)
{
	size_t	count = 0;
	char	*lower_hex = "0123456789abcdef";
	if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'd')
		count += ft_putnbr_base(va_arg(ap, int), "0123456789", 10, c);
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(ap, unsigned int), lower_hex, 16, c);
	return (count);
}

size_t	ft_putnbr_base(ssize_t nbr, char *base, size_t len, char specifier)
{
	size_t	count = 0;
	if (specifier == 'd')
	{
		if (nbr < 0)
		{
			count += ft_putchar('-');
			nbr *= -1;
		}
		print_base(nbr, base, len, &count);
	}
	else if (specifier == 'x')
		print_base(nbr, base, len, &count);
	return (count);
}

void	print_base(ssize_t num, char *base, size_t len, size_t *count)
{
	char		str[20];
	size_t		rem;
	size_t		i = 0;

	if (num == 0)
		*count += ft_putchar(base[0]);
	while (num != 0)
	{
		rem = num % len;
		str[i] = base[rem];
		++i;
		num = num / len;
	}
	while (i-- > 0)
		*count += ft_putchar(str[i]);
}
    
size_t	ft_putchar(const char c)
{
	write (1, &c, 1);
	return (1);
}

size_t	ft_putstr(const char *str)
{
	size_t	i = -1;

	if (!str)
		return (ft_putstr("(null)"));
	while (str[++i])
		write (1, &str[i], 1);
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i = -1;

	while (s[++i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}
