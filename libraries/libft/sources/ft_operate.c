/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:33:10 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_operate(int nbr1, int nbr2, char operator)
{
	if (operator == MIN)
	{
		if (nbr1 <= nbr2)
			return (nbr1);
		return (nbr2);
	}
	if (nbr1 >= nbr2)
		return (nbr1);
	return (nbr2);
}
