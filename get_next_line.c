/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamonal <jgamonal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:34:55 by jgamonal          #+#    #+#             */
/*   Updated: 2023/04/10 14:54:28 by jgamonal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** this function checks if backup has a '\n'.
** If yes returns 1, if not returns 2
*/

static int	ft_backup_check(char *backup)
{
	int	i;

	i = 0;
	while (backup[i] != 0)
	{
		if (backup[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_copy_line(char *backup)
{
	char	*line;
	int		i;

	i = 0;
	while (backup[i] != '\n')
		i++;
	line = (char *)malloc(i * sizeof(char) + 2);
	i = 0;
	while (backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

static char	*ft_clean_backup(char *backup)
{
	char	*clean_backup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (backup[i] != '\n')
		i++;
	clean_backup = (char *) malloc((ft_strlen(backup) - i) * sizeof(char));
	while (backup[i] != '\0')
	{
		clean_backup[j] = backup[i + 1];
		j++;
		i++;
	}
	clean_backup[j + 1] = '\0';
	return (clean_backup);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*backup = "";
	char		*line;
	int			i;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + sizeof(char) + 1);
	if (!buf)
		return (NULL);
	i = read(fd, buf, BUFFER_SIZE);
	if (i == -1)
		return (NULL);
	backup = ft_strjoin(backup, buf);
	if (backup[0] == 0)
		return (backup);
	while (ft_backup_check(backup) != 1)
	{
		read(fd, buf, BUFFER_SIZE);
		backup = ft_strjoin(backup, buf);
	}
	line = ft_copy_line(backup);
	backup = ft_clean_backup(backup);
	free(buf);
	return (line);
}
