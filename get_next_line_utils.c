/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamonal <jgamonal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:07:42 by jgamonal          #+#    #+#             */
/*   Updated: 2023/04/18 10:32:38 by jgamonal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	char	*s2;

	s2 = (char *)s;
	c = c % 256;
	while (*s2 != c)
	{
		if (*s2 == '\0')
		{
			return (0);
		}
		s2++;
	}
	return (1);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!(s1))
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * ((ft_strlen(s1)) + (ft_strlen(s2)) + 1));
	if (!(s3))
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			s3[i] = s1[i];
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (s3);
}
