/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:41:19 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/06/17 10:49:51 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

char	**wildcard(char *str)
{
	char	**ret;
	char	**cmd;

	ret = NULL;
	cmd = ft_split(str, '/');
	if (!cmd)
		return (NULL);
	if (!cmd[0])
		return (NULL);
	if (str && str[0] == '/')
		ret = wild_recursive("/", ret, cmd, 0);
	else
		ret = wild_recursive(".", ret, cmd, 0);
	free_tab(cmd);
	ret = sort_tab(ret);
	return (ret);
}

char	**sort_tab(char **tab)
{
	int		i;
	int		j;
	char	s1[256];
	char	s2[256];
	char	*tmp;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[++j + 1])
		{
			if (comp(to_lower(tab[i], s1), to_lower(tab[j], s2)) < 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}
	return (tab);
}

char	**extract_pattern(char *str, char **ret)
{
	int		i;
	int		j;
	char	*to_add;

	i = 0;
	while (str && str[i])
	{
		while (str[i] && (str[i] == '*' || str[i] == '?'))
			i++;
		j = i;
		while (str[j] && !(str[j] == '*' || str[j] == '?'))
			j++;
		if (i == j)
			continue ;
		to_add = sub_string(str, i, j);
		ret = tdtab_push(ret, to_add);
		free(to_add);
		if (!ret)
			return (NULL);
		i = j;
	}
	if (!ret)
		return (tdtab_push(ret, ""));
	return (ret);
}

char	**wild_recursive(char *directory, char **ret, char **cmd, int layer)
{
	int		i;
	int		code;
	char	**list;
	DIR		*dirp;

	i = -1;
	code = 0;
	dirp = init_dir_code(directory, &code, layer, cmd);
	if (!dirp)
		return (ret);
	list = list_file(dirp, code);
	while (list && list[++i])
	{
		if (!wildcard_check(cmd[layer], list[i]))
			continue ;
		add_dir(list, i, directory);
		if (layer != tdtab_len(cmd) - 1)
			ret = wild_recursive(list[i], ret, cmd, layer + 1);
		else
			ret = tdtab_push(ret, list[i]);
	}
	closedir(dirp);
	free_tab(list);
	return (ret);
}

void	add_dir(char **list, int idx, char *dir)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	i = -1;
	len = ft_strlen(list[idx]) + ft_strlen(dir) + 1;
	if (ft_strlen(dir) == 1 && dir[0] == '.')
		return ;
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return ;
	while (dir[++i])
		new[i] = dir[i];
	if (comp("/", dir))
		new[i++] = '/';
	j = 0;
	while (list[idx][j])
		new[i++] = list[idx][j++];
	new[i] = 0;
	free(list[idx]);
	list[idx] = new;
}
