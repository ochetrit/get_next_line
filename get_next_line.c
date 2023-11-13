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
	char		*str;
	char static	*temp;
	int			count;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	temp = build_temp(fd, BUFFER_SIZE, temp);
	count = ft_strchr(temp, '\n');
	if (!count)
	{
		str = end_of_file(temp);
		temp = NULL;
		return (str);
	}
	str = (char *)malloc((count + 2) * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, temp);
	temp = last_temp(temp);
	return (str);
}

char	*build_temp(int fd, int n_oct, char *temp)
{
	char	stock[BUFFER_SIZE];

	while ((!ft_strchr(temp, '\n')) && n_oct == BUFFER_SIZE)
	{
		n_oct = read(fd, stock, BUFFER_SIZE);
		if (n_oct < 1)
			return (temp);
		temp = ft_extend_temp(temp, stock, n_oct);
		if (!temp)
			return (NULL);
	}
	return (temp);
}	

char	*last_temp(char *temp)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	i = ft_strchr(temp, '\n') + 1;
	if (!i)
	{
		free(temp);
		return (NULL);
	}
	j = 0;
	new = malloc((ft_strlen(temp) - i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (temp[i])
	{
		new[j] = temp[i];
		j++;
		i++;
	}
	new[j] = '\0';
	free(temp);
	return (new);
}

char	*ft_extend_temp(char *temp, char stock[BUFFER_SIZE], int n_oct)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	new = (char *)malloc((ft_strlen(temp) + n_oct + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new[ft_strlen(temp) + n_oct] = '\0';
	i = 0;
	while (i < ft_strlen(temp))
	{
		new[i] = temp[i];
		i++;
	}
	j = 0;
	while (j < (unsigned int)n_oct)
	{
		new[i] = stock[j];
		i++;
		j++;
	}
	free(temp);
	return (new);
}

char	*end_of_file(char *temp)
{
	char			*str;
	unsigned int	i;

	i = ft_strlen(temp);
	if (!i)
		return (NULL);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (temp[i])
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	temp = NULL;
	free(temp);
	return (str);
}

/* int main(int argc, char **argv)
{
	(void) argv;
	if (argc == 2)
	{
		int fd = open("florian.txt", O_RDONLY);
		char *str = "yo";
		int i = 0;
		while (str)
		{
			str = get_next_line(fd);
			printf("%s", str);
			i++;
		}
		printf("\n%d", i);
	}
	else
	{
		int fd = 0;
		char *str = "yo";
		while (str)
		{
			str = get_next_line(fd);
			printf("%s", str);
		}
	}
}
 */