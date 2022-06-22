#include "minishell.h"

void	sighandler(int	signum)
{
	if (signum == SIGINT)
		
	exit(EXIT_FAILURE);
}