#include "minishell.h"

void	sighandler(int	signum)
{
	printf("caught signal : %d\n", signum);
	exit(EXIT_FAILURE);
}