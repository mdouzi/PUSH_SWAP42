/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:15:00 by mdouzi            #+#    #+#             */
/*   Updated: 2023/01/25 22:04:33 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (char *)malloc((count * size));
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, (size * count));
	return (ptr);
}

char	*ft_get_line(char *save)
{
	char	*line;
	int		i;

	if (!save[0])
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] && save[i] == '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] && save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	return (line);
}

char	*update_save(char *save)
{
	char	*res;
	int		i;
	int		j;

	if (!save[0])
	{
		free(save);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] && save[i] == '\n')
		i++;
	res = ft_calloc(sizeof(char), (ft_strlen(save) - i + 1));
	if (!res)
		return (NULL);
	while (save[i])
	{
		res[j++] = save[i++];
	}
	free(save);
	return (res);
}

char	*get_helper(char *save, int fd, char *buffer)
{
	int	rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(save);
			save = 0;
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		save = ft_strjoin(save, buffer);
		if (ft_strchr(save, '\n'))
			break ;
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	save = get_helper(save, fd, buffer);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = update_save(save);
	return (line);
}
