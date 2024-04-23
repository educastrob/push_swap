/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:34:47 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_manage_flags(t_parameters *params, ssize_t *conv_len,
				long *index, size_t *pb);

size_t	ft_write_params(t_parameters *params)
{
	long	index;
	size_t	pb;
	ssize_t	conv_len;

	pb = 0;
	index = 0;
	if (params->specifier == '%')
		return (write(STDOUT_FD, params->converted, sizeof(char)));
	if (params->flags->has_hashtag && *(params->converted) != '0')
		index += 2;
	if (params->specifier == 'c' && !*(params->converted))
		conv_len = sizeof(char);
	else
		conv_len = ft_strlen(params->converted);
	ft_manage_flags(params, &conv_len, &index, &pb);
	return (pb);
}

static void	ft_manage_flags(t_parameters *params, ssize_t *conv_len,
long *index, size_t *pb)
{
	if (params->flags->has_minus)
	{
		ft_apply_prefixes(params, pb);
		ft_apply_precision(params, conv_len, index, pb);
		ft_apply_conversion(params, conv_len, pb);
		ft_apply_width(params, conv_len, index, pb);
	}
	else
	{
		ft_apply_zero_flag(params, conv_len, index, pb);
		*(params->width) = ft_apply_width(params, conv_len, index, pb);
		ft_apply_precision(params, conv_len, index, pb);
		ft_apply_prefixes(params, pb);
		ft_apply_conversion(params, conv_len, pb);
	}
}
