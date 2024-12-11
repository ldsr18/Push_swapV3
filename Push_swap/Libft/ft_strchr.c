/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecarro <jdecarro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:17:53 by jdecarro          #+#    #+#             */
/*   Updated: 2024/10/02 15:17:53 by jdecarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	letter;

	i = 0;
	letter = (char) c;
	while (s[i])
	{
		if (s[i] == letter)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (letter == '\0' || s == NULL)
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main()
{
	char	str[] = "Teste";
	char	c = 'e';

	printf("%p\n", ft_strchr(str, c));
	printf("%s\n", ft_strchr(str, c));
	return (0);
}
*/
