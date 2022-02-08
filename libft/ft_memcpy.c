/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:52:34 by bepifani          #+#    #+#             */
/*   Updated: 2021/10/11 13:50:10 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	if (len && src == NULL && dest == NULL)
		return (NULL);
	while (len)
	{
		*a++ = *b++;
		len--;
	}
	return (dest);
}
