/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:03:20 by edcastro          #+#    #+#             */
/*   Updated: 2024/03/13 04:58:31 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_handle_error(const char *message)
{
	if (errno)
		perror(message);
	else
		write(STDERR_FILENO, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}
