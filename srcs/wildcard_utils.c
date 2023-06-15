/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:13:37 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/06/15 23:33:59 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

int	tdtab_len(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

char	*sub_string(char *str, int start, int end)
{
	int		idx;
	int		len;
	char	*ret;

	idx = -1;
	len = end - start;
	ret = malloc(sizeof(char) * len + 2);
	if (!ret)
		return (NULL);
	while (++idx < len)
		ret[idx] = str[start++];
	ret[idx] = 0;
	return (ret);
}

int	modified_twild(t_wild *inf, int i)
{
	if (inf->sep[i] == INT_MIN)
	{
		inf->sep[i] = 0;
		return (0);
	}
	if (inf->sep[i] < 1)
	{
		inf->sep[i] *= -1;
		return (1);
	}
	if (inf->sep[i] > 0)
		return (0);
	return (0);
}

t_wild	wild_struct_init(int *sep, int sep_size, char **pattern, char *str)
{
	t_wild	ret;

	ret.sep = sep;
	ret.sep_size = sep_size;
	ret.pattern = pattern;
	ret.str = str;
	ret.wild = 0;
	return (ret);
}

int	comp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	i = 0;
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while ((t1[i] && t2[i]) && (t1[i] == t2[i]))
		i++;
	return (t1[i] - t2[i]);
}
