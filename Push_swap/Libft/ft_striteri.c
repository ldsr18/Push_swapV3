/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecarro <jdecarro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:38:05 by jdecarro          #+#    #+#             */
/*   Updated: 2024/10/07 09:38:05 by jdecarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	ft_my_test(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c -= 32;
}

int	main()
{
	char	str[] = "abcdef";

	ft_striteri(str, ft_my_test);
	printf("%s\n", str);
	return (0);
}
*/