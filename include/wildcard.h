/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:39:27 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/06/17 10:51:41 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_H
# define WILDCARD_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <dirent.h>
# include <limits.h>

/* =========== struct =========== */
typedef struct s_wild_inf
{
	int		*sep;
	int		sep_size;
	char	**pattern;
	char	*str;
	int		wild;
}	t_wild;

/* ========== wildcard ========== */
char	**wildcard(char *str);
char	**extract_pattern(char *str, char **ret);
char	**wild_recursive(char *directory, char **ret, char **cmd, int layer);
void	add_dir(char **list, int idx, char *dir);
char	**sort_tab(char **tab);

/* ======== wildcard_ext ======== */
char	**list_file(DIR *dirp, int code);
int		*wildcard_find_sep(int sep_size, char *str);
void	wildcard_find_sep_ext(char *str, int *ret, int *idx, int *i);
int		exit_wildcard(char **pattern, int *sep, int ret);
DIR		*init_dir_code(char *directory, int *code, int layer, char **cmd);

/* ======== wildcard_utils ======== */
void	tab_init(char *s1, char *s2);
int		tdtab_len(char **tab);
char	*sub_string(char *str, int start, int end);
int		modified_twild(t_wild *inf, int i);
int		comp(const char *s1, const char *s2);

/* ======== wildcard_check ======== */
int		wildcard_check(char *str, char *cmp);
int		find_pattern(int idx, char *str, char *pattern);
int		check_pattern(t_wild *inf, int i, int idx);
int		check_end_pattern(t_wild *inf, int i, int idx);
int		check_pattern_sp(int *sep, char *str);

/* ============ utils ============= */
int		ft_strlen(char *str);
void	*free_tab(char **tab);
char	*ft_strdup(const char *s);
char	**tdtab_push(char **tab, char *to_add);
char	*to_lower(char *str, char *ret);

char	**ft_split(char const *s, char c);

#endif
