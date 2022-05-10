/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 04:02:12 by gverdyan          #+#    #+#             */
/*   Updated: 2022/04/16 02:50:03 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_specifier(const char *str, size_t idx, va_list ap)
{
	size_t	cnt;

	cnt = 0;
	if (str[idx] == '%' || str[idx] == 'c' || str[idx] == 's')
		cnt += ft_char_specifier(str, idx, ap);
	else if (str[idx] == 'i' || str[idx] == 'd' || str[idx] == 'u')
		cnt += ft_int_specifier(str, idx, ap);
	else if (str[idx] == 'x' || str[idx] == 'X')
		cnt += ft_hex_specifier(str, idx, ap);
	else if (str[idx] == 'p')
		cnt += ft_pointer_specifier(ap);
	return (cnt);
}

size_t	ft_char_specifier(const char *str, size_t idx, va_list ap)
{
	char	*ptr;

	ptr = NULL;
	if (str[idx] == '%')
	{
		ft_putchar_fd(str[idx], 1);
		return (1);
	}
	else if (str[idx] == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		return (1);
	}
	else if (str[idx] == 's')
	{
		ptr = va_arg(ap, char *);
		if (ptr == NULL)
		{
			ft_putstr_fd("(null)", 1);
			return (ft_strlen("(null)"));
		}
		ft_putstr_fd(ptr, 1);
		return (ft_strlen(ptr));
	}
	return (0);
}

size_t	ft_int_specifier(const char *str, size_t idx, va_list ap)
{
	char			*chr_num;
	int				num;
	unsigned int	u_num;

	num = 0;
	if (str[idx] != 'u')
	{
		num = va_arg(ap, int);
		chr_num = ft_itoa(num);
		ft_putnbr_fd(num, 1);
	}
	else
	{
		u_num = va_arg(ap, unsigned int);
		chr_num = ft_uitoa(u_num);
		ft_uputnbr_fd(u_num, 1);
	}
	u_num = ft_strlen(chr_num);
	free(chr_num);
	return (u_num);
}

size_t	ft_hex_specifier(const char *str, size_t idx, va_list ap)
{
	char			*ptr;
	unsigned int	num;
	size_t			len;

	num = va_arg(ap, long int);
	ptr = ft_dec_to_hex(num, 1000);
	len = ft_strlen(ptr);
	if (str[idx] == 'x')
		ft_putstr_fd(ptr, 1);
	else
	{
		ft_strupper(ptr);
		ft_putstr_fd(ptr, 1);
	}
	free(ptr);
	return (len);
}

size_t	ft_pointer_specifier(va_list ap)
{
	uintptr_t	num;
	char		*ptr;
	size_t		len;

	num = va_arg(ap, uintptr_t);
	len = 0;
	ptr = ft_dec_to_hex(num, 1000);
	len = ft_strlen(ptr) + 2;
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(ptr, 1);
	free(ptr);
	return (len);
}
