/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:56:44 by pviegas           #+#    #+#             */
/*   Updated: 2023/04/14 13:17:46 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	words;
	int		in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (in_word && *s == c)
		{
			in_word = 0;
		}
		else if (in_word == 0 && *s != c)
		{
			in_word = 1;
			words++;
		}
		s++;
	}
	return (words);
}

static char	*next_word(const char **s, char c)
{
	const char	*start;
	char		*word;

	while (**s && **s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	word = ft_substr(start, 0, *s - start);
	if (!word)
		return (NULL);
	if (**s)
		(*s)++;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		n_words;
	char		**words;
	const char	*p;

	p = s;
	n_words = count_words(s, c);
	words = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!s || !words)
		return (NULL);
	i = 0;
	while (i < n_words)
	{
		words[i] = next_word(&p, c);
		if (!words[i])
		{
			while (i--)
				free(words[i]);
			free(words);
			return (NULL);
		}
		i++;
	}
	words[i] = NULL;
	return (words);
}
