#include <unistd.h>

void	print_byt(unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			write(1, "0", 1);
		else
			write(1, "1", 1);
		i--;
	}
}

/*unsigned char	reverse_bits(unsigned char octet)
{
	int i;
	unsigned char result;

	i = 8;
	result = 0;
	while (i > 0)
	{
		result =  result * 2 + (octet % 2);
		//result *= 2 + (octet % 2);
		octet /= 2;
		i--;
	}
	return (result);
}*/

int main()
{
	unsigned char	i;
//	unsigned char	res;

	i = 99;
//	res = 0;
	print_byt(i);
	write(1, "\n", 1);
//	res = reverse_bits(i);
//	print_byt(res);
//	write(1, "\n", 1);
	return (0);

}
