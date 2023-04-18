/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamonal <jgamonal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:50:44 by jgamonal          #+#    #+#             */
/*   Updated: 2023/04/18 10:14:16 by jgamonal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Checs if there is '\n' in backup string.
** if yes returns 1, if not returns 0.
*/

static int	find_line(char *backup)
{
	int	i;

	i = 0;
	if (backup == NULL)
		return (0);
	while (backup[i] != '\0')
	{
		if (backup[i] == '\n')
			return (1);
	i++;
	}
	return (0);
}

/*
** Uses read to add character to the static char *backup
*/

static char	*read_and_backup(int fd, char *backup)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (find_line(backup) == 0 && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			backup = ft_strjoin(backup, buffer);
		}
		if (bytes_read == -1)
		{
			free(backup);
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (backup);
}

/*
** Extract all character form backup and prepare line to return.
** Stops when '\n' is founds
*/

static char	*extract_line(char *backup)
{
	int		i;
	char	*line;

	i = 0;
	if (!backup || backup[0] == '\0')
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	line = (char *)malloc(i * sizeof(char) + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*
** Clean backup deleting all the character psssed to line
*/

static char	*clean_backup(char *backup)
{
	char	*clean_backup;
	int		i;
	int		j;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	if (!backup[i])
		return (NULL);
	clean_backup = (char *) malloc(sizeof (char) * (ft_strlen(backup) - i) + 1);
	if (!clean_backup)
		return (NULL);
	i++;
	j = 0;
	while (backup[i])
		clean_backup[j++] = backup[i++];
	clean_backup[j] = '\0';
	free(backup);
	return (clean_backup);
}

/*
** This function read nbytes (given by BUFFER_SIZE) of a text passed.
** The text is passed by its fd (file directory).
** If all is ok it returns a char* of the line.
** If nothing is read or if it has an error, it returns NULL.
*/

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_and_backup(fd, backup);
	if (backup == NULL)
		return (NULL);
	line = extract_line(backup);
	backup = clean_backup(backup);
	return (line);
}
