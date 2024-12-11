/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecarro <jdecarro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:29:52 by jdecarro          #+#    #+#             */
/*   Updated: 2024/10/04 13:29:52 by jdecarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words_count(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static size_t	ft_words_len(const char *str, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] && str[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	*ft_alloc_word(const char *s, char c)
{
	char	*word;
	size_t	word_len;
	size_t	i;

	word_len = ft_words_len(s, c);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		word[i] = *s++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_split(char **split, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	i;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_words_count(s, c);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		split[i] = ft_alloc_word(s, c);
		if (!split[i])
			return (ft_free_split(split, i), NULL);
		while (*s && *s != c)
			s++;
		i++;
	}
	split[i] = NULL;
	return (split);
}
/*
int	main()
{
	char	str[] = " Bonjour   tout le   monde   ";
	char	delim = ' ';
	char	**result = ft_split(str, delim);
	int	i = 0;

	while (result[i])
	{
		printf("%s\n", result[i]);
		free(result[i]); // free de chaque mot
		i++;
	}
	free(result); // free du tableau
	return (0);
}
*/