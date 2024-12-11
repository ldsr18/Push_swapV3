/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecarro <jdecarro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:38:03 by jdecarro          #+#    #+#             */
/*   Updated: 2024/10/02 12:38:03 by jdecarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src1;
	const unsigned char	*src2;
	size_t				i;

	src1 = s1;
	src2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (src1[i] == src2[i] && i < n - 1)
		i++;
	return (src1[i] - src2[i]);
}
/*
int	main()
{
	char	str[10] = "Bonjour!";
	char	str1[10] = "Bonjour!";
	char	str2[10] = "Bon";
	char	str3[10] = "jour!";

	printf("%d\n", ft_memcmp(str, str1, 10));
	printf("%d\n", ft_memcmp(str, str3, 10));
	printf("%d\n", ft_memcmp(str, str2, 10));
	printf("%d\n", ft_memcmp(str2, str3, 10));
	return (0);
}
*/