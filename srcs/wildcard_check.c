/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:41:19 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/06/15 23:31:38 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

int	wildcard_check(char *str, char *cmp)
{
	int		ret;
	int		*sep;
	int		sep_size;
	char	**pattern;

	ret = 0;
	sep_size = 0;
	pattern = extract_pattern(str, NULL);
	if (!pattern)
		return (-1);
	while (pattern[sep_size])
		sep_size++;
	sep_size++;
	sep = wildcard_find_sep(sep_size, str);
	if (!sep)
		return (exit_wildcard(pattern, NULL, -1));
	if (!ft_strlen(pattern[0]))
		if (check_pattern_sp(sep, cmp))
			ret = 1;
	if (check_pattern(wild_struct_init(sep, sep_size, pattern, cmp), 0, 0))
		ret = 1;
	return (exit_wildcard(pattern, sep, ret));
}

int	find_pattern(int idx, char *str, char *pattern)
{
	int	i;

	i = 0;
	while (str[idx] && pattern[i] && pattern[i] == str[idx])
	{
		i++;
		idx++;
	}
	if (pattern[i])
		return (0);
	return (1);
}

int	check_pattern(t_wild inf, int i, int idx)
{
	if (i > inf.sep_size)
		return (0);
	while (inf.str[idx] && inf.pattern[i] && i < inf.sep_size)
	{
		inf.wild = modified_twild(&inf, i);
		idx += inf.sep[i];
		if (!inf.wild && !find_pattern(idx, inf.str, inf.pattern[i]))
			return (0);
		else if (inf.wild)
		{
			while (inf.str[idx])
			{
				if (find_pattern(idx, inf.str, inf.pattern[i]))
					if (check_pattern(inf, i + 1,
							idx + ft_strlen(inf.pattern[i])))
						return (1);
				idx++;
			}
		}
		idx += ft_strlen(inf.pattern[i]);
		i++;
	}
	return (check_end_pattern(inf, i, idx));
}

int	check_end_pattern(t_wild inf, int i, int idx)
{
	if (i != inf.sep_size - 1)
		return (0);
	inf.wild = modified_twild(&inf, i);
	idx += inf.sep[i];
	if (idx > ft_strlen(inf.str))
		return (0);
	if (!inf.wild && inf.str[idx])
		return (0);
	return (1);
}

int	check_pattern_sp(int *sep, char *str)
{
	int	wild;

	wild = 0;
	if (sep[0] < 1)
	{
		wild = 1;
		sep[0] *= -1;
	}
	if (!wild && ft_strlen(str) != sep[0])
		return (0);
	if (wild && ft_strlen(str) < sep[0])
		return (0);
	return (1);
}
