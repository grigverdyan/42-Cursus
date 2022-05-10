/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:31:49 by gverdyan          #+#    #+#             */
/*   Updated: 2022/04/16 19:28:43 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
size_t	ft_char_specifier(const char *str, size_t idx, va_list ap);
size_t	ft_int_specifier(const char *str, size_t idx, va_list ap);
size_t	ft_hex_specifier(const char *str, size_t idx, va_list ap);
size_t	ft_specifier(const char *str, size_t idx, va_list ap);
size_t	ft_pointer_specifier(va_list ap);
char	*ft_dec_to_hex(uintptr_t n, size_t size);

#endif
