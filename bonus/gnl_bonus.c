/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:40:49 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/25 12:01:49 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_lennew(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*read_fd(int fd, char *buff, char *str)
{
	int		i;
	char	*tmp;

	i = 1;
	buff[0] = 0;
	while (i > 0 && !ft_strchr(buff, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		if (i == 0)
		{
			free(buff);
			return (str);
		}
		buff[i] = 0;
		tmp = str;
		str = ft_strjoin_gnl(tmp, buff);
		free(tmp);
	}
	free(buff);
	return (str);
}

char	*get_rest(char *str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	temp = malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!temp)
		return (free(str), NULL);
	i++;
	j = 0;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*s;
	char		*line;
	char		*tmp;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	s = read_fd(fd, buff, s);
	if (!s)
		return (NULL);
	if (!*s)
		return (free(s), s = NULL);
	tmp = s;
	line = ft_substr(tmp, 0, ft_lennew(tmp) + 1);
	if (!line)
		return (free(line), line = NULL);
	s = get_rest(s);
	return (line);
}
