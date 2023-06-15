/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:06:28 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/06/15 23:11:49 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

int	main(int ac, char **av)
{
	char	**ret;

	if (ac != 2)
	{
		if (ac < 2)
			printf("error: too few arguments\n");
		if (ac > 2)
			printf("error: too many arguments\n");
		return (1);
	}
	ret = wildcard(av[1]);
	if (!ret)
	{
		printf("%s\n", av[1]);
		return (0);
	}
	for (int i = 0; ret[i]; i++)
		printf("%s\n", ret[i]);
	free_tab(ret);
	return (0);
}
