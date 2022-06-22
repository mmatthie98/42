#include "minishell.h"

void	sighandler(int	signum)
{
	struct sigaction sa;
	//sa.sa_handler = &sighandler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	if (signum == SIGINT)
	exit(EXIT_FAILURE);
}
