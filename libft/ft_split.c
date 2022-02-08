/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:03:02 by bepifani          #+#    #+#             */
/*   Updated: 2021/10/11 18:03:37 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_chaek(char **str)
{
	unsigned int	a;

	a = 0;
	while (str[a])
	{
		free(str[a]);
		a++;
	}
	free(str);
	return (NULL);
}

static unsigned int	ft_find_str(char const *s, char c)
{
	unsigned int	i;
	unsigned int	strs;

	i = 0;
	strs = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		strs++;
	return (strs);
}

static void	ft_next(char **next, unsigned int *next_s, char c)
{
	unsigned int	i;

	i = 0;
	*next = *next + *next_s;
	*next_s = 0;
	while (**next && **next == c)
		(*next)++;
	while ((*next)[i])
	{
		if ((*next)[i] == c)
			return ;
		(*next_s)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next;
	unsigned int	next_s;
	unsigned int	nb;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	nb = ft_find_str(s, c);
	tab = malloc(sizeof(char *) * (nb + 1));
	if (!tab)
		return (NULL);
	i = 0;
	next = (char *)s;
	next_s = 0;
	while (i < nb)
	{
		ft_next(&next, &next_s, c);
		tab[i] = malloc(sizeof(char) * (next_s + 1));
		if (!tab[i])
			return (ft_malloc_chaek(tab));
		ft_strlcpy(tab[i++], next, next_s + 1);
	}
	tab[i] = NULL;
	return (tab);
}
