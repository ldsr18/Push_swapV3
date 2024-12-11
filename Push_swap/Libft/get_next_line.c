/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecarro <jdecarro@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:20:40 by jdecarro          #+#    #+#             */
/*   Updated: 2024/10/22 17:20:40 by jdecarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char *s1, char *s2)
{
	char	*temp;

	if (!s1)
		s1 = ft_calloc_gnl(1, sizeof(char));
	if (!s2)
		s2 = ft_calloc_gnl(1, sizeof(char));
	temp = ft_strjoin_gnl(s1, s2);
	free(s1);
	return (temp);
}

char	*ft_extract_remainder(char *remainder)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	line = ft_calloc_gnl((ft_strlen_gnl(remainder) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (remainder[i])
		line[j++] = remainder[i++];
	free(remainder);
	return (line);
}

char	*ft_extract_line(char *remainder)
{
	int		i;
	char	*line;

	i = 0;
	if (!remainder[i])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		line = ft_calloc_gnl(i + 2, sizeof(char));
	else
		line = ft_calloc_gnl(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] && remainder[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *result)
{
	char	*data_read;
	int		byte_read;

	if (!result)
		result = ft_calloc_gnl(1, 1);
	data_read = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, data_read, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(data_read);
			if (result)
				free(result);
			return (NULL);
		}
		data_read[byte_read] = '\0';
		result = ft_free(result, data_read);
		if (ft_strchr_gnl(data_read, '\n'))
			break ;
	}
	free(data_read);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	buffer = ft_extract_remainder(buffer);
	return (line);
}
/*
#include <fcntl.h>

int main(void)
{
    int     fd;
    char    *line;

    // Ouvrir un fichier en lecture seule
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) 
	{
        perror("Error opening file");
        return (1);
    }

    printf("File opened successfully, fd: %d\n", fd);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Read line: %s", line);
        free(line); // Ne pas oublier de libérer chaque ligne lue
    }

    printf("Finished reading file.\n");

    // Fermer le fichier après lecture
    printf("Attempting to close file...\n");
    if (close(fd) == -1) {
        perror("Error closing file");
        return (1);
    } else {
        printf("File closed successfully.\n");
    }

    return (0);
}
*/