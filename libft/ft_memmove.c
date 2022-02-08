/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:13:11 by bepifani          #+#    #+#             */
/*   Updated: 2021/10/11 13:53:47 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*ld;
	unsigned char	*ls;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (d < s)
	{
		while (len > 0)
		{
			*d++ = *s++;
			len--;
		}
	}
	else
	{
		ls = s + (len - 1);
		ld = d + (len - 1);
		while (len--)
			*ld-- = *ls--;
	}
	return (dest);
}
