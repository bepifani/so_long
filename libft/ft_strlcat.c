/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:34:29 by bepifani          #+#    #+#             */
/*   Updated: 2021/10/09 15:56:05 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t siz)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dlen;

	d = (char *)dest;
	s = (char *)src;
	n = siz;
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dest;
	n = siz - dlen;
	if (n == 0)
		return (dlen + (ft_strlen((char *)s)));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
