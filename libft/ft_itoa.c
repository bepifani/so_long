/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:56:23 by bepifani          #+#    #+#             */
/*   Updated: 2021/10/11 18:05:59 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_number(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_nb(long n, char *str, int *i)
{
	if (n > 9)
	{
		ft_nb((n / 10), str, i);
		ft_nb((n % 10), str, i);
	}
	else
		str[(*i)++] = n + '0';
}

char	*ft_itoa(int a)
{
	char	*str;
	int		i;
	long	n;

	n = a;
	str = (char *)malloc(sizeof(char) * ((ft_number(n)) + 2));
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = n * -1;
	}
	ft_nb(n, str, &i);
	str[i] = '\0';
	return (str);
}
