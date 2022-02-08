/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:37:34 by bepifani          #+#    #+#             */
/*   Updated: 2021/10/10 14:51:07 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	size_t	l;
	size_t	i;
	size_t	j;

	hay = (char *)haystack;
	l = ft_strlen(needle);
	if (!l)
		return (hay);
	if (ft_strlen(haystack) < l || len < l)
		return (NULL);
	i = 0;
	while (hay[i] && i <= len - l)
	{
		j = 0;
		while (needle[j] && needle[j] == hay[i + j])
			j++;
		if (j == l)
		{
			return (&hay[i]);
		}
		i++;
	}
	return (NULL);
}
