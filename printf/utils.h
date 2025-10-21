#include <stdarg.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);
size_t		ft_putchar_fd(char c, int fd);
size_t		ft_putstr_fd(char *s, int fd);
int		ft_printf(const char *str, ...);