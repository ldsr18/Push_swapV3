/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecarro <jdecarro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:12:56 by jdecarro          #+#    #+#             */
/*   Updated: 2024/09/28 10:12:56 by jdecarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main()
{
	char	src[] = "Bonjour";
	char	dest[50];
	printf("%s\n", src);
	printf("%s\n", dest);
	printf("%s\n", ft_strcpy(dest, src));
	printf("%s\n", src);
	printf("%s\n", dest);
	return (0);
}
*/