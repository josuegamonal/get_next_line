/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamonal <jgamonal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:41:28 by jgamonal          #+#    #+#             */
/*   Updated: 2023/04/10 09:05:11 by jgamonal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s1copy;
	int		i;

	i = 0;
	s1copy = (char *) malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!(s1copy))
		return (NULL);
	while (*s1)
	{
		s1copy[i++] = *s1++;
	}
	s1copy[i] = '\0';
	return (s1copy);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static void	ft_copy_all(char const *s1, char const *s2, char *s3)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
	{
		s3[j] = s2[i];
		i++;
		j++;
	}
	s3[j] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		len;

	if (!(s1) || !(s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *) malloc(sizeof(char) * (len + 1));
	if (!(s3))
		return (NULL);
	ft_copy_all(s1, s2, s3);
	return (s3);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}



