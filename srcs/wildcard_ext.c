/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:53:59 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/06/14 11:15:54 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

char	**list_file(DIR *dirp, int code)
{
	struct dirent	*entity;
	char			**ret;

	ret = NULL;
	while (1)
	{
		entity = readdir(dirp);
		if (!entity)
			break ;
		if (!code && entity->d_name[0] == '.')
			continue ;
		ret = tdtab_push(ret, entity->d_name);
		if (!ret)
			break ;
	}
	return (ret);
}

int	*wildcard_find_sep(int sep_size, char *str)
{
	int	i;
	int	idx;
	int	*ret;

	i = 0;
	idx = 0;
	ret = malloc(sizeof(int) * sep_size);
	if (!ret)
		return (NULL);
	if (str[idx] != '*' && str[idx] != '?')
		ret[i++] = INT_MIN;
	wildcard_find_sep_ext(str, ret, &idx, &i);
	if (str[idx - 1] != '?' && str[idx - 1] != '*')
		ret[i] = INT_MIN;
	return (ret);
}

void	wildcard_find_sep_ext(char *str, int *ret, int *idx, int *i)
{
	int	wild;

	while (str[*idx])
	{
		if (!(str[*idx] != '?' && str[*idx] != '*'))
		{
			ret[*i] = 0;
			wild = 1;
			while (str[*idx] && (str[*idx] == '*' || str[*idx] == '?'))
			{
				if (str[*idx] == '*')
					wild = -1;
				else
					ret[*i]++;
				(*idx)++;
			}
			if ((ret[*i] == 0 && wild == 1))
				ret[(*i)++] = INT_MIN;
			else
				ret[(*i)++] *= wild;
		}
		else
			(*idx)++;
	}
}

int	exit_wildcard(char **pattern, int *sep, int ret)
{
	if (pattern)
		free_tab(pattern);
	if (sep)
		free(sep);
	return (ret);
}

DIR	*init_dir_code(char *directory, int *code, int layer, char **cmd)
{
	DIR	*dirp;

	dirp = opendir(directory);
	if (cmd && cmd[layer] && cmd[layer][0] == '.')
		*code = 1;
	return (dirp);
}
