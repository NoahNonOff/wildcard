/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:44:05 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/06/17 10:52:26 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*free_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return (NULL);
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*ret;

	i = -1;
	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	while (++i < len)
		ret[i] = s[i];
	ret[i] = 0;
	return (ret);
}

char	**tdtab_push(char **tab, char *to_add)
{
	int		len;
	char	**ret;

	len = 0;
	while (tab && tab[len])
		len++;
	ret = malloc(sizeof(char *) * (len + 2));
	if (!ret)
		return (NULL);
	len = 0;
	while (tab && tab[len])
	{
		ret[len] = ft_strdup(tab[len]);
		if (!ret[len++])
			return (free_tab(ret));
	}
	ret[len] = ft_strdup(to_add);
	if (!ret[len++])
		return (free_tab(ret));
	ret[len] = NULL;
	if (tab)
		free_tab(tab);
	return (ret);
}

char	*to_lower(char *str, char *ret)
{
	int	i;

	i = 0;
	while (str[i] && i < 256)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			ret[i] = str[i] + 32;
		else
			ret[i] = str[i];
		i++;
	}
	return (ret);
}
