/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 04:01:55 by gverdyan          #+#    #+#             */
/*   Updated: 2022/04/16 02:50:35 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static void	ft_reverse(char *str)
{
	size_t	i;
	size_t	len;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

char	*ft_dec_to_hex(uintptr_t n, size_t size)
{
	char	*base;
	char	*hex;
	size_t	i;

	i = 0;
	hex = (char *)malloc(size * sizeof(char));
	base = "0123456789abcdef";
	if (n == 0)
	{
		hex[0] = base[0];
		hex[1] = '\0';
		return (hex);
	}
	while (n)
	{
		if (n > 15)
			hex[i++] = base[n % 16];
		else
			hex[i++] = base[n];
		n /= 16;
	}
	hex[i] = '\0';
	ft_reverse(hex);
	return (hex);
}
