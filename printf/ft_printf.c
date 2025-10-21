#include "utils.h"

static int ft_putnbr_base(long long n, int base, char *base_str)
{
    int printed;

    printed = 0;
    if (n < 0)
    {
        printed += ft_putchar_fd('-', 1);
        n *= -1;
    }
    if (n / base != 0)
        printed += ft_putnbr_base((n / base), base, base_str);
    printed += ft_putchar_fd(base_str[n % base], 1);
    return (printed);
}

static int	ft_print_type(char c, va_list args)
{
    int size;
    char *base_str = "0123456789abcdef";

    size = 0;
	if (c == 'c')
		size = (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 's')
		size = (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'p')
		size = (ft_putnbr_base((long long)va_arg(args, void *), 16, base_str));
	else if (c == 'd' || c == 'i')
		size = (ft_putnbr_base((long long)va_arg(args, int), 10, base_str));
	else if (c == 'u')
		size = (ft_putnbr_base((long long)va_arg(args, unsigned int), 10, base_str));
	else if (c == 'x')
		size = (ft_putnbr_base((long long)va_arg(args, long long), 16, "0123456789ABCDEF"));
	else if (c == 'X')
		size = (ft_putnbr_base((long long)va_arg(args, long long), 16, "0123456789ABCDEF"));
	else if (c == '%')
		size = (ft_putchar_fd('%', 1));
    return (size);
}

int	ft_printf(const char *str, ...)
{
	int i;
	int size;
	va_list args;

	if (!str)
		return (-1);
	i = 0;
	size = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
        {
            i++;
            size += ft_print_type(str[i], args);
            i++;
        }
		else
			ft_putchar_fd(str[i], 1);
	}
	va_end(args);
	return (size + i);
}