/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:33:14 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	*ft_set_modifier(char c, ssize_t *width, ssize_t *precision);

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	size_t			pb;
	t_parameters	*params;

	pb = 0;
	params = NULL;
	if (!format)
		return (PRINTF_ERROR);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			params = (t_parameters *)ft_calloc(1, sizeof(t_parameters));
			format = ft_apply_params(params, (char *)format, ap);
			pb += ft_write_params(params);
			ft_free_params(params);
		}
		else
			pb += write(STDOUT_FD, &(*format), sizeof(char));
		format++;
	}
	va_end(ap);
	return (pb);
}

char	*ft_check_flags(char *format, t_flags *flags)
{
	while (ft_strchr(FLAGS, *format))
	{
		if (*format == '-')
			flags->has_minus = true;
		else if (*format == '+')
			flags->has_plus = true;
		else if (*format == ' ')
			flags->has_space = true;
		else if (*format == '0')
			flags->has_zero = true;
		else if (*format == '#')
			flags->has_hashtag = true;
		format++;
	}
	return (format);
}

char	*ft_check_mods(char *format, ssize_t *width, ssize_t *precision)
{
	char	*temp;
	size_t	index;
	ssize_t	*modifier;

	index = 0;
	temp = NULL;
	if (format[index] == '.')
	{
		*precision = 0;
		format++;
	}
	while (ft_strchr(DECIMALS, format[index]))
		index++;
	if (!index)
		return (format);
	temp = ft_substr(format, 0, index);
	modifier = ft_set_modifier(*(format - 1), width, precision);
	*modifier = ft_atoi(temp);
	if (modifier == precision)
		format += index;
	else
		format = ft_check_mods(format + index, width, precision);
	free(temp);
	return (format);
}

static ssize_t	*ft_set_modifier(char c, ssize_t *width, ssize_t *precision)
{
	if (c == '.')
		return (precision);
	else
		return (width);
}

char	*ft_apply_specifier(char specifier, va_list ap)
{
	char	*str;

	str = NULL;
	if (specifier == 's')
		str = ft_check_string(va_arg(ap, char *));
	else if (specifier == 'p')
		str = ft_ptoa(va_arg(ap, size_t));
	else if (specifier == 'o')
		str = ft_itoa_base(va_arg(ap, size_t), 8, OCTALS);
	else if (specifier == 'b')
		str = ft_itoa_base(va_arg(ap, size_t), 2, BINARIES);
	else if (ft_strchr("di", specifier))
		str = ft_itoa_base(va_arg(ap, int), 10, DECIMALS);
	else if (specifier == 'u')
		str = ft_itoa_base(va_arg(ap, unsigned int), 10, DECIMALS);
	else if (specifier == 'X')
		str = ft_itoa_hex(va_arg(ap, unsigned int), 16, UPPER_HEXAS);
	else if (specifier == 'x')
		str = ft_itoa_hex(va_arg(ap, unsigned int), 16, LOWER_HEXAS);
	else if (specifier == 'c')
		str = ft_ctoa(va_arg(ap, int));
	else if (specifier == '%')
		str = ft_ctoa(specifier);
	return (str);
}
