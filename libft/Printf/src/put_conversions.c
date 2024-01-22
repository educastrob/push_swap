/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:02:36 by edcastro          #+#    #+#             */
/*   Updated: 2023/11/04 10:02:37 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

unsigned int	ft_putstr(char *str, int strlen)
{
	int	i;

	if (str == NULL && strlen >= 6)
		return (write(1, "(null)", 6));
	if (str == NULL)
		return (0);
	i = -1;
	while (++i < strlen)
		write(1, &str[i], 1);
	return (i);
}

static unsigned int	putnbr_recursion(size_t nbr, char *base,
	unsigned int baselen)
{
	int		chrs_written;
	char	c;

	chrs_written = 0;
	if (nbr >= baselen)
		chrs_written += putnbr_recursion(nbr / baselen, base, baselen);
	c = base[nbr % baselen];
	chrs_written += write(1, &c, 1);
	return (chrs_written);
}

unsigned int	ft_putnbr_base(ssize_t nbr, char *base)
{
	unsigned int	chrs_written;
	unsigned int	baselen;
	size_t			nb;

	baselen = ft_strlen(base);
	if (baselen < 2)
		return (0);
	chrs_written = 0;
	nb = (size_t)nbr;
	if (nbr < 0 && baselen == 10)
		nb = (size_t) - nbr;
	chrs_written += putnbr_recursion(nb, base, baselen);
	return (chrs_written);
}

int	put_padding(char c, int len)
{
	int	chars_written;

	chars_written = 0;
	while (len-- > 0)
		chars_written += write(1, &c, 1);
	return (chars_written);
}

int	put_sign_or_space(t_print *tab)
{
	int	chars_written;

	chars_written = 0;
	if (tab->neg)
		chars_written += write(1, "-", 1);
	else if (tab->sign)
		chars_written += write(1, "+", 1);
	else if (tab->space)
		chars_written += write(1, " ", 1);
	return (chars_written);
}
