/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 04:02:03 by gverdyan          #+#    #+#             */
/*   Updated: 2022/04/16 03:05:23 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	idx;
	size_t	char_cnt;
	void	*ptr;

	ptr = NULL;
	idx = -1;
	char_cnt = 0;
	va_start(ap, str);
	while (str[++idx])
	{
		if (str[idx] == '%')
		{
			idx++;
			if (ft_strchr("cspdiuxX%", str[idx]))
				char_cnt += ft_specifier(str, idx, ap);
		}
		else
		{
			ft_putchar_fd(str[idx], 1);
			++char_cnt;
		}
	}
	va_end(ap);
	return (char_cnt);
}
