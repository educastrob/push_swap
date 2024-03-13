/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:03:16 by edcastro          #+#    #+#             */
/*   Updated: 2024/03/13 04:58:36 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

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
