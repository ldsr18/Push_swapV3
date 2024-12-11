/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecarro <jdecarro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:24:27 by jdecarro          #+#    #+#             */
/*   Updated: 2024/10/17 18:24:27 by jdecarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_printf(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr_printf(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar_printf(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_printf(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_putstr_printf("-2147483648");
		return (count);
	}
	if (nb < 0)
	{
		count += ft_putchar_printf('-');
		nb = -nb;
	}
	if (nb > 9)
		count += ft_putnbr_printf(nb / 10);
	count += ft_putchar_printf((nb % 10) + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += ft_putnbr_unsigned(nb / 10);
	count += ft_putchar_printf((nb % 10) + '0');
	return (count);
}

int	ft_putnbr_hex(unsigned int nb, int uppercase)
{
	int		count;
	char	*base;

	count = 0;
	if (uppercase)
		base = ("0123456789ABCDEF");
	else
		base = ("0123456789abcdef");
	if (nb >= 16)
		count += ft_putnbr_hex(nb / 16, uppercase);
	count += ft_putchar_printf(base[nb % 16]);
	return (count);
}
