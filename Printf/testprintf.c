#include "ft_printf.h"

int main()
{
	char	*str;
	char	c;
	int		nb;

	c = 'a';
	nb = 42;
	str = "allo la terre";
	printf("____Printf____\n");
	ft_printf("ceci est le char %c\n", c);
	printf("ceci est le char %c\n", c);
	ft_printf("ceci est le nb |%d|\n", nb);
	printf("ceci est le nb |%d|\n", nb);
	ft_printf("ceci est le str |%s|\n", str);
	printf("ceci est le str |%s|\n", str);
	ft_printf("ceci est le x |%x|\n", nb);
	printf("ceci est le x |%x|\n", nb);
	printf("___end___\n");
	return (0);
}
