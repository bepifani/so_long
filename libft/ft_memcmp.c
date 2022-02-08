/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:29:25 by bepifani          #+#    #+#             */
/*   Updated: 2021/10/05 19:43:24 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a1;
	const unsigned char	*a2;

	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*a1 != *a2)
			return (*a1 - *a2);
		a1++;
		a2++;
		n--;
	}
	return (0);
}
