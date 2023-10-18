/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:45:19 by pviegas           #+#    #+#             */
/*   Updated: 2023/04/14 10:45:19 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	s_len = s_len - start;
	if (s_len > len)
		s_len = len;
	substr = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, s_len);
	substr[s_len] = '\0';
	return (substr);
}
