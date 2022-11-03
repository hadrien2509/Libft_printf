/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeissle <hgeissle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:06:34 by hgeissle          #+#    #+#             */
/*   Updated: 2022/11/03 12:59:05 by hgeissle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkformat(const char c, va_list ap)
{
	if (c == 'c')
		return (ft_printchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_printstr(va_arg(ap, char *)));
	if (c == 'd' || c == 'i')
		return (ft_printnbr(va_arg(ap, int), "0123456789", 10));
	if (c == 'u')
		return (ft_printunbr(va_arg(ap, unsigned int), "0123456789", 10));
	if (c == 'x')
		return (ft_printunbr(va_arg(ap, unsigned int), "0123456789abcdef", 16));
	if (c == 'X')
		return (ft_printunbr(va_arg(ap, unsigned int), "0123456789ABCDEF", 16));
	if (c == 'p')
		return (ft_printptr(va_arg(ap, unsigned long int)));
	return (ft_printchar(c));
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	size_t		i;
	int			len;
	int			old_len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		old_len = len;
		if (str[i] == '%')
		{	
			i++;
			len += ft_checkformat(str[i], ap);
		}
		else
			len += write(1, &str[i], 1);
		i++;
		if (len == old_len - 1)
			return (-1);
	}
	va_end(ap);
	return (len);
}
