/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:00:21 by bepifani          #+#    #+#             */
/*   Updated: 2021/10/09 19:39:47 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*a;
	char	b;

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
