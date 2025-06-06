/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:54:23 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/31 18:19:45 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*next_character(const char *str, char c)
{
	char	*pt_return;

	if (*(str - 1) == 39)
	{
		pt_return = ft_strchr(str, 39);
		if (!pt_return || !*pt_return)
			return (pt_return);
	}
	else
		pt_return = ft_strchr(str, c);
	return (pt_return);
}

static unsigned int	ft_splits_number(const char *to_split, char split_character)
{
	unsigned int	splits;

	splits = 0;
	while (*to_split)
	{
		while (*to_split && *to_split == split_character)
			to_split++;
		if (!*to_split)
			break ;
		splits++;
		while (*to_split && *to_split != split_character)
			to_split++;
	}
	return (splits);
}

static char	**ft_split_word(char **split, const char *to_split, char c)
{
	char	*pt_aux;
	char	*splitted;
	char	**pt_split;

	pt_split = split;
	while (*to_split)
	{
		while (*to_split && (*to_split == c || *to_split == 39))
			to_split++;
		if (!*to_split)
			break ;
		pt_aux = next_character(to_split, c);
		if (!pt_aux)
			pt_aux = ft_strchr(to_split, '\0');
		splitted = ft_calloc(sizeof(char), pt_aux - to_split + 1);
		if (!splitted)
			return (NULL);
		ft_memcpy(splitted, to_split, pt_aux - to_split);
		*split++ = splitted;
		to_split = pt_aux;
	}
	return (pt_split);
}

//function to split the string s to different string given the character c
char	**ft_split_pipex(char const *s, char c)
{
	char			**pt_return;
	unsigned int	splits;

	if (!s)
		return (NULL);
	splits = ft_splits_number(s, c);
	pt_return = ft_calloc(sizeof(char *), splits + 1);
	if (!pt_return)
		return (NULL);
	if (!ft_split_word(pt_return, s, c))
	{
		free_memory(pt_return);
		return (NULL);
	}
	return (pt_return);
}
