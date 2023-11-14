/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:29:13 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/13 16:26:45 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
		static char		*temp;
		char			*str;
		int						size;
		int						i;

		if (ft_strchr(temp, '\n') == -1)
			temp = ft_initialise(temp, fd);
		size = ft_strchr(temp, '\n');
		if (size == -1)
			return (temp);
		str = (char *)malloc((size + 2) * sizeof(char));		// +2 parce que on inclut le \n
		i = -1;
		while (++i <= size)
			str[i] = temp[i];
		str[i] = '\0';
		temp = ft_replace_temp(temp, size);
}

char	*ft_initialise(char *temp, int fd)
{
	char	stock[BUFFER_SIZE];
	char	*new;
	int			n_oct;
	int			i;

	n_oct = read(fd, stock, BUFFER_SIZE);
	if (n_oct < 1)
		return (temp);
	if (!temp)
	{
		new = (char *)malloc((n_oct + 1) * sizeof(char));
		i = -1;
		while (++i < n_oct)
			new[i] = stock[i];
		new[i] = '\0';
	}
	else
		new = ft_extend_temp(temp, stock, n_oct);
	if (ft_strchr(new, '\n') == -1)
		new = ft_initialise(new, fd);
	return (new);
}

char 	*ft_extend_temp(char *temp, char stock[BUFFER_SIZE], int n_oct)
{
	char	*new;
	unsigned int i;
	unsigned int j;

	new = (char *)malloc((ft_strlen(temp) + n_oct + 1) * sizeof(char));
	i = 0;
	while (temp[i])
	{
		new[i] = temp[i];
		i++;
	}
	j = 0;
	while (j < n_oct)
	{
		new[i] = stock[j];
		i++;
		j++;
	}
	new[i] = '\0';
	free(temp);
	return (new);
}

char	*ft_replace_temp(char *temp, int i)			//TRES IMPORTANT POUR DEMAIN, PRENDRE LE CAS OU IL N Y A RIEN APRES LE DERNIER \n
{
	char	*new;
	unsigned int	len;
	unsigned int	j;

	len = ft_strlen(temp);
	new = (char *)malloc((len - i + 1) * sizeof(char));
	j = 0;
	while (i < len)
	{
		new[j] = temp[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(temp);
	return (new);
}