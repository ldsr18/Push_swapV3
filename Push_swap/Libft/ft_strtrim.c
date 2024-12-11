/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecarro <jdecarro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:23:33 by jdecarro          #+#    #+#             */
/*   Updated: 2024/10/04 10:23:33 by jdecarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && check_set(s1[start], set))
		start++;
	while (end > start && check_set(s1[end - 1], set))
		end--;
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}
/*
int	main()
{
	char	s1[] = "  	Bonjour tout le monde!	 	";
	char	set[] = " \t\n";
	char	*result;

	result = ft_strtrim(s1, set);
	printf("Chaîne originale = %s\n", s1);
	printf("Résultat = %s\n", result);
	free(result);
	return (0);
}
*/