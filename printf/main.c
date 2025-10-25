#include "utils.h"
#include <stdio.h>

int	main(void)
{
	int		a;
	int		b;
	char	c;
	char	*s;
	char	*null_str;
	void	*ptr;
	void	*null_ptr;

	a = 42;
	b = -42;
	unsigned int u = 4294967295U; // UINT_MAX
	c = 'A';
	s = "Hello, world!";
	null_str = NULL;
	ptr = &a;
	null_ptr = NULL;
	int ret_std, ret_ft;
	printf("\n================= %%c =================\n");
	ret_std = printf("printf   : |%c|\n", c);
	ret_ft = ft_printf("ft_printf: |%c|\n", c);
	printf("ret_printf=%d | ret_ft_printf=%d\n", ret_std, ret_ft);
	printf("\n================= %%s =================\n");
	ret_std = printf("printf   : |%s|\n", s);
	ret_ft = ft_printf("ft_printf: |%s|\n", s);
	printf("ret_printf=%d | ret_ft_printf=%d\n", ret_std, ret_ft);
	printf("----- NULL string -----\n");
	ret_std = printf("printf   : |%s|\n", null_str);
	ret_ft = ft_printf("ft_printf: |%s|\n", null_str);
	printf("ret_printf=%d | ret_ft_printf=%d\n", ret_std, ret_ft);
	printf("\n================= %%p =================\n");
	ret_std = printf("printf   : |%p|\n", ptr);
	ret_ft = ft_printf("ft_printf: |%p|\n", ptr);
	printf("ret_printf=%d | ret_ft_printf=%d\n", ret_std, ret_ft);
	printf("----- NULL pointer -----\n");
	ret_std = printf("printf   : |%p|\n", null_ptr);
	ret_ft = ft_printf("ft_printf: |%p|\n", null_ptr);
	printf("ret_printf=%d | ret_ft_printf=%d\n", ret_std, ret_ft);
	printf("\n================= %%d / %%i =================\n");
	ret_std = printf("printf   : |%d| |%i| |%d| |%i|\n", 0, 0, a, b);
	ret_ft = ft_printf("ft_printf: |%d| |%i| |%d| |%i|\n", 0, 0, a, b);
	printf("ret_printf=%d | ret_ft_printf=%d\n", ret_std, ret_ft);
	printf("----- INT_MIN / INT_MAX -----\n");
	ret_std = printf("printf   : |%ld| |%d|\n", -2147483648, 2147483647);
	ret_ft = ft_printf("ft_printf: |%d| |%d|\n", -2147483648, 2147483647);
	printf("ret_printf=%d | ret_ft_printf=%d\n", ret_std, ret_ft);
	printf("\n================= %%u =================\n");
	ret_std = printf("printf   : |%u| |%u|\n", 0, u);
	ret_ft = ft_printf("ft_printf: |%u| |%u|\n", 0, u);
	printf("ret_printf=%d | ret_ft_printf=%d\n", ret_std, ret_ft);
	printf("\n================= %%x / %%X =================\n");
	ret_std = printf("printf   : |%x| |%X|\n", a, a);
	ret_ft = ft_printf("ft_printf: |%x| |%X|\n", a, a);
	printf("ret_printf=%d | ret_ft_printf=%d\n", ret_std, ret_ft);
	printf("----- Edge hex values -----\n");
	ret_std = printf("printf   : |%x| |%X|\n", 0, u);
	ret_ft = ft_printf("ft_printf: |%x| |%X|\n", 0, u);
	printf("ret_printf=%d | ret_ft_printf=%d\n", ret_std, ret_ft);
	printf("\n================= %%%% =================\n");
	ret_std = printf("printf   : |%%|\n");
	ret_ft = ft_printf("ft_printf: |%%|\n");
	printf("ret_printf=%d | ret_ft_printf=%d\n", ret_std, ret_ft);
	printf("\n================= Mixed =================\n");
	ret_std = printf("printf   : |char=%c str=%s int=%d hex=%x ptr=%p %%|\n", c,
			s, a, a, ptr);
	ret_ft = ft_printf("ft_printf: |char=%c str=%s int=%d hex=%x ptr=%p %%|\n",
						c,
						s,
						a,
						a,
						ptr);
	printf("ret_printf=%d | ret_ft_printf=%d\n", ret_std, ret_ft);
	printf("\n================= '\\0' =================\n");
	ret_std = printf("printf   : |\\0| -> |%c|\n", '\0');
	ret_ft = ft_printf("ft_printf: |\\0| -> |%c|\n", '\0');
	printf("ret_printf=%d | ret_ft_printf=%d\n", ret_std, ret_ft);

    printf("\n+++++++++++++EVIL++++++++++++++++++\n");
     
	printf("\n========= %%c =========\n");
    ret_std = printf("printf   : |%c|\n", '\0');
    ret_ft  = ft_printf("ft_printf: |%c|\n", '\0');
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    ret_std = printf("printf   : |%c|\n", 128);
    ret_ft  = ft_printf("ft_printf: |%c|\n", 128);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    printf("\n========= %%s =========\n");
    char *test = NULL;
    ret_std = printf("printf   : |%s|\n", test);
    ret_ft  = ft_printf("ft_printf: |%s|\n", test);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    ret_std = printf("printf   : |%s|\n", "");
    ret_ft  = ft_printf("ft_printf: |%s|\n", "");
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    ret_std = printf("printf   : |%s|\n", "ab\0cd");
    ret_ft  = ft_printf("ft_printf: |%s|\n", "ab\0cd");
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    printf("\n========= %%p =========\n");
    ret_std = printf("printf   : |%p|\n", test);
    ret_ft  = ft_printf("ft_printf: |%p|\n", test);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    ret_std = printf("printf   : |%p|\n", (void *)0x7ffeefffffff);
    ret_ft  = ft_printf("ft_printf: |%p|\n", (void *)0x7ffeefffffff);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    printf("\n========= %%d / %%i =========\n");
    ret_std = printf("printf   : |%d|\n", 0);
    ret_ft  = ft_printf("ft_printf: |%d|\n", 0);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    ret_std = printf("printf   : |%d|\n", -42);
    ret_ft  = ft_printf("ft_printf: |%d|\n", -42);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    ret_std = printf("printf   : |%d|\n", 2147483647);
    ret_ft  = ft_printf("ft_printf: |%d|\n", 2147483647);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    ret_std = printf("printf   : |%ld|\n", -2147483648);
    ret_ft  = ft_printf("ft_printf: |%d|\n", -2147483648);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    printf("\n========= %%u =========\n");
    ret_std = printf("printf   : |%u|\n", 0);
    ret_ft  = ft_printf("ft_printf: |%u|\n", 0);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    ret_std = printf("printf   : |%u|\n", -1);
    ret_ft  = ft_printf("ft_printf: |%u|\n", -1);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    ret_std = printf("printf   : |%u|\n", 4294967295U);
    ret_ft  = ft_printf("ft_printf: |%u|\n", 4294967295U);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    printf("\n========= %%x / %%X =========\n");
    ret_std = printf("printf   : |%x|\n", 0);
    ret_ft  = ft_printf("ft_printf: |%x|\n", 0);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    ret_std = printf("printf   : |%x|\n", -1);
    ret_ft  = ft_printf("ft_printf: |%x|\n", -1);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    ret_std = printf("printf   : |%x|\n", 4294967295U);
    ret_ft  = ft_printf("ft_printf: |%x|\n", 4294967295U);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    ret_std = printf("printf   : |%X|\n", 48879);
    ret_ft  = ft_printf("ft_printf: |%X|\n", 48879);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    printf("\n========= %%%% =========\n");
    ret_std = printf("printf   : |%%|\n");
    ret_ft  = ft_printf("ft_printf: |%%|\n");
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    ret_std = printf("printf   : |%%%%|\n");
    ret_ft  = ft_printf("ft_printf: |%%%%|\n");
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    printf("\n========= MIXED =========\n");
    ret_std =   printf("printf   : |%c|%s|%p|%ld|%i|%u|%x|%X|%%|\n",'\0', test, test, -2147483648, 2147483647, -1, 0, 48879);
    ret_ft  = ft_printf("ft_printf: |%c|%s|%p|%d|%i|%u|%x|%X|%%|\n",'\0', test, test, -2147483648, 2147483647, -1, 0, 48879);
    printf("return printf=%d | ft_printf=%d\n", ret_std, ret_ft);

    printf("\n========= MORE =========\n");
    ret_std = printf("printf   : |%x| |%x|\n", -1, 255);
    ret_ft  = ft_printf("ft_printf: |%x| |%x|\n", -1, 255);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);

    ret_std = printf(NULL);
    ret_ft  = ft_printf(NULL);
    printf("return printf=%d | ft_printf=%d\n\n", ret_std, ret_ft);
    
	return (0);
}
