/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:04:02 by pviegas           #+#    #+#             */
/*   Updated: 2023/04/13 13:04:02 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (str1[i] == str2[i]) && (str1[i] != '\0')
		&& (str2[i] != '\0'))
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
