#include <unistd.h>

void	print_byt(unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}


int main()
{
	unsigned char	c;

	c = 'b';
	print_byt(c);
	return (0);
}