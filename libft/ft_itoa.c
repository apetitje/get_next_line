/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:31:15 by apetitje          #+#    #+#             */
/*   Updated: 2016/11/08 20:58:17 by apetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_find_range(int n, int *is_neg, unsigned int absolute_nb,
		unsigned int *nb_cpy)
{
	int				range;

	range = 0;
	if (n < 0)
	{
		*is_neg = 1;
		absolute_nb = (unsigned int)-n;
	}
	else
		absolute_nb = (unsigned int)n;
	*nb_cpy = absolute_nb;
	while (absolute_nb >= 10)
	{
		absolute_nb = absolute_nb / 10;
		range++;
	}
	range++;
	return (range);
}

char		*ft_itoa(int n)
{
	unsigned int	absolute_nb;
	char			*number;
	int				is_neg;
	unsigned int	nb_cpy;
	int				range;

	absolute_nb = 0;
	is_neg = 0;
	range = ft_find_range(n, &is_neg, absolute_nb, &nb_cpy);
	if (!(number = (char *)malloc(sizeof(char) * (range + is_neg + 1))))
		return (NULL);
	number[range + is_neg] = '\0';
	range--;
	while (nb_cpy >= 10)
	{
		number[range + is_neg] = nb_cpy % 10 + 48;
		nb_cpy = nb_cpy / 10;
		range--;
	}
	number[range + is_neg] = nb_cpy + 48;
	if (is_neg == 1)
		number[0] = '-';
	return (number);
}
