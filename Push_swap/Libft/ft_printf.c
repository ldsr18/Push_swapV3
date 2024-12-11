/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecarro <jdecarro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:46:45 by jdecarro          #+#    #+#             */
/*   Updated: 2024/10/15 16:46:45 by jdecarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(uintptr_t nb)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		count += ft_putchar_printf('0');
		return (count);
	}
	if (nb >= 16)
		count += ft_putptr(nb / 16);
	count += ft_putchar_printf("0123456789abcdef"[nb % 16]);
	return (count);
}

int	ft_format(va_list arg, const char format)
{
	int	result;

	result = 0;
	if (format == 'c')
		result += ft_putchar_printf(va_arg(arg, int));
	else if (format == 's')
		result += ft_putstr_printf(va_arg(arg, char *));
	else if (format == 'p')
	{
		result += ft_putstr_printf("0x");
		result += ft_putptr((uintptr_t)va_arg(arg, void *));
	}
	else if (format == 'd' || format == 'i')
		result += ft_putnbr_printf(va_arg(arg, int));
	else if (format == 'u')
		result += ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (format == 'x')
		result += ft_putnbr_hex(va_arg(arg, unsigned int), 0);
	else if (format == 'X')
		result += ft_putnbr_hex(va_arg(arg, unsigned int), 1);
	else if (format == '%')
		result += ft_putchar_printf('%');
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		result;
	int		i;

	result = 0;
	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			result += ft_format(arg, format[i + 1]);
			i++;
		}
		else
			result += ft_putchar_printf(format[i]);
		i++;
	}
	va_end(arg);
	return (result);
}
/*
#include <stdio.h>

int	main(void)

{
	int		count;
	int		nb = -1;
	char	*str = "Hello, world!";
	void	*ptr = &nb;

	count = ft_printf("Character: %c\n", 'A');
	ft_printf("Printed %d characters\n", count);
	count = printf("Character: %c\n", 'A');
	printf("Printed %d characters\n\n", count);

	count = ft_printf("String: %s\n", str);
	ft_printf("Printed %d characters\n", count);
	count = printf("String: %s\n", str);
	printf("Printed %d characters\n\n", count);

	count = ft_printf("Pointer: %p\n", ptr);
	ft_printf("Printed %d characters\n", count);
	count = printf("Pointer: %p\n", ptr);
	printf("Printed %d characters\n\n", count);

	count = ft_printf("Decimal: %d\n", 12345);
	ft_printf("Printed %d characters\n", count);
	count = printf("Decimal: %d\n", 12345);
	printf("Printed %d characters\n\n", count);

	count = ft_printf("Unsigned: %u\n", 4294967295U);
	ft_printf("Printed %d characters\n", count);
	count = printf("Unsigned: %u\n", 4294967295U);
	printf("Printed %d characters\n\n", count);

	count = ft_printf("Hex lowercase: %x\n", 255);
	ft_printf("Printed %d characters\n", count);
	count = printf("Hex lowercase: %x\n", 255);
	printf("Printed %d characters\n\n", count);

	count = ft_printf("Hex uppercase: %X\n", 255);
	ft_printf("Printed %d characters\n", count);
	count = printf("Hex uppercase: %X\n", 255);
	printf("Printed %d characters\n\n", count);

	count = ft_printf("Percent: %%\n");
	ft_printf("Printed %d characters\n", count);
	count = printf("Percent: %%\n");
	printf("Printed %d characters\n\n", count);

	return (0);
}
*/