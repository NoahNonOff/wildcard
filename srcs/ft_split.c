/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:26:34 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/06/12 11:37:04 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

static int	len_sep_string(const char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
		{
			counter++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (counter + 1);
}

static char	*get_next_word(int *index, const char *str, char c)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = 0;
	while (str[*index] == c)
		(*index)++;
	while (str[*index + len] != c && str[*index + len])
		len++;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < len)
		ret[i++] = str[(*index)++];
	ret[i] = 0;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		ac;
	char	**ret;

	i = 0;
	j = 0;
	ac = len_sep_string(s, c);
	ret = malloc(ac * sizeof(char *));
	if (!ret)
		return (NULL);
	while (i < ac - 1)
		ret[i++] = get_next_word(&j, s, c);
	ret[i] = NULL;
	return (ret);
}
