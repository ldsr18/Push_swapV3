/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecarro <jdecarro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:16:31 by jdecarro          #+#    #+#             */
/*   Updated: 2024/10/07 09:16:31 by jdecarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
char	ft_my_test(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c - 32);
	return (c);
}

int	main()
{
	char	*str = "abcdefg";
	char	*result;

	result = ft_strmapi(str, ft_my_test);
	printf("Result = %s\n", result);
	free(result);
	return (0);
}
*/