/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:28:30 by apetitje          #+#    #+#             */
/*   Updated: 2016/11/21 18:07:29 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# define BUFF_SIZE 1

typedef struct		s_lst
{
	int				fd;
	char			*stock;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(const int fd, char **line);

#endif
