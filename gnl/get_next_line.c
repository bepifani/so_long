/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:38:47 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/12 19:21:40 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	a = malloc(count * size);
	if (a == 0)
		return (0);
	ft_bzero(a, count * size);
	return (a);
}

char	*ft_end_str_from_buff(char *str)
{
	char	*s;
	int		a;
	int		b;

	b = 0;
	a = 0;
	if (!str)
		return (NULL);
	while (str[a] != '\n' && str[a] != '\0')
		a++;
	if (!str[a++])
	{
		ft_freestr(str);
		return (NULL);
	}
	s = ft_calloc((ft_strlen(str) - a + 1), sizeof(char));
	if (!s)
		return (NULL);
	while (str[a] != '\0')
		s[b++] = str[a++];
	s[b] = '\0';
	ft_freestr(str);
	return (s);
}

char	*ft_one_str_to_n(char *str)
{
	char	*s;
	int		a;
	int		b;

	b = 0;
	a = 0;
	if (!str[a])
		return (NULL);
	while (str[a] != '\n' && str[a] != '\0')
		a++;
	s = ft_calloc((a + 2), sizeof(char));
	if (!s)
		return (NULL);
	while (str[b] != '\n' && str[b] != '\0')
	{
		s[b] = str[b];
		b++;
	}
	if (str[b] == '\n')
	{
		s[b] = str[b];
		b++;
		s[b] = '\0';
	}
	return (s);
}

char	*ft_readfile(int fd, char *str)
{
	char	*buff;
	int		simvol;

	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	simvol = 1;
	while (!ft_strchr(str, '\n') && simvol >= 0)
	{
		simvol = read (fd, buff, BUFFER_SIZE);
		if (simvol < 0)
		{
			ft_freestr(buff);
			return (NULL);
		}
		if (ft_strlen(buff) == 0 && simvol <= 1)
		{
			free (buff);
			return (str);
		}
		buff[simvol] = '\0';
		str = ft_strjoinn(str, buff);
	}
	ft_freestr(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buf1;
	static char	*buf2;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buf2 = ft_readfile(fd, buf2);
	if (buf2 == NULL)
		return (NULL);
	buf1 = ft_one_str_to_n(buf2);
	buf2 = ft_end_str_from_buff(buf2);
	// if (buf1)
	// 	write(1, buf1, ft_strlen(buf1));
	// write(1, "\n", 1);
	// write(1, "\n", 1);
	return (buf1);
}