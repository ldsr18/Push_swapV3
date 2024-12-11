/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecarro <jdecarro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:19:21 by jdecarro          #+#    #+#             */
/*   Updated: 2024/10/02 16:19:21 by jdecarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
/*
int	main()
{
	char	str[] = "Bonjour tout le monde!";
	char	c = 'l';

	printf("%p\n", ft_strrchr(str, c));
	printf("%s\n", ft_strrchr(str, c));
	return (0);
}
*/