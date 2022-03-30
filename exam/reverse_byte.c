
int	reverse_byte(long long n)
{
	long long tmp;
	int		i;
	int		rem;

	tmp = 0;
	i = 1;
	rem = 1;
	while (n != 0)
	{
		rem = n % 2;
		n /= 2;
		tmp += rem * i;
		i *= 10;
	}
	return (tmp);
}

int main()
{
	long long i;
	int		res;

	i = 1010;
	res = reverse_byte(i);
	return (0);
}
