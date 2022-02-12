/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:39:08 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/12 19:22:16 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return ((size_t) NULL);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*a;
	char	b;

	if (s == NULL)
		return (NULL);
	a = (char *)s;
	b = (char)c;
	while (*a)
	{
		if (*a == b)
			return (a);
		a++;
	}
	if (*a == b)
		return (a);
	return (NULL);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)ft_calloc(1, sizeof(char));
		s1[j] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	ft_freestr(s1);
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n > 0)
	{
		*str = '\0';
		n--;
		str++;
	}
	return (*s);
}

void	ft_freestr(char *str)
{
	if (str)
		free(str);
	str = NULL;
}