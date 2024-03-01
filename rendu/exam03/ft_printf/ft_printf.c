/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: james <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 04:48:05 by james             #+#    #+#             */
/*   Updated: 2024/03/01 06:14:16 by james            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>

#define PTRNULL	"(nil)"
#define STRNULL	"(null)"
#define BUFFERSIZE 20

size_t	ft_strlen(char *s)
{
	char	*p;

	p = s;
	while (*s)
		s++;
	return (s - p);
}

size_t ft_case_c(int c)
{
	unsigned char	uc;
	
	uc = (unsigned char) c;
	return (write(1, &uc, 1));
}

size_t	ft_case_s(char *str)
{
	if (!str)
		return (write(1, STRNULL, ft_strlen(STRNULL)));
	return (write(1, str, ft_strlen(str)));
}

size_t	ft_putullnbr_base(size_t nl, char *base)
{
	size_t	len;
	size_t	i;
	char	s[BUFFERSIZE + 1];

	i = (size_t) BUFFERSIZE;
	s[i] = '\0';
	len = ft_strlen(base);
	if (!nl)
		s[--i] = base[0];
	while (nl && i--)
	{
		s[i] = base[(int)(nl % len)];
		nl /= len;
	}
	return (write(1, s + i, (size_t)(BUFFERSIZE - i)));

}


size_t	ft_case_p(void *p)
{
	size_t	count;

	count = 0;
	if (p == NULL)
		count += write(1, PTRNULL, ft_strlen(PTRNULL));
	else
	{
		count += write(1, "0x", 2);
		count += ft_putullnbr_base((size_t)p, "0123456789abcdef");
	}
	return (count);
}

size_t	ft_case_lx(unsigned int n)
{
	return (ft_putullnbr_base((size_t)n, "0123456789abcdef"));
}

size_t	ft_switch_case(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_case_c((int) va_arg(*ap, int)));
	if (c == 's')
		return (ft_case_s((char *) va_arg(*ap, char *)));
	if (c == 'd')
		return (ft_case_d((int) va_arg(*ap, int)));
	if (c == 'p')
		return (ft_case_p((void *) va_arg(*ap, void *)));
	if (c == 'x')
		return (ft_case_lx((unsigned int) va_arg(*ap, unsigned int));
	else
		return (-1);

}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	count;
	int		i;

	if (!format)
		return (-1);
	i = -1;
	count = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
			count += ft_switch_case(format[++i], &ap);
		else
			count += write(1, format + i, 1);
	}
	va_end(ap);
	return ((int)count);
}
