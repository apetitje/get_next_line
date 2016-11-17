/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 23:36:15 by apetitje          #+#    #+#             */
/*   Updated: 2016/11/06 12:53:44 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*zone;

	if (!(zone = malloc(size)))
		return (NULL);
	while (size > 0)
		((char *)zone)[--size] = 0;
	return (zone);
}
