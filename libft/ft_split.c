/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:28:17 by dmitrypopov       #+#    #+#             */
/*   Updated: 2024/09/28 18:15:10 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(const char *s, char sep)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == sep)
			i++;
		if (s[i] && s[i] != sep)
		{
			words++;
			while (s[i] && s[i] != sep)
				i++;
		}
	}
	return (words);
}

char	*ft_extract_word(const char *s, size_t start, size_t len)
{
	return (ft_substr(s, start, len));
}

void	ft_free_split(char **result)
{
	size_t	i;

	i = 0;
	if (!result)
		return ;
	while (result[i])
	{
		free(result[i]);
		result[i] = NULL;
		i++;
	}
	free(result);
}

char	**ft_fill_result(char **result, const char *s, char sep)
{
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != sep && s[i] != '\0' && start < 0)
			start = i;
		else if ((s[i] == sep || s[i] == '\0') && start >= 0)
		{
			result[j] = ft_extract_word(s, start, i - start);
			if (!result[j])
			{
				result[j] = NULL;
				return (NULL);
			}
			j++;
			start = -1;
		}
		i++;
	}
	return (result[j] = NULL, result);
}

char	**ft_split(char const *s, char sep)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc((ft_countwords(s, sep) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!ft_fill_result(result, s, sep))
	{
		ft_free_split(result);
		return (NULL);
	}
	return (result);
}
