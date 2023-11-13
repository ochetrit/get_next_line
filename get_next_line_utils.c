/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utilis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:29:27 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/13 16:29:27 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strchr(const char *str, int character)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != (unsigned char)character)
		i++;
	if (str[i] == (unsigned char)character)
		return (i);
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\n';
	i++;
	dest[i] = '\0';
	return (dest);
}
