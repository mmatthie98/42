#include "get_next_line.h"

int main()
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("premiere ligne de GNL : %s", get_next_line(fd));
	printf("deuxieme ligne de GNL : %s", get_next_line(fd));
	printf("3eme ligne de GNL : %s", get_next_line(fd));
	printf("\n");
	return (0);
}
