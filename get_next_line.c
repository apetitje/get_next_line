/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:28:22 by apetitje          #+#    #+#             */
/*   Updated: 2016/11/14 12:31:34 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_line_len(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] == '\n')
		i++;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		ft_is_over(char	**tmp, char **line)
{
	int		i;

	i = 0;
	if (**tmp)
	{
		i = ft_line_len(*tmp);
		*line = ft_strndup(*tmp, i);
		if ((*tmp)[i] == '\n' || *(tmp)[i] == '\0')
		{
			while ((*tmp)[i] == '\n')
					i++;
			*tmp = &((*tmp)[i]);
// regler pb de fuite memoire.
			return (1);
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*tmp = 0;
	int 			i;
	int				i_last;
	char			buffer[BUFF_SIZE + 1];
	int				ret;

	ret = 0;
	i = 0;
	if (BUFF_SIZE < 1 || !fd || fd < 0)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		i_last = i;
		buffer[ret] = '\0';
		i = ft_line_len(buffer);
		if (!*line)
		{
			if (tmp)
			{
				*line = ft_strdup(tmp);
				i = ft_strlen(tmp) + i;
				*line = (char *)ft_realloc(*line, i);
				*line = ft_strncat(*line, buffer, i);
			}
			else
				*line = ft_strndup(buffer, i);
		}
		else
		{
			*line = (char *)ft_realloc(*line, i + i_last);
			*line = ft_strncat(*line, buffer, i);

		}
		if (buffer[i] == '\n' || buffer[i] == '\0')
		{
			while (buffer[i] == '\n')
				i++;
			tmp = ft_strdup(&(buffer[i]));
			return (1);
		}
	}
	if (!ret)
	{
		if (ft_is_over(&tmp, line))
			return (1);
	}
	return (0);
}

//si aucune info il faut renvoyer une ligne avec '\0'
//penser a free tmp
