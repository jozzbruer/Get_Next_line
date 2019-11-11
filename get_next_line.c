/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquince <jquince@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:52:55 by jquince           #+#    #+#             */
/*   Updated: 2019/11/07 18:39:54 by jquince          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_line_reader(char **bar, char **str)
{
	char			*foo;
	int				i;

	i = 0;
	while ((*bar)[i] != '\n' && (*bar)[i] != '\0')
		i++;
	if ((*bar)[i] == '\n')
	{
		*str = ft_strsub(*bar, 0, i);
		foo = ft_strdup(&((*bar)[i + 1]));
		free(*bar);
		*bar = foo;
		if ((*bar)[0] == '\0')
			ft_strdel(bar);
	}
	else
	{
		*str = ft_strdup(*bar);
		ft_strdel(bar);
	}
	return (1);
}

int					ft_result(char **bar, char **str, int result, int fd)
{
	if (result < 0)
		return (-1);
	else if (result == 0 && bar[fd] == NULL)
		return (0);
	else
		return (ft_line_reader(&bar[fd], str));
}

int					get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	static char		*buffer_max[255];
	char			*temporary_line;
	int				result;

	if (fd < 0 || line == NULL)
		return (-1);
	else
	{
		while ((result = read(fd, buffer, BUFF_SIZE)) > 0)
		{
			buffer[result] = '\0';
			if (buffer_max[fd] == NULL)
				buffer_max[fd] = ft_strdup(buffer);
			else
			{
				temporary_line = ft_strjoin(buffer_max[fd], buffer);
				free(buffer_max[fd]);
				buffer_max[fd] = temporary_line;
			}
		}
	}
	return (ft_result(buffer_max, line, result, fd));
}
