/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecarro <jdecarro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:02:22 by jdecarro          #+#    #+#             */
/*   Updated: 2024/10/02 11:02:22 by jdecarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1;
	size_t				i;

	s1 = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (s1[i] == (unsigned char) c)
		{
			return ((void *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	char	str[] = "Bonjour à tous!";

	printf("%p\n", ft_memchr(str, 'j', 15));
	return (0);
}
*/